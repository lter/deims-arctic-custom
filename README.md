deims-arctic-custom
===================

Customizations for the migration and settings of the Arctic LTER DEIMS

This is a set of custom Drupal 7.x modules. The _arctic_ module extends the Drupal contributed migrate module and the DEIMS custom module D6 Migrate module, which in itself is an extension of the Drupal contrib. migrate. The _arctic_ feature modules addresses special customizations of the Arctic LTER information management system

Instructions

Clone

* `git clone --branch 7.x-1.x git@github.com:lter/deims-arctic-custom.git`

into a place of your choice (current directory, Desktop, etc)

Or download this module from:

* `https://github.com/lter/deims-ntl-custom/archive/7.x-1.x.zip`

Extract the contents in a local directory, you will copy the parts inside to different places in your DEIMS install, as we explain now.

Once you have the repository locally, create a folder named modules under your DEIMS root sites/default (unless you have already made it)

Under the sites/default/modules, create another folder named _arctic_

Copy the arctic.* files you downloaded from github locally, into the _arctic_ folder you just created. Also, copy the migration subfolder you downloaded from github into the same arctic folder. 

Also, we need new content types, views and DEIMS content type extensions for the ARC LTER. You will find those, featurized, in the local github download subfolder named features . Inside, you will see some features that start with the word deims and some that begin with the word ntl. THe deims are overrides of existing features, and are located in /profiles/deims/modules/features, just place the content accordingly, overwrite the existing ones with the new - DEIMS will enact the changes. THe custom, ntl specific need to be moved too, for example, copy them in the modules folder, like this:

cp -r deims-arctic-custom/features/ntl_* DEIMSROOT/sites/default/modules/


There are things you need to do before you use the migration:

The default DEIMS D7 would have created 5 vocabularies for you, including the
LTER Keywords and the Core Areas. Furthermore, the assumption is that
the Core Areas are in "vid=1" in the source vocabulary, and the 
LTER Keywords are in the "vid=9" vocabulary.  This is only true for the
Sevilleta, you NEED to edit the file deims_d6_migration.migrate.inc and
CHANGE things.

In the Arctic Example, we do not have Core Areas. I suggest you comment
out this block:

* `      'DeimsTaxonomyCoreAreas' => array(`
* `       'class_name' => 'DrupalTerm6Migration',`
* `        'description' => "Taxonomy migration for the 'Core areas' vocabulary.",`
* `        'source_connection' => 'drupal6',`
* `        'source_version' => 6,`
* `        // @todo Make this vocabulary source ID automatic from the D6 database.`
* `        'source_vocabulary' => '1',`
* `        'destination_vocabulary' => 'core_areas',`
* `      ),`
   

Also, the next block assumes your LTER controlled has a vid=9,
but Arctic's vid for the LTER controlled seems to be "2", so, look below,
third line from the bottom:

* `      'DeimsTaxonomyLTERControlled' => array(`
* `        'class_name' => 'DrupalTerm6Migration',`
* `        'description' => "Taxonomy migration for the 'LTER Controlled' vocabula$`
* `        'source_connection' => 'drupal6',`
* `       'source_version' => 6,`
* `        // @todo Make this vocabulary source ID automatic from the D6 database.`
* `        'source_vocabulary' => '2',`
* `        'destination_vocabulary' => 'lter_controlled_vocabulary',`
* `      ),`

