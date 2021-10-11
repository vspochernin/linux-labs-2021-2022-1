#!/bin/sh
sumcalc ()
{
	sum=$[$1 + $2]
}
echo "Введите первое число:"
read num1
echo "Введите второе число:"
read num2
sumcalc $num1 $num2
echo "Сумма чисел: $sum"
