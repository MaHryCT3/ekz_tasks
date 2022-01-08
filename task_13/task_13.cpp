#include <windows.h>
#include <iostream>
#include <cmath>

/*Задача 13

Определить функцию, возвращающую косинус угла между двумя векторами
N-мерного пространства, каждый из которых представлен одномерным массивом -
координат вектора.
Воспользоваться формулой для скалярного произведения векторов:
(a * b) = |a| * |b| * cos(α)
cos(α) = (a * b) / |a| * |b|
Формула - https://media.discordapp.net/attachments/279531827272613888/929443005788745728/img9.png?width=894&height=670
*/

using namespace std;

const int N = 3;

float GetCos(int (&a)[N], int (&b)[N], int N) {
    int numerator = 0;
    int denominator1 = 0;
    int denominator2 = 0;
    for (int i = 0; i < N; i++) {  // Находим числитель
        numerator += a[i] * b[i];
    }
    for (int i = 0; i < 2; i++) { // Находим знаменатель
        for (int j = 0; j < N; j++) {
            denominator1 += pow(a[j], 2);
            denominator2 += pow(b[j], 2);
        }
    }
    float result = numerator / (sqrt(denominator1) * sqrt(denominator2));
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[3] = { 2, 3, 4 };
    int b[3] = { 6, 3, 8 };

    float cosin = GetCos(a, b, N);
    cout << cosin;
}