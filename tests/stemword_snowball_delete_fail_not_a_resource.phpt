--TEST--
stemword_snowball_delete fails if argument is not a resource
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$failure_list = array(
	1,
	true,
	'bla',
	array(),
	new stdClass(),
);
foreach ($failure_list as $not_a_stemmer)
{
	var_dump(stemword_snowball_delete($not_a_stemmer));
}
?>
--EXPECTF--
Warning: stemword_snowball_delete() expects parameter 1 to be resource, integer given in %sstemword_snowball_delete_fail_not_a_resource.php on line %d
bool(false)

Warning: stemword_snowball_delete() expects parameter 1 to be resource, boolean given in %sstemword_snowball_delete_fail_not_a_resource.php on line %d
bool(false)

Warning: stemword_snowball_delete() expects parameter 1 to be resource, string given in %sstemword_snowball_delete_fail_not_a_resource.php on line %d
bool(false)

Warning: stemword_snowball_delete() expects parameter 1 to be resource, array given in %sstemword_snowball_delete_fail_not_a_resource.php on line %d
bool(false)

Warning: stemword_snowball_delete() expects parameter 1 to be resource, object given in %sstemword_snowball_delete_fail_not_a_resource.php on line %d
bool(false)

