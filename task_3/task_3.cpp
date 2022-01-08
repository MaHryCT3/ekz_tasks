#include <windows.h>
#include <iostream>

using namespace std;

int FindMultiplesSeven(int* arr, int size, int& num) {
    for (int i = 0; i < size; i++)
        if (arr[i] % 7 == 0) {
            num = arr[i];
            return 1;
        }
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    int arr[3][2] = { {1, 2}, {3, 31}, {21, 5} };
    int num, result;
    result = FindMultiplesSeven(*arr, 6, num);
    if (result == 1) cout << num;
    else cout << 0;
}
