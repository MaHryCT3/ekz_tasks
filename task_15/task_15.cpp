#include <windows.h>
#include <iostream>

/*Задача 15

Определить функцию, возвращающую одномерный массив с помощью оператора
return. Массив формируется из элементов трехмерного массива, передаваемого в
функцию Через параметр, которые больше среднеарифметического значения
элементов массива. Память для формируемого массива выделить в функции
динамически.
*/

using namespace std;

const int ROWS = 4, COLS = 3, MATX = 2;

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

int* GetNewArray(int (&arr)[ROWS][COLS][MATX],int &newArrSize) {
    float sum = 0;                      
    float size = ROWS * COLS * MATX;    // количество записей в массиве
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < MATX; k++) {
                sum += arr[i][j][k];   // находим сумму элементов в массиве
            }
        }
    }
    float AverageValue = sum / size;
    cout << "Среднее арифметическое в масcиве: " << AverageValue << endl;

    for (int i = 0; i < ROWS; i++) {        // находим количество элементов которые больше ср. ариф. для выделения памяти
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < MATX; k++) {                
                if (arr[i][j][k] > AverageValue) newArrSize++;
            }
        }
    }
    int *result_arr = new int[newArrSize];   // Выделяем дин. память на массив
    int index = 0;
    for (int i = 0; i < ROWS; i++) {  // записываем значения больше ср. ариф. в масив
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < MATX; k++) {
                if (arr[i][j][k] > AverageValue) result_arr[index++] = arr[i][j][k];
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

    int arr[ROWS][COLS][MATX];
    
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            for (int k = 0; k < MATX; k++){
                arr[i][j][k] = random(-100, 100);
            }
        }
    }
    int newArrSize = 0;
    int* result_arr = GetNewArray(arr, newArrSize);

    cout << "\nВывод массива:\n";
    for (int i = 0; i < newArrSize; i++) cout << result_arr[i] << '\t';
}