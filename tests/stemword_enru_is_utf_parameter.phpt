--TEST--
stemword_enru should not take non-boolean values as second parameter
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_enru('stun', 0));
var_dump(stemword_enru('stun', 1));
var_dump(stemword_enru('stun', 'a string'));
var_dump(stemword_enru('stun', array()));
var_dump(stemword_enru('stun', new stdClass()));
?>
--EXPECTF--
string(4) "stun"
string(4) "stun"
string(4) "stun"

Warning: stemword_enru() expects parameter 2 to be boolean, array given in %s/tests/stemword_enru_is_utf_parameter.php on line %d
NULL

Warning: stemword_enru() expects parameter 2 to be boolean, object given in %s/tests/stemword_enru_is_utf_parameter.php on line %d
NULL
