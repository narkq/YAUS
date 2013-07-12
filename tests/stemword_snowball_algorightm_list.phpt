--TEST--
stemword_snowball_algorithm_list works
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$list = stemword_snowball_algorithm_list();
var_dump(in_array('porter', $list));
var_dump(in_array('english', $list));
var_dump(in_array('russian', $list));
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
