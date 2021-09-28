#!/bin/bash
# Дана команда: ls file1 file2. Файл file1 существует, файл file2 не существует.
# Перенаправьте ТОЛЬКО стандартную ошибку в конвейер, одновременно записывая номера строк и
# перенаправьте вывод в файл.
ls file1 file2 2>temp >output
cat temp | wc -l > error-output-count-lines
rm temp
