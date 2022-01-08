#include <windows.h>
#include <iostream>

/*
Определить функцию, возвращающую с помощью return одномерный числовой
массив (на массив в функции выделить динамическую память), упорядоченный по
возрастанию, сформированный из элементов двух других одномерных массивов,
которые передавать в функцию как параметры.

В main определить с инициализацией два одномерных массива, сформировать
‘упорядоченный массив из элементов этих массивов, используя функцию.
*/

using namespace std;

const int size1 = 8, size2 = 9; // размеры масивов

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}


void sort_arr(int* &arr, int &size) {  // Сортирует массив по возрастанию
    int temp;  // временная переменная для обмена ячеек масива

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

int* get_array(int (&arr1)[size1], int (&arr2)[size2]){
    int size = size1 + size2;

    int* result_arr = new int[size];

    for (int i = 0; i < size1; i++){
        result_arr[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++){
        result_arr[size1 + i] = arr2[i];
    }


    sort_arr(result_arr, size);
    return result_arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int arr1[size1], arr2[size2];   // масивы

    for (int i = 0; i < size1; i++) 
        arr1[i] = random(-100, 100);
    for (int i = 0; i < size2; i++)   // заполняем массивы рандомными числами
        arr2[i] = random(-100, 100);
    int* result_arr = get_array(arr1, arr2);
    for (int i = 0; i < size1 + size2; i++) cout << result_arr[i] << " ";

    delete[] result_arr;
}

