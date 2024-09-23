# CP3

g++ -c -o main.o -fPIC main.cpp
g++ -c -o array.o -fPIC array.cpp
g++ -c -o matrix.o -fPIC matrix.cpp

g++ -shared -o lib_ar.dll array.o
g++ -shared -o lib_matr.dll matrix.o

g++.exe -c -fPIC main.cpp
g++.exe -c -fPIC load.cpp
g++.exe -shared -o load.dll load.o
g++.exe -o main.exe main.o -L./ -lload
