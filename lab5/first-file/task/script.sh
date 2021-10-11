#!/bin/bash
echo -n "Введите имя исходного файла программы: "
read file_name
echo -n "Введите ключи оптимизации: "
read compilation_keys

gcc -Wall $compilation_keys $file_name -lm

echo -n "1) Текущие ключи оптимизации: "
echo $compilation_keys
echo -n "2) Время, затраченное программой на выполнение: "
time ./a.out
echo -n "3) Занимание программой дисковое пространство (в байтах): "
du -h -b a.out
