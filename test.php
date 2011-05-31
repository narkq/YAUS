<?php
$words = array(
	'�����',
	'������',
	'�����',
	'�����',
	'����������',
	'����������',
	'���������',
	'�������������',
	'�������������',
	'�������������',
	'��������',
	'��������',
	'��������',
	'��������',
	'���������',
	'���������',
	'���������',
	'����������',
	'����������',
	'�����������',
	'��������',
	'���������',
	'���������',
	'���������',
	'����������',
	'����������',
	'�����������',
);

$syscall_path = '../bloat/src/bloat';
foreach ($words as $word)
{
	$right = substr(`$syscall_path $word`, 0, -1);
	$result = stemword_ru_cp1251($word);
	if ($result !== $right)
	{
		echo "FAIL!\t($word)\t$result\tinstead of\t$right\n";
	}
	else
	{
		echo "PASS \t($word)\n";
	}
}

$c = 50;

$b = microtime(true);
for ($i = 0; $i < $c; $i++)
{
	foreach ($words as $word)
		`$syscall_path $word`;
}
$t = microtime(true) - $b;
echo "SYSCALL: ".($t)."\n";

$b = microtime(true);
for ($i = 0; $i < $c; $i++)
{
	foreach ($words as $word)
		stemword_ru_cp1251($word);
}
$t = microtime(true) - $b;
echo "FUNCCALL: ".($t)."\n";
