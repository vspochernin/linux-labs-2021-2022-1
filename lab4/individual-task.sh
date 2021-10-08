#!/bin/bash
# Вариант 5

printerrormessage ()
{
	echo "Некорректные параметры"
	echo "Возможен только один параметр - целое положительное нечетное число"
	exit
}

if [ $# -ne 1 ]
then
	printerrormessage
fi
if [[ $1 =~ [^0-9] ]]
then
	printerrormessage
fi
if [ $[$1 % 2] -ne 1 ]
then
	printerrormessage
fi

spaces=0
for i in `seq $1 -1 1`
do
	for j in `seq 0 $(($spaces - 1))`
	do
		echo -n "  "
	done
	for k in `seq $i -1 1`
	do
		echo -n "* "
	done
	spaces=$(($spaces+1))
	echo ""
done
