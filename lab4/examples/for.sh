#!/bin/sh
for (( i=1; $i <= 10; i++ ))
do
	echo $i
done

echo "==============================="

count=0
for i in `cat /etc/group`
do
	count=`expr "$count" + 1`
	echo "Строка номер $count :"
	echo $i
done
echo "Конец файла"

echo "==============================="

for i in `seq 1 5`
do
	echo $i
done
