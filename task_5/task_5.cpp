#include <windows.h>
#include <iostream>

/*
task 5
Определить функцию, возвращающую с помощью формального параметра
двумерный массив, элементами которого являются последовательные натуральные
числа от 1 и далее. Память на массив чисел выделить в главной функции динамически.
*/

using namespace std;

void FillArray(int rows, int cols, int** result_arr) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result_arr[i][j] = k++;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols;
    cout << "Enter rows: "; cin >> rows; // Количество строк
    cout << "Enter cols: "; cin >> cols; // Количество столбиков
    
    int** result_arr = new int* [rows]; // Выделяем дин. память
    for (int i = 0; i < rows; i++)
        result_arr[i] = new int [cols];

    FillArray(rows, cols, result_arr); 
  
    for (int i = 0; i < rows; i++) {     // Это вывод массива, в задание его делать не нужно
        for (int j = 0; j < cols; j++) {  // Но результат проверить то нужно
            cout << result_arr[i][j] << '\t';
        }
        cout << endl;
    }
    
    for (int i = 0; i < rows; i++)  // Очищаем память выделенную на массив
        delete result_arr[i];              // Хоть visual studio и делает автоматически все таки для понимания стоит это делать
    delete[] result_arr;
}

