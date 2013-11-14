<?php

/**
 * @file
 * Definition of ArcticContentDataSetMigration.
 */

class ArcticContentDataSetMigration extends DeimsContentDataSetMigration {

   public function __construct(array $arguments) {

   parent::__construct($arguments);

// provided we: 
//  1) remove the 'ArcticTaxonomyLTERVocabulary' from arctic.migrate.inc
//  2) we change the source VID from the deims_d6_migration.migrate.inc from 6 to 2
// then, this will work

    $this->addFieldMapping('field_keywords', '2')
      ->sourceMigration('DeimsTaxonomyLTERControlled');
    $this->addFieldMapping('field_keywords:source_type')
      ->defaultValue('tid');

// provided you create a "field" of type "Term Reference" with
// machine name "field_dataset_project_keywords", then the next
// code will tie the terms well.

    $this->addFieldMapping('field_dataset_project_keywords', '4')
      ->sourceMigration('ArcticTaxonomyProjectVocabulary');
    $this->addFieldMapping('field_keywords:source_type')
      ->defaultValue('tid');

  }
//
// likewise for vocabularies "Species".
// 1) create the vocabulary in D7 (use arctic.install, this may be done..
// 2) migrate the vocabulary (this was done in arctic.migrate.inc)
// 3) create a Term Reference type field for "species" in content type
//    data set, and then use a code chunk like the one above this.

}
