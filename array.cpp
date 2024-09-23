#include <iostream>
#include <cstdlib>
#include <ctime>
#include "load.h"

void fill(int *array, int n) {
  srand(time(nullptr));

  // Заполнение массива случайными числами
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 101 - 50; // Числа от -50 до 50
  }
}

void process(int *array, int n) {
  // Замена отрицательных чисел на квадраты
  for (int i = 0; i < n; i++) {
    if (array[i] < 0) {
      array[i] = array[i] * array[i];
    }
  }
}