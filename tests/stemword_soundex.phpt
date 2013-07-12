--TEST--
stemword_soundex
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$word_list = array_map(
	function($word) {
		return substr($word, 0, -1);
	},
	file(__DIR__.'/words_for_soundex.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_soundex($word));
}
?>
--EXPECT--
string(4) "r163"
string(4) "r163"
string(5) "a2613"
string(5) "a2613"
string(4) "t520"
string(5) "p1236"
