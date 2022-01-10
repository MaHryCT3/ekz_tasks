#include <windows.h>
#include <iostream>
#include <cmath>
#include <iomanip>

/*Задача 25
Определить функцию вывода на экран n значений трех функций,
возврашаюшщих результат одного типа с однотипным параметром( (Fx) ) в
интервале значений аргумента от a до b с равным шагом.
Вывод производить в четыре столбика: значение аргумента, значение первой,
второй ин третьей функции. Использовать формальный параметр — массив
указателей на функции. В главной функции, используя описанную выше функцию,
вывести на экран 7 значений функций у1= sin^2(х)-1 , у2=cos^2(х)-1 и у3=|cos(х)
+sin(х)|^1/2 в интервале (0.0, 3p).
*/

using namespace std;

const int PI = 3.1415926;

double y1(double x) {
    return pow(sin(x), 2) - 1;
}

double y2(double x) {
    return pow(cos(x), 2) - 1;
}

double y3(double x) {
    return pow(abs(cos(x) + sin(x)), 1.0 / 2.0);
}


typedef double (*Func)(double);

Func output[3] = { y1, y2, y3 };  // https://metanit.com/cpp/tutorial/4.8.php

void OutputOnScreen(float n, float a, float b, Func *output) {
    cout.setf(ios::left | ios::fixed);
    cout.precision(4);

    cout << setw(13) << "x" << setw(13) << "y1" << setw(13) << "y2" << setw(13) << "y3" << endl;
    for (int x = a; x <= b; x += (b - a) / n) {
        cout << setw(13) << x << setw(13) << output[0](x) << setw(13) << output[1](x) << setw(13) << output[2](x) << endl;
    }
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    OutputOnScreen(7, 0.0, 3 * PI, output);
}