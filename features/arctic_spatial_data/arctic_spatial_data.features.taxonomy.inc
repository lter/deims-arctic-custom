<?php
/**
 * @file
 * sevilleta_spatial_data.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sevilleta_spatial_data_taxonomy_default_vocabularies() {
  return array(
    'spatial_data' => array(
      'name' => 'Spatial Data',
      'machine_name' => 'spatial_data',
      'description' => 'Categories of spatial data.  ',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
