--TEST--
stemword_en for cp1251 encoding
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
	file(__DIR__.'/words_cp1251.txt')
);
foreach ($word_list as $word)
{
	var_dump(stemword_en($word));
}
?>
--EXPECT--
string(5) "сучка"
string(6) "сучкой"
string(5) "сучку"
string(5) "сучке"
string(10) "директором"
string(10) "директорам"
string(9) "директору"
string(13) "бухгалтерский"
string(13) "бухгалтерская"
string(13) "бухгалтерское"
string(8) "домашний"
string(8) "домашная"
string(8) "домашнее"
string(8) "менеджер"
string(9) "менеджеру"
string(9) "менеджера"
string(9) "менеджере"
string(10) "менеджером"
string(10) "менеджерам"
string(11) "менеджерами"
string(8) "сталевар"
string(9) "сталевару"
string(9) "сталевара"
string(9) "сталеваре"
string(10) "сталеваром"
string(10) "сталеварам"
string(11) "сталеварами"
string(5) "googl"
string(5) "googl"
string(5) "googl"
string(7) "googler"
string(5) "googl"
string(7) "googler"
string(3) "sky"
string(3) "sky"
string(4) "have"
string(2) "ha"
string(5) "storm"
string(5) "storm"
string(5) "storm"
