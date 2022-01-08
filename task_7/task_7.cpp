#include <windows.h>
#include <iostream>


/*
task_7
Определить функцию, результат работы которой - матрица, сформированная из
сумм элементов каждой нечетной строки произвольной матрицы целых чисел,
кратных простому числу m (m — параметр функцин), и количества этих элементов
в каждой нечетной строке. Первая строка нового массива — суммы, вторая строка
— количества нужных элементов каждой нечетной строки.
Исходный и формируемый массивы передать в функцию как параметры. Дать
пример использования функции.
*/

const int ROWS = 5, COLS = 6;
const int RESULT_COLS = (ROWS + 1) / 2;

using namespace std;

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void FillArray(int (&arr)[ROWS][COLS], int m, int (&new_arr)[2][RESULT_COLS]) {
    int count;
    int sum;

    for (int i = 0, index = 0; i < ROWS; i += 2, index++) {
        count = 0;  // обнуляем значения для новой строки
        sum = 0;
        for (int j = 0; j < COLS; j++){
            if (arr[i][j] % m == 0) {
                sum += arr[i][j];
                count++;
            }

        }
        new_arr[0][index] = sum;     // записываем сумму
        new_arr[1][index] = count;  // записываем количество чисел
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));
    
    int new_arr[2][RESULT_COLS];     // массив с результатами
    int arr[ROWS][COLS];                // исходнй массив
    int m = 7;                          // из условия, кратность числа

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {      // создаем массив из рандомных чисел
            arr[i][j] = random(-100, 100);
        }
    }
    FillArray(arr, m, new_arr);

    for (int i = 0; i < 2; i++) {               // Это вывод массива
        for (int j = 0; j < RESULT_COLS; j++) {
            cout << new_arr[i][j] << '\t';
        }
        cout << endl;
    }
}

