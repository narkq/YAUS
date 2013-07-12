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
$stemmer = stemword_snowball_new('ru');
$word_list = array_map(
	function($word) {
		return substr($word, 0, -1);
	},
	file(__DIR__.'/words_for_snowball_ru_utf-8.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_snowball_stem($stemmer, $word));
}
?>
--EXPECT--
string(8) "сучк"
string(8) "сучк"
string(8) "сучк"
string(8) "сучк"
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
