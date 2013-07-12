--TEST--
stemword_snowball_delete fails if argument is not a stemmer resource
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$not_a_stemmer = fopen(__FILE__, 'r');
var_dump(stemword_snowball_delete($not_a_stemmer));
var_dump($not_a_stemmer);
?>
--EXPECTF--
Warning: stemword_snowball_delete(): supplied resource is not a valid Snowball stemmer resource in %sstemword_snowball_delete_fail_wrong_resource_type.php on line %d
bool(false)
resource(%d) of type (stream)
