#include <windows.h>
#include <iostream>

using namespace std;

void CreateArray(int** arr, int cols, int rows) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = k++;
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

    int** arr = new int* [rows];   
    for (int i = 0; i < rows; i++)  // Создаем массив с выделением динамеческой памяти
        arr[i] = new int[cols]; 

    CreateArray(arr, cols, rows); // Создаем массив по условиям задачи

    for (int i = 0; i < rows; i++) {     // Это вывод массива, в задание его делать не нужно
        for (int j = 0; j < cols; j++) {  // Но результат проверить то нужно
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)  // Очищаем память выделенную на массив
        delete arr[i];              // Хоть visual studio и делает автоматически все таки для понимания стоит это делать
    delete[] arr;
}

