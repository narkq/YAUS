<?php
$words = array(
	'сучка',
	'сучкой',
	'сучку',
	'сучке',
	'директором',
	'директорам',
	'директору',
	'бухгалтерский',
	'бухгалтерская',
	'бухгалтерское',
	'домашний',
	'домашная',
	'домашнее',
	'менеджер',
	'менеджеру',
	'менеджера',
	'менеджере',
	'менеджером',
	'менеджерам',
	'менеджерами',
	'сталевар',
	'сталевару',
	'сталевара',
	'сталеваре',
	'сталеваром',
	'сталеварам',
	'сталеварами',
);

foreach ($words as $word)
{
	$right = substr(`~/src/bloat/bin/Debug/bloat $word`, 0, -1);
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
		`~/src/bloat/bin/Debug/bloat $word`;
}
$t = microtime(true) - $b;
echo "SYSCALL: ".($t/1000)."\n";

$b = microtime(true);
for ($i = 0; $i < $c; $i++)
{
	foreach ($words as $word)
		stemword_ru_cp1251($word);
}
$t = microtime(true) - $b;
echo "FUNCCALL: ".($t/1000)."\n";
