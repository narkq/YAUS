--TEST--
stemword_en for utf-8 encoding
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
	var_dump(stemword_en($word));
}
?>
--EXPECT--
string(10) "сучка"
string(12) "сучкой"
string(10) "сучку"
string(10) "сучке"
string(20) "директором"
string(20) "директорам"
string(18) "директору"
string(26) "бухгалтерский"
string(26) "бухгалтерская"
string(26) "бухгалтерское"
string(16) "домашний"
string(16) "домашная"
string(16) "домашнее"
string(16) "менеджер"
string(18) "менеджеру"
string(18) "менеджера"
string(18) "менеджере"
string(20) "менеджером"
string(20) "менеджерам"
string(22) "менеджерами"
string(16) "сталевар"
string(18) "сталевару"
string(18) "сталевара"
string(18) "сталеваре"
string(20) "сталеваром"
string(20) "сталеварам"
string(22) "сталеварами"
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
