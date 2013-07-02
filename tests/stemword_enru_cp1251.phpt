--TEST--
stemword_enru for cp1251 encoding
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
	var_dump(stemword_enru($word));
}
?>
--EXPECT--
string(2) "��"
string(2) "��"
string(2) "��"
string(2) "��"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(11) "�����������"
string(11) "�����������"
string(11) "�����������"
string(6) "������"
string(6) "������"
string(6) "������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
string(8) "��������"
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
