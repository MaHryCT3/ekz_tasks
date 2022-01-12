#include <windows.h>
#include <iostream>

/*Задача 29
Определить рекурсивную функцию для вычисления следующей математической

функиин (аналог факториала) F(п), где n — целое:

F(N) = 3*5*7*...*(2*n+1), Область определения: n>=1.
*/

using namespace std;

int TipoFactorial(int n) {
    if (n > 0) 
        return (2 * n + 1) * TipoFactorial(n - 1);
    else
        return 1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << TipoFactorial(3);

}