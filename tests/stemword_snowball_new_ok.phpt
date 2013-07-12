--TEST--
stemword_snowball_stem should stem russian fine
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
var_dump(stemword_snowball_new('ru', 'UTF_8'));
?>
--EXPECTF--
resource(%d) of type (Snowball stemmer)
