#include <windows.h>
#include <iostream>

/*
task 8 
Определить функцию, возвращающую массив, составленный из четных элементов
произвольного символьного массива (четные номера индексов). Исходный массив — параметра функции.
*/

using namespace std;



char* GetArray(char *arr, int size) {
    char* new_arr = new char[size / 2];
    int count = 0;
    for (int i = 0; i < size; i++){  
        if (i % 2 == 0) {
            new_arr[count++] = arr[i];
        }
    }
    return new_arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // pangram - короткий текст, использующий все или почти все буквы алфавита
    char pangram[] = { "Съешь ещё этих мягких французских булок, да выпей же чаю" }; // Используем любую фразу дамы сформировать символьный массив
    int size = sizeof(pangram) / sizeof(*pangram); // Определяем размер этого массива
    char *result = GetArray(pangram, size);
    for (int i = 0; i < size / 2; i++)  // вывод нового массива символов
        cout << result[i];

    delete[] result;
    
}