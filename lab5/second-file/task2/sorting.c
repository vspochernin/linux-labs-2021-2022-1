#include <stdlib.h>
#include <time.h>
#include <stdio.h>

const size_t ARRAY_SIZE = 10000;

int getRandomNumber(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

void fillArray(int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = getRandomNumber(-1000, 1000);
  }
}

void selectionSort(int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    size_t maxIndex = i;
    for (size_t j = i + 1; j < size; j++)
    {
      if (arr[j] > arr[maxIndex])
      {
        maxIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[maxIndex];
    arr[maxIndex] = temp;
  }
}

int main()
{
  srand(time(0));
  int* arr = malloc(sizeof(int) * ARRAY_SIZE);
  fillArray(arr, ARRAY_SIZE);
  selectionSort(arr, ARRAY_SIZE);

  return 0;
}