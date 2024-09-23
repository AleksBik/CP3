#include <iostream>
#include <cstdlib> // для rand()
#include <ctime>   // для time()
#include "load.h"

void fill(int **matrix, int n, int m) {
  srand(time(nullptr)); // Инициализация генератора случайных чисел

  // Заполнение матрицы случайными числами
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 101 - 50; // Числа от -50 до 50
    }
  }
}

void process(int **matrix, int n, int m) {
  // Замена отрицательных чисел на квадраты
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] < 0) {
        matrix[i][j] = matrix[i][j] * matrix[i][j];
      }
    }
  }
}
