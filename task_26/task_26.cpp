#include <windows.h>
#include <iostream>

/*Задача 26
Определить рекурсивную функцию для вычисления суммы элементов
одномерного массива. Дать пример использования. 
*/

using namespace std;

int SumArray(int* arr, int size) {
    if (size - 1 > 0)
        return arr[size - 1] + SumArray(arr, size - 1);
    else
        return arr[size - 1];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     
    const int arrSize = 10;
    int arr[arrSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << SumArray(arr, arrSize);
}