deims-arctic-custom
===================

Customizations for the migration and settings of the Arctic LTER DEIMS

*Note* when you install DEIMS, do not enable the Deims D6 migration 
module, let's do that later -- in the step of optional features, skip
the first checkbox.

Place these files under a folder named (for example) arctic, which is suggested
you place under sites/default/modules in your DEIMS install.

Before you enable the new module,

There are things you need to do before you use the migration:

The default DEIMS D7 would have created 5 vocabularies for you, including the
LTER Keywords and the Core Areas. Furthermore, the assumption is that
the Core Areas are in "vid=1" in the source vocabulary, and the 
LTER Keywords are in the "vid=9" vocabulary.  This is only true for the
SEV, you NEED to edit the file deims_d6_migration.migrate.inc and
CHANGE things.

In the Arctic Example, we do not have Core Areas. I suggest you comment
out this block:
//      'DeimsTaxonomyCoreAreas' => array(
//        'class_name' => 'DrupalTerm6Migration',
//        'description' => "Taxonomy migration for the 'Core areas' vocabulary.$
//        'source_connection' => 'drupal6',
//        'source_version' => 6,
//        // @todo Make this vocabulary source ID automatic from the D6 databas$
//        'source_vocabulary' => '1',
//        'destination_vocabulary' => 'core_areas',
//      ),

Also, the next block assumes your LTER controlled has a vid=9,
but Arctic's vid for the LTER controlled seems to be "2", so, look below,
third line from the bottom:

      'DeimsTaxonomyLTERControlled' => array(
        'class_name' => 'DrupalTerm6Migration',
        'description' => "Taxonomy migration for the 'LTER Controlled' vocabula$
        'source_connection' => 'drupal6',
        'source_version' => 6,
        // @todo Make this vocabulary source ID automatic from the D6 database.
        'source_vocabulary' => '2',
        'destination_vocabulary' => 'lter_controlled_vocabulary',
      ),

That's it.
