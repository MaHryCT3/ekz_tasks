#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

/*Задача 20
Имеются массив записей (50 записей) о студентах группы. Каждая запись
включает следующие данные:
а) ФИО;
6) номер зачетки;
в) отметки по трем предметам;
г) стипендия до сессии;
Определить функцию, параметром которой является массив записей о
студентах. Функция выводит список студентов в формате:
ФИО стипендия после сессии.
Учитывать правило начисления стипендией:
стипендия отличника — 2600р.
стипендия студентов, успевающих на 4 и 5 - 1600р.
стипендия студента, получившего хотя бы одну тройку - 0 р. (<=3)
Функцию, возвращает с помощью return изменение стипенднального фонда
группы.
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

int ChangeScholarshipFund(StudentInfo* groupArr) {
    int newScholarashipLevel;  // 0  - без стипендии; 1 - 1600 рублей; 2 - 2600 рублей
    int changeFund = 0;        // изменение стипенднального фонда группы
    cout << "ФИО Ученика\t\t\t||Стипендия после сессии" << endl;
    for (int i = 0; i < SIZE_ARR; i++) {   // Проходимся по массиву структур
        newScholarashipLevel = 2600;
        for (int j = 0; j < 3; j++) {        // Проходимся по массиву с оценками
            if (groupArr[i].scores[j] == 4 && newScholarashipLevel == 2600) newScholarashipLevel = 1600;
            if (groupArr[i].scores[j] <= 3) newScholarashipLevel = 0;
        }
        changeFund -= groupArr[i].scholarship - newScholarashipLevel;    // считаем изменение фонда
        cout.setf(ios::scientific);
        cout.setf(ios::left);
        cout << setw(25) << groupArr[i].fio;
        cout.unsetf(ios::left);
        cout << setw(9) << "||" << newScholarashipLevel << " рублей" << endl;
    }
    return changeFund;
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

    cout << "Cтипенднальный фонда группы изменился на " << ChangeScholarshipFund(groupArr);
    
    //for (int i = 0; i < SIZE_ARR; i++) {
    //    cout << groupArr[i].fio << '\t';
    //    cout << groupArr[i].recordBook << "\t";
    //    for (int j = 0; j < 3; j++) {
    //        cout << groupArr[i].scores[j] << ' ';
    //    }
    //    cout << groupArr[i].scholarship << endl;
    //}
}