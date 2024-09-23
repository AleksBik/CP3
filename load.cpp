#include "load.h"
#include <iostream>
#include <windows.h>

#define LL LoadLibraryA // Загружаем библиотеку
#define GPA GetProcAddress // Получаем адрес функции 
#define FL FreeLibrary // Выгружаем библиотеку

void LoadRun(const char* s, int* m, int sss) {
    HMODULE lib = LL(s); // Загрузка библиотеки в память
    if (!lib) {
        std::cerr << "Error of open lib '" << s << "'\n";
        return;
    }

    // Получение указателя на функцию "input"
    typedef int(*fillFunc)(int*, int); 
    fillFunc fun = (fillFunc)GPA(lib, "fill");
    if (fun == NULL) {
        std::cerr << "Error downloud func fill\n";
    } else {
        fun(m, sss);
    }

    // Получение указателя на функцию "count"
    typedef int(*processFunc)(int*, int);
    processFunc fun2 = (processFunc)GPA(lib, "process");
    if (fun2 == NULL) {
        std::cerr << "Error downloud func process\n";
    } else {
        fun2(m, sss);
    }

    FL(lib); // Выгрузка библиотеки
}