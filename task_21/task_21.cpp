#include <windows.h>
#include <iostream>
#include <fstream>

/*Задача 21
Имеются массив записей (50 записей) о студентах группы. Каждая запись
включает следующие данные:
а) ФИО;
6) номер зачетки;
в) отметки по трем предметам;
г) стипендия до сессии;
Определить функцию, параметром которой является массив записей о студентах.
Функция выводит на экран списки записей о студентах, получивших хотя бы
одну тройку. Функцию, возвращает с помощью return освобождающийся
стипендиальный фонд (с оценкой 3 стипендия снимается).
*/

using namespace std;

const int SIZE_ARR = 4;

struct StudentInfo {
    char fio[35];
    unsigned int recordBook;
    int scores[3];
    unsigned int scholarship;
};

void DeleteSpace(char* str) { //  Функция для удаления пробелов
    int x;
    int xLeft = 0,
        xRight = strlen(str) - 1;
    while (str[xLeft] == ' ') xLeft++;
    while (str[xRight] == ' ') xRight--;
    for (x = xLeft; x <= xRight; x++)
        str[x - xLeft] = str[x];
    str[x - xLeft] = '\0';
}

int FreeUpScholarship(StudentInfo* groupArr) {
    int freeUpFund = 0;
    cout.setf(ios::left);
    cout << "Студенты, которые слетают со стипендии:" << endl;
    for (int i = 0; i < SIZE_ARR; i++) {   // Проходимся по массиву структур
        for (int j = 0; j < 3; j++) {        // Проходимся по массиву с оценками
            if (groupArr[i].scores[j] <= 3) {
                cout << groupArr[i].fio << endl;  
                freeUpFund += groupArr[i].scholarship;
                break;                                  // Если находим хоть одну тройку то выходим из цикла, дальше смысла от прохода уже нету
            }
        }
    }
    return freeUpFund;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    StudentInfo groupArr[SIZE_ARR];

    ifstream fin;
    fin.open("data.txt");

    if (!fin) {
        cout << "[ERROR] File was not opened" << endl;
        exit(0);
    }

    char buff[256];
    int tempArr[3];

    for (int i = 0; i < SIZE_ARR; i++) {
        fin.get(groupArr[i].fio, 35);
        fin >> groupArr[i].recordBook;
        for (int j = 0; j < 3; j++) {
            fin >> groupArr[i].scores[j];
        }
        fin >> groupArr[i].scholarship;
        fin.getline(buff, 100);
        DeleteSpace(groupArr[i].fio);
    }

    cout << "Стипендиальный фонд освободился на " << FreeUpScholarship(groupArr) << " рублей";
}