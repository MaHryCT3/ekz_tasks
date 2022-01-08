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

const int ROWS = 2, COLN = 2, MATX = 2;

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void sort_arr(float* arr, int size, int k) {  // Сортирует массив по возрастанию
    float temp;    // временная переменная для обмена ячеек масива

    for (int i = 0; i < size - 1; i++) {   // выполняем сортировку пузырьком 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //for (int i = 0; i < size; i++)
    //    cout << arr[i] << ' ';
    int index = 0;
    for (int i = 0; i < size / k; i++){
        for (int j = 0; j < k; j++) {
            cout << arr[index++] << "\t";
        }
        cout << endl;
    }

    for (int remainder = 0; remainder < size % k; remainder++)
        cout << arr[index++] << "\t";
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    float arr[ROWS][COLN][MATX];
    int size = ROWS * COLN * MATX;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLN; j++) {      // создаем массив из рандомных чисел
            for (int z = 0; z < MATX; z++) {
                arr[i][j][z] = random(-100, 100);
            }
        }
    }

    sort_arr(**arr, size, 3);

    //for (int i = 0; i < ROWS; i++) {          // Вывод трехмерного массива
    //    for (int j = 0; j < COLN; j++) {
    //        for (int z = 0; z < MATX; z++) {
    //            cout << arr[i][j][z] << " ";   
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}


}

