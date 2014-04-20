<?php
/**
 * @file 
 * Migrate module integration for the Arctic DEIMS.
 *
 *| vid | name                       |
 *|   1 | Arctic Bibliographic terms |
 *|   2 | LTER Keywords              |
 *|   3 | Species                    |
 *|   4 | Projects                   |
 *|   5 | Image Galleries            |
 *|   6 | Arctic LTER keyword terms  |  <--- this one ??
 *
 *| vid | type             |
 *+-----+------------------+
 *|   1 | biblio           |
 *|   2 | data_set         |
 *|   3 | data_set         |
 *|   4 | biblio, data_set, news , page  , research_project, research_site     
 *|   5 | image      
 *|   6 | data set  
 *   
 *  Data set should have at least 4 term references: 
 *  LTER keywords is built-in on 'deims_d6_migration'
 *  but all others are new (Species, Projects, Arctic LTER..)
 *  in addition, data set comes with core areas, which seems
 *  unused by ARC.
 */
/**
 * Implements hook_migrate_api().
 */
function arctic_migrate_api() {
  $info = array(
    'api' => 2,
    'migrations' => array(
      'ArcticContentBlog' => array(
        'class_name' => 'ArcticContentBlogMigration',
      ),
//      'ArcticTaxonomyARCVocabulary' => array(
//        'class_name' => 'DrupalTerm6Migration',
//        'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
//        'source_connection' => 'drupal6',
//        'source_version' => 6,
//        'source_vocabulary' => '6',
//        'destination_vocabulary' => 'arc_lter_vocabulary',
//      ),

// I doubt this will really override the default DEIMS
// migration, that's why im commenting it out, and recommeding we change
// the value of the "source_vocabulary" in deims_d6_migration.migrate.inc
// from "6" to "2", which is the correct value here.

/*    'ArcticTaxonomyLTERVocabulary' => array(
 *       'class_name' => 'DrupalTerm6Migration',
 *       'description' => "Taxonomy migration for the 'Data Sets LTER Vocabulary' vocabulary.",
 *       'source_connection' => 'drupal6',
 *       'source_version' => 6,
 *       'source_vocabulary' => '2',
 *       'destination_vocabulary' => 'lter_controlled_vocabulary',
 *    ),
*/
      'ArcticTaxonomySpeciesVocabulary' => array(
         'class_name' => 'DrupalTerm6Migration',
         'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
         'source_connection' => 'drupal6',
         'source_version' => 6,
         'source_vocabulary' => '3',
         'destination_vocabulary' => 'taxa',
      ),
      'ArcticTaxonomyProjectVocabulary' => array(
         'class_name' => 'DrupalTerm6Migration',
         'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
         'source_connection' => 'drupal6',
         'source_version' => 6,
         'source_vocabulary' => '4',
         'destination_vocabulary' => 'section',
      ),
    ),
  );
  foreach ($info['migrations'] as &$migration) {
    $migration['group_name'] = DEIMS_D6_MIGRATION_GROUP;
  }
  return $info;
}
/**
 * Implements hook_deims_migration_overrides().
 */
function arctic_deims_migration_overrides() {
  return array(
    'DeimsContentDataSet' => array('class_name' => 'ArcticContentDataSetMigration'),
    'DeimsContentPerson' => array('class_name' => 'ArcticContentPersonMigration'),
    'DeimsContentOrganization' => array('class_name' => 'ArcticContentOrganizationMigration'),
  );
}
