#!/bin/bash
echo -n "Введите имя исходного файла программы: "
read file_name

for optimization_keys in "-O0" "-Os" "-O1" "-O2" "-O3" "-O2 -march=native" "-O3 -march=native" "-O2 -march=native -funroll-loops" "-O3 -march=native -funroll-loops"
do
echo "----------------------------------------------------------------------------"
gcc -Wall $optimization_keys $file_name -lm
echo -n "1) Текущие ключи оптимизации: "
echo $optimization_keys
echo -n "2) Время, затраченное программой на выполнение: "
time ./a.out
echo -n "3) Занимание программой дисковое пространство (в байтах): "
du -h -b a.out
echo "----------------------------------------------------------------------------"
echo
done
