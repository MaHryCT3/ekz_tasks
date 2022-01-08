#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}


int* GetArray(int **arr, int rows, int cols) { 
    int size = rows;  // Определяем размер массива с результатом
    int* result_arr = new int[size];  // Выделяем дин. память на этот массив
    for (int i = 1; i < rows; i += 2) {  // Проходимся по четным строкам массива
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for (int j = 0; j < cols; j++) {   // Находим 2 максимальных значения в массиве
            if (arr[i][j] > max1) {
                max2 = max1;
                max1 = arr[i][j];
            }
            else if (arr[i][j] > max2) max2 = arr[i][j];
        }
        result_arr[i - 1] = max1;  // Каждую итерацию добавляем новые максимальные значения в массив
        result_arr[i] = max2;
    }
    return result_arr;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int ROWS = 4, COLS = 3;
    int size = ROWS * COLS;

    
    int **arr = new int* [ROWS];   // Создаем массив с выделением динамеческой памяти
    for (int i = 0; i < ROWS; i++)
        arr[i] = new int[COLS];

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = random(-100, 100);

    
    int* result = GetArray(arr, ROWS, COLS);
    for (int i = 0; i < size; i++)  // Выводим массив
        cout << result[i] << endl;
    
    delete[] result;  // удаляем массивы нафиг из памяти
    delete[] arr; 
}
