#include <windows.h>
#include <iostream>

/*Задача 30
Определить рекурсивную функцию для вычисления следующей математической
функции (аналог факторнала) F(n), где n — целое :
F(N)= 3*6*9*...*(3-n). область определения: п>=1.
*/

using namespace std;

int TipoFactorial(int n) {
    if (n > 0)
        return (3 * n) * TipoFactorial(n - 1);
    else
        return 1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << TipoFactorial(3);
}