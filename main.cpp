#include <iostream>
#include <windows.h> 
#include "load.h"
#define N 67
#define A 7
#define B 6

#define LL LoadLibraryA // Загружаем библиотеку
#define GPA GetProcAddress // Получаем адрес функции 
#define FL FreeLibrary // Выгружаем библиотеку

int main() {
  int choice;
  std::cout << "1. Matrix\n";
  std::cout << "2. Array\n";
  std::cout << "Choice variant: ";
  std::cin >> choice;

  if (choice == 1) {
    // Выделение памяти для матрицы (двумерный массив)
    int** matr = new int*[A]; 
    for (int i = 0; i < A; ++i) {
      matr[i] = new int[B]; 
    }

    // Вызов LoadRun для матрицы
    LoadRun("lib_matr.dll", (int*)matr, A * B); // Передаем адрес матрицы

    // Вывод матрицы
    std::cout << "Matrix:\n";
    for (int i = 0; i < A; i++) {
      for (int j = 0; j < B; j++) {
        std::cout << matr[i][j] << " ";
      }
      std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < A; ++i) {
      delete[] matr[i];
    }
    delete[] matr;

  } else if (choice == 2) {
    // Выделение памяти для массива
    int* arr = new int[N];

    // Вызов LoadRun для массива
    LoadRun("lib_ar.dll", arr, N);

    // Вывод массива
    std::cout << "Array:\n";
    for (int i = 0; i < N; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete[] arr;
  } else {
    std::cout << "Incorrect choice.\n";
  }

  return 0;
}