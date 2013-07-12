--TEST--
stemword_snowball_delete deletes a resource
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$stemmer = stemword_snowball_new('ru', 'UTF_8');
var_dump(stemword_snowball_delete($stemmer));
var_dump($stemmer);
?>
--EXPECTF--
bool(true)
resource(%d) of type (Unknown)
