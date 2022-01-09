#include <windows.h>
#include <iostream>
#include <fstream>

/*Задача 16

Имеется месячные данные о 200 телефонных разговорах, загруженные в массив
структур. Данные включают:
1) ФИО абонента;
2) номер телефона (целое значение);
3) адрес абонента.
Определить функцию, параметром которой является массив структур о звонках.
Функция сортирует и выводит записи на экран в порядке возрастания числового
значения номера телефона.
*/

using namespace std;

const int SIZE_ARR = 4; // Размер массива

struct CallData {
    char fio[30];
    long long phoneNumber;
    char adress[30];
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

void SortArray(CallData *dataArr) {
    CallData temp;
    for (int i = 0; i < SIZE_ARR - 1; i++) {
        for (int j = 0; j < SIZE_ARR - i - 1; j++) {
            if (dataArr[j].phoneNumber > dataArr[j + 1].phoneNumber) {
                temp = dataArr[j];
                dataArr[j] = dataArr[j + 1];
                dataArr[j + 1] = temp;
            }
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CallData callDataArr[SIZE_ARR];

    ifstream fin;

	fin.open("data.txt");

	for (int i = 0; i < 4; i++){
		fin.get(callDataArr[i].fio, 30);
		DeleteSpace(callDataArr[i].fio);
		fin >> callDataArr[i].phoneNumber;
		fin.getline(callDataArr[i].adress, 30);
		DeleteSpace(callDataArr[i].adress);
	}

    SortArray(callDataArr);


	for (int i = 0; i < 4; i++) {
		cout << callDataArr[i].fio << '\t' << callDataArr[i].phoneNumber << '\t' << callDataArr[i].adress << endl; // Вывод данных
	}
}