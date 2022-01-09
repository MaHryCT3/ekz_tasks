#include <iostream>
#include <windows.h>

/*
task_10
Определить функцию, возвращающую с помощью returп матрицу, на которую в функции выделить 
динамическую память и запополнить матрнцу числами с клавиатyры. Функция возвращает по ссылке сумму 
и произведение всех отрицательных элементов или нули, если отрицательных элементов нет. 
*/

using namespace std;

int** new_matrix(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)   // Выделяем дин. память на массив
        arr[i] = new int[cols];
    return arr;
}

int** GetArray(int& sum, int& prod, int& rows, int& cols) {
    int rows, cols;
    cout << "Введите количество строк в массиве: "; cin >> rows;
    cout << "Введите количество столбцов в массиве: "; cin >> cols;
    int** arr = new_matrix(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Введите значение массива: "; cin >> arr[i][j];   // вводим числа с клавиатуры
        }
    }

    bool was_negative = false;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (arr[i][j] < 0){
                sum += arr[i][j];             // ищем отрицательные числа
                prod *= arr[i][j];
                was_negative = true;
            }
        }
    }
    if (!was_negative){
        prod = 0;           //если отрицательных значений не было, обнуляем произведение
    }
    
    return arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    int sum = 0;
    int prod = 1;
    int rows, cols;
    int** new_arr = GetArray(sum, prod, rows, cols);

    cout << "Сумма: " << sum << "\nПроизведение: " << prod << endl;

    for (int i = 0; i < rows; i++) 
        delete new_arr[i];               // очищаем памяти
    delete[] new_arr;
}

