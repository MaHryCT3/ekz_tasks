#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string.h>


/*Задача 17
Имеется массив записей (70 записей) об абитуриентах факультета. Каждая запись
включает следующие данные:
а) ФИО;
6) номер зачетки;
в) отметки по трем предметам.
Определить функцию, параметром которой является массив записей об
абитуриентах. Функция сортирует и выводит записи об абитуриентах на экран в
порядке убывания его среднего балла.
*/

using namespace std;

const int SIZE_ARR = 4; // Размер массива

struct EnrolleeData {
    char fio[38];
    int recordBook;
    float averageScore;
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

float ConsiderAverageScore(int* Scores) {   // Для вычисления ср. балла.
    int countScores = 3; // Из условий задания
    float averageScore = 0;
    for (int i = 0; i < 3; i++) {
        averageScore += Scores[i];
    }
    return averageScore / countScores;
}

void SortArray(EnrolleeData* enrolleeDataArr) {
    EnrolleeData temp;
    for (int i = 0; i < SIZE_ARR - 1; i++) {
        for (int j = 0; j < SIZE_ARR - i - 1; j++) {
            if (enrolleeDataArr[j].averageScore > enrolleeDataArr[j + 1].averageScore) {
                temp = enrolleeDataArr[j];
                enrolleeDataArr[j] = enrolleeDataArr[j + 1];
                enrolleeDataArr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    EnrolleeData enrolleeDataArr[SIZE_ARR];

    ifstream fin;

    fin.open("data.txt");

    if (!fin) {
        cout << "[ERROR] File was not opened" << endl;
        exit(0);
    }


    int tempArr[3];
    char T[256];

    for (int i = 0; i < SIZE_ARR; i++) {
        fin.get(enrolleeDataArr[i].fio, 38);
        //cout << enrolleeDataArr[i].fio;
        DeleteSpace(enrolleeDataArr[i].fio);
        fin >> enrolleeDataArr[i].recordBook;
        for (int i = 0; i < 3; i++) {
            fin >> tempArr[i];
        }
        enrolleeDataArr[i].averageScore = ConsiderAverageScore(tempArr);
        fin.getline(T, 256);
    }

    SortArray(enrolleeDataArr);

    for (int i = 0; i < 4; i++) {
        cout << enrolleeDataArr[i].fio << '\t' << enrolleeDataArr[i].recordBook << '\t' << enrolleeDataArr[i].averageScore << endl; // Вывод данных
    }
    
}