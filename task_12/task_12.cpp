#include <windows.h>
#include <iostream>

/*
task_12
Определить функцию упорядочения произвольного массива вещественных чисел
по возрастанию. В функции вывести на экран элементы полученного массива по k
значений в строки значение k передавать в функцию, используя параметр.

В main определить с инициализацией трехмерный массив, применить к нему
функцию.
*/

using namespace std;

const int size = 12;

void sort_arr(float &arr[size], int k) {  // Сортирует массив по возрастанию
    float temp;  // временная переменная для обмена ячеек масива

    for (int i = 0; i < size - 1; i++) {   // выполняем сортировку пузырьком 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


}

