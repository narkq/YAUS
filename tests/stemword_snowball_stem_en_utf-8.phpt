--TEST--
stemword_snowball_stem should stem english fine
--SKIPIF--
<?php
if (!extension_loaded("yaus"))
{
	print "skip";
}
--FILE--
<?php
$stemmer = stemword_snowball_new('en', 'UTF_8');
$word_list = array_map(
	function($word) {
		return substr($word, 0, -1);
	},
	file(__DIR__.'/words_for_snowball_en_utf-8.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_snowball_stem($stemmer, $word));
}
?>
--EXPECT--
string(5) "googl"
string(5) "googl"
string(5) "googl"
string(7) "googler"
string(5) "googl"
string(7) "googler"
string(3) "sky"
string(3) "sky"
string(4) "have"
string(3) "has"
string(5) "storm"
string(5) "storm"
string(5) "storm"
