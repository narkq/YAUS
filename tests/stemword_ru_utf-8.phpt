--TEST--
stemword_ru for utf-8 encoding
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
	file(__DIR__.'/words_utf-8.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_ru($word, true));
}
?>
--EXPECT--
string(4) "су"
string(4) "су"
string(4) "су"
string(4) "су"
string(16) "директор"
string(16) "директор"
string(16) "директор"
string(22) "бухгалтерск"
string(22) "бухгалтерск"
string(22) "бухгалтерск"
string(12) "домашн"
string(12) "домашн"
string(12) "домашн"
string(16) "менеджер"
string(16) "менеджер"
string(16) "менеджер"
string(16) "менеджер"
string(16) "менеджер"
string(16) "менеджер"
string(16) "менеджер"
string(16) "сталевар"
string(16) "сталевар"
string(16) "сталевар"
string(16) "сталевар"
string(16) "сталевар"
string(16) "сталевар"
string(16) "сталевар"
string(6) "google"
string(7) "googles"
string(7) "googled"
string(7) "googler"
string(8) "googling"
string(9) "googlerer"
string(3) "sky"
string(5) "skies"
string(4) "have"
string(3) "has"
string(5) "storm"
string(6) "storms"
string(7) "stormed"
