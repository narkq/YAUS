--TEST--
stemword_ru for cp1251 encoding
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
	var_dump(stemword_ru($word));
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
