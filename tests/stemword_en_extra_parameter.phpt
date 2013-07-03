--TEST--
stemword_en should not take extra parameter
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_en('speedy', true));
?>
--EXPECTF--
Warning: stemword_en() expects exactly 1 parameter, 2 given in %sstemword_en_extra_parameter.php on line %d
NULL
