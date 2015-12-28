--TEST--
stemword_ru should not take non-boolean values as second parameter
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_ru('stun', 0));
?>
--EXPECTF--
Warning: stemword_ru() expects exactly 1 parameter, 2 given in %sstemword_ru_is_utf_parameter.php on line %d
NULL
