--TEST--
stemword_snowball_new should throw a warning and return false on fail
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_snowball_new('ramtamtam', 'FFFUUUU'));
?>
--EXPECTF--
Warning: stemword_snowball_new(): Could not create stemmer with ramtamtam algorithm for FFFUUUU charset in %sstemword_snowball_new_failure.php on line 2
bool(false)
