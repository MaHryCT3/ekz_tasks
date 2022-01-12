#include <windows.h>
#include <iostream>

/*Задача 32
Информация о каждом абитуриенте факультета находится в массиве структур c полями
1) Фамилия, имя, отчество;
2) признак - нуждается ли в общежитии;
3) оценки вступительных экзаменов (3-х);
Вывести на экран список абитурнентов, нуждающихся в общежитии.
*/

using namespace std;

const int SIZE_ARR = 4;

struct StudentInfo{
    char fio[35];
    bool needHostel;
    int scores[3];
};

StudentInfo StudentsData[SIZE_ARR]{
    {"Щербаков Лев Кириллович", true, {3, 4, 5}},
    {"Захаров Егор Денисович", false, {5, 5, 5}},
    {"Семенова Полина Артёмовна", false, {3, 5, 5}},
    {"Овсянников Александр Михайлович", true, {4, 4, 4}}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Список абитуриентов нуждающихся в общежитии:" << endl;
    for (int i = 0; i < SIZE_ARR; i++)
        if (StudentsData[i].needHostel) cout << StudentsData[i].fio << endl;
}