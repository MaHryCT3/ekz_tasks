#include <windows.h>
#include <iostream>

/*
Определить функцию, имеющую в качестве параметра трехмерный
целочисленный массив. Результатом работы функции, является одномерный
массив, возвращаемый с помошью return. Массив составляется из всех элементов
трехмерного массива, кратных 3. На формируемый массивв функции выделяется динамическая память.
*/

const int ROWS = 2, COLN = 2, MATX = 2;

using namespace std;


int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

int* GetArray(int (&arr)[ROWS][COLN][MATX], int& size) {                      
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLN; j++) {      // Определяем размер будущего массива с чилсами кратными трем
            for (int z = 0; z < MATX; z++) {
                if (arr[i][j][z] % 3 == 0) size++;
            }
        }
    }
    int* result_arr = new int[size];   // создаем дин. массив
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLN; j++) {      // Находим числа кратные трем
            for (int z = 0; z < MATX; z++) {
                if (arr[i][j][z] % 3 == 0) result_arr[index++] = arr[i][j][z];
            }
        }
    }
    return result_arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL)); 

    int arr[ROWS][COLN][MATX];
    int size = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLN; j++) {      // создаем массив из рандомных чисел
            for (int z = 0; z < MATX; z++) {
                arr[i][j][z] = random(-100, 100);
            }
        }
    }

    cout.setf(ios::left);
    int *result = GetArray(arr, size);
    for (int i = 0; i < size; i++) cout << result[i] << ' ';

    delete[] result;
}
