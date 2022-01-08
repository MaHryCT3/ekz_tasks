#include <windows.h>
#include <iostream>

using namespace std;


// Не совсем корректное задания, если нужно вернуть адресс, то мы никак не можем вернуть нулл, 
//поэтому мы возращаем указатель

float *FindNumber(float* arr, int size, float find_number) {
    for (int i = 0; i < size; i++) 
        if (arr[i] == find_number) return &arr[i];
    return NULL;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float arr[3][2] = { {1.05, 1.40}, {1.55, 31.41}, {-53, 5.5} };
    float *result = FindNumber(*arr, 6, 10);
    if (result != NULL) cout << *result;
    else cout << NULL;
}
