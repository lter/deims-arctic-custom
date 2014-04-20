<?php
/**
 * @file
 * Definition of ArcticContentPersonMigration.
 */

class ArcticContentPersonMigration extends DeimsContentPersonMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // field_person_pubs and two other do not exist
    $this->removeFieldMapping(NULL, 'field_person_pubs');
    $this->removeFieldMapping(NULL, 'field_person_fullname');
    $this->removeFieldMapping(NULL, 'field_person_list');

    $this->addUnmigratedSources(array(
      'revision',
      'log',
      'revision_uid',
      'field_person_photo:list',
      'field_person_photo_data',
      'upload',
      'upload:description',
      'upload:list',
      'upload:weight',
    ));
   
   $this->addUnmigratedDestinations(array(
     'field_associated_biblio_author',
     'field_list_in_directory',
     'field_person_status:language',
     'field_images:language',	
//     'field_images:destination_dir',	
//     'field_images:destination_file',
//     'field_images:file_replace',
//     'field_images:source_dir',
//     'field_images:urlencode',
     'field_images:alt',
     'field_images:title',	
     'field_person_reu_type',
     'field_person_reu_year',
     'field_person_reu_year:timezone',
     'field_person_reu_year:rrule',
     'field_person_reu_year:to',
     'field_person_biography',
     'field_person_biography:language',
   ));

    $this->addFieldMapping('field_person_status','field_person_status');
    $this->addFieldMapping('field_images','field_person_photo')
      ->sourceMigration('DeimsFile');
    $this->addFieldMapping('field_images:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_images:preserve_files')->defaultValue(TRUE);

    $this->addFieldMapping('field_url','field_person_web_page');
    $this->addFieldMapping('field_url:title','field_person_web_page:title');
    $this->addFieldMapping('field_url:attributes','field_person_web_page:attributes');

  }

  public function prepareRow($row) {
    // Fix empty email values used on Arc.
    switch ($row->field_person_email) {
      case 'unknown@ualaska.edu':
      case 'none@ualaska.edu':
        $row->field_person_email = NULL;
    }

    // Fix country values used on Arc.
    switch ($row->field_person_country) {
      case 'Dublin':
        $row->field_person_city = 'Dublin';
        $row->field_person_country = 'Ireland';
        break;
      case 'Cumbria':
        $row->field_person_state = 'Cumbria';
        $row->field_person_country = 'United Kingdom';
        break;
    }

    parent::prepareRow($row);
  }

  public function getOrganization($node, $row) {
    $field_values = array();

    // Search for an already migrated organization entity with the same title
    // and link value.
    if (!empty($row->{'field_person_organization:title'})) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'organization');
      $query->propertyCondition('title', $row->{'field_person_organization:title'});
      $results = $query->execute();
      if (!empty($results['node'])) {
        $field_values[] = array('target_id' => reset($results['node'])->nid);
      }
    }

    return $field_values;
  }
}
