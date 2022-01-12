#include <windows.h>
#include <iostream>
#include <cmath>
#include <iomanip>

/*Задача 28

Определить функцию вывода на экран в ш столбиков значения п функций,
возвращающих результат одного типа с однотипным параметром (&х)) в интервале
значений аргумента ота до 6, вывести п ( с равным шагом) значений. Использовать
формальный параметр — массив указателей на функции, значения т, план -
передавать в функцию посредством параметров.

В главной функции, используя описанную выше функцию, вывест+и 10
значений функций: у1 = arctg^2(х); у2 = ln(х+1); уЗ=|х^2-1|; у4= x^3 +2х;
*/

using namespace std;

double y1(double x) {
    return pow(atan(x), 2);
}

double y2(double x) {
    return log(x + 1);
}

double y3(double x) {
    return abs(pow(x, 2) - 1);
}

double y4(double x) {
    return pow(x, 2) + 2 * x;
}

typedef double (*Func)(double);

Func output[4] = { y1, y2, y3, y4 };

void ShowTable(Func *output, int m, int n, double a, double b) {
    cout.setf(ios::fixed || ios::left);
    cout.precision(4);

    // Хуй знает че за вывод она там хочет от нас я нихуя не понял
    //for (int x = a; x < b; x += (b-a))
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

}