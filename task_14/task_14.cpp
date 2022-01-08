#include <windows.h>
#include <iostream>

/* Задача 14
Определить функцию, формирующую новый массив из двумерного массива
вещественных чисел путем удаления из него строки и столбца, в которых
находится минимальный элемент массива. Старый массив передавать в функцию
посредством формального параметра и сформированный массив функция также
должна возвращать посредством формального параметра.
*/

using namespace std;

const int ROWS = 3, COLS = 2;

void FillNewArray(float (&arr)[ROWS][COLS], float (&new_arr)[ROWS-1][COLS-1]) {
    int minRowsIndex = 0;
    int minColsIndex = 0;
    for (int i = 0; i < ROWS; i++) {       
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] < arr[minRowsIndex][minColsIndex]) {  // Находим индекс минимального элемента в масиве
                minRowsIndex = i;
                minColsIndex = j;
            }
        }
    }
    for (int i = 0, rowsIndex = 0; i < ROWS; i++) {
        if (i == minRowsIndex) continue;               // пропускаем строчку в которой находится минимальный элемент масива
        for (int j = 0, colsIndex = 0; j < COLS; j++) {
            if (j == minColsIndex) continue;          // пропускаем столбец в которой находится минимальный элемент масива
            new_arr[rowsIndex][colsIndex] = arr[i][j];
            colsIndex++;
        }
        rowsIndex++;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float arr[ROWS][COLS] = { {31.64, 2.43}, 
                            {1.13, 3.61},
                            {21.134, 5.13} };

    float new_arr[ROWS-1][COLS-1];

    FillNewArray(arr, new_arr);
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            cout << new_arr[j][i] << '\t';
        }
        cout << endl;
    }
    
}