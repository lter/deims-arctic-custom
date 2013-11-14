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
            'ArcticTaxonomyARCVocabulary' => array(
                'class_name' => 'DrupalTerm6Migration',
                'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
                'source_connection' => 'drupal6',
                'source_version' => 6,
                'source_vocabulary' => '6',
                'destination_vocabulary' => 'arctic_lter_vocabulary',
                'group' => DEIMS_D6_MIGRATION_GROUP,
            ),

// Im not sure this will really overwrite the default lter keywords vocab
// migration, that's why im commenting it out, and recommeding we change
// the value of the "source_vocabulary" in deims_d6_migration.migrate.inc
// from "6" to "2", which is the correct value here.

/*	    'ArcticTaxonomyLTERVocabulary' => array(
 *               'class_name' => 'DrupalTerm6Migration',
 *               'description' => "Taxonomy migration for the 'Data Sets LTER Vocabulary' vocabulary.",
 *               'source_connection' => 'drupal6',
 *               'source_version' => 6,
 *               'source_vocabulary' => '2',
 *               'destination_vocabulary' => 'lter_controlled_vocabulary',
 *               'group' => DEIMS_D6_MIGRATION_GROUP,
 *           ),
*/
	    'ArcticTaxonomySpeciesVocabulary' => array(
                'class_name' => 'DrupalTerm6Migration',
                'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
                'source_connection' => 'drupal6',
                'source_version' => 6,
                'source_vocabulary' => '3',
                'destination_vocabulary' => 'taxa',
                'group' => DEIMS_D6_MIGRATION_GROUP,
            ),
	'ArcticTaxonomyProjectVocabulary' => array(
                'class_name' => 'DrupalTerm6Migration',
                'description' => "Taxonomy migration for the 'Data Sets Arctic Vocabulary' vocabulary.",
                'source_connection' => 'drupal6',
                'source_version' => 6,
                'source_vocabulary' => '4',
                'destination_vocabulary' => 'section',
                'group' => DEIMS_D6_MIGRATION_GROUP,
            ),
        ),
    );
}
/**
 * Implements hook_deims_migration_overrides().
 */
function arctic_deims_migration_overrides() {
    return array(
        'DeimsContentDataSet' => array('class_name' => 'ArcticContentDataSetMigration'),
//        'DeimsContentPerson' => array('class_name' => 'ArcticContentPersonMigration'),
        'DeimsContentOrganization' => array('class_name' => 'ArcticContentOrganizationMigration'),
    );
}
