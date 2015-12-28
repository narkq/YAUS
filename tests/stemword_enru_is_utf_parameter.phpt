--TEST--
stemword_enru should not take second parameter
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_enru('stun', 0));
?>
--EXPECTF--
Warning: stemword_enru() expects exactly 1 parameter, 2 given in %sstemword_enru_is_utf_parameter.php on line %d
NULL
