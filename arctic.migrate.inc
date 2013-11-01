<?php
/**
 * @file
 * Migrate module integration for the Arctic DEIMS.
 */
/**
 * Implements hook_migrate_api().
 */
function arctic_migrate_api() {
    return array(
        'api' => 2,
        'migrations' => array(
//            'ArcticTaxonomyDataSetsVocabularyV' => array(
//                'class_name' => 'DrupalTerm6Migration',
//                'description' => "Taxonomy migration for the 'Data Sets Vocabulary V' vocabulary.",
//                'source_connection' => 'drupal6',
//                'source_version' => 6,
//                'source_vocabulary' => '5',
//                'destination_vocabulary' => 'datasets_vocabulary_v',
//                'group' => DEIMS_D6_MIGRATION_GROUP,
            ),
        ),
    );
}
/**
 * Implements hook_deims_migration_overrides().
 */
function arctic_deims_migration_overrides() {
    return array(
//        'DeimsContentDataSet' => array('class_name' => 'ArcticContentDataSetMigration'),
//        'DeimsContentPerson' => array('class_name' => 'ArcticContentPersonMigration'),
        'DeimsContentOrganization' => array('class_name' => 'ArcticContentOrganizationMigration'),
    );
}
