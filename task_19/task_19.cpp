#include <windows.h>
#include <iostream>
#include <fstream>

/*эедача 19
Имеется массив записей (50 записей) о сотрудниках Кафедры. Каждая запись
включает следующие данные:
а) ФИО;
6) количество полных лет;
в) должность;
д) пол;
Определить функцию, параметром которой является массив записей о
сотрудниках. Функция выводит список пенснонеров кафедры, учитывая, что для
женщин пенсионный возраст —60 лет, а для мужчин — 65. Функция возвращает с
помощью return процент пенсионеров среди сотрудников.
*/

using namespace std;

const int SIZE_ARR = 4;

struct Person {
    char fio[35];
    unsigned int age;
    char role[20];
    char sex;
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

float PercentPensioner(Person* personData) {
    float countPensioners = 0;
    cout << "Пенсионеры кафедры:\n";
    for (int i = 0; i < SIZE_ARR; i++) {
        if (personData[i].age >= 60 && personData[i].sex == 'Ж') {
            cout << personData[i].fio << endl;
            countPensioners++;
        }
        if (personData[i].age >= 65 && personData[i].sex == 'М') {
            cout << personData[i].fio << endl;
            countPensioners++;
        }
    }
    return countPensioners / SIZE_ARR * 100;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Person personData[SIZE_ARR];

    ifstream fin;
    fin.open("data.txt");

    if (!fin) {
        cout << "[ERROR] File was not opened" << endl;
        exit(0);
    }

    char buff[256];

    for (int i = 0; i < SIZE_ARR; i++) {
        fin.get(personData[i].fio, 35);
        fin >> personData[i].age;
        fin.get(personData[i].role, 17);
        fin >> personData[i].sex;
        fin.getline(buff, 100);
        DeleteSpace(personData[i].fio);
        DeleteSpace(personData[i].role);
    }
    
    cout << "\nПроцент пенсионеров на кафедре - " << PercentPensioner(personData) << '%' << endl;

    //for (int i = 0; i < SIZE_ARR; i++) {
    //    cout << personData[i].fio << '\t';
    //    cout << personData[i].age << '\t';
    //    cout << personData[i].role << '\t';
    //    cout << personData[i].sex << endl;
    //}
}