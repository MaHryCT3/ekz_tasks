#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;


float OrderArrayAndGetMinimum(float* array, int count_el, float a, float b) {
    float* min = &array[0];  // переменная в которую будем записывать минимальное число

    float temp; // временная перемеенная для обмена данных в ячейках массива

    for (int i = 0; i < count_el - 1; i++) {   // выполняем сортировку пузырьком
        if (array[i] > a && array[i] < b) min = &array[i]; // как раз таки находим минимальный элемент массива 
        for (int j = 0; j < count_el - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    if (*min > a && *min < b) return *min; // если минимальный элемент входит в интервал от а до б, то возвращаем указатель на него
    else return NULL; // если не входит то возращаем NULL т.е 0
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float array[] = { 1.323222, 3.12, 3.12, 5.41, 3.32, 4.12314124, 13.31231231 };
    int count_elements_array = sizeof(array) / sizeof(*array); // определяем количество элементов в массиве
    float minimal = OrderArrayAndGetMinimum(array, count_elements_array, 1, 4);  // последние 2 числа это промежуток поиска минимального числа
    cout << minimal;
}

