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
var_dump(stemword_ru('stun', 1));
var_dump(stemword_ru('stun', 'a string'));
var_dump(stemword_ru('stun', array()));
var_dump(stemword_ru('stun', new stdClass()));
?>
--EXPECTF--
string(4) "stun"
string(4) "stun"
string(4) "stun"

Warning: stemword_ru() expects parameter 2 to be boolean, array given in %sstemword_ru_is_utf_parameter.php on line %d
NULL

Warning: stemword_ru() expects parameter 2 to be boolean, object given in %sstemword_ru_is_utf_parameter.php on line %d
NULL
