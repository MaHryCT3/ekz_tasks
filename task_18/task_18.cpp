#include <windows.h>
#include <iostream>
#include <fstream>

/*Задача 13
Имеется массив структур (500 записей) о книгах библиотеки. Каждая запись
включает следующие данные:
а) название книги;
6) автор;
в) год издания;
Г) издательство;
Определить функцию, параметром которой является массив структур о книгах.
Функция сортирует и выводит записи на экран в алфавитном порядке по названию
книги о
*/

using namespace std;

const int SIZE_ARR = 4;

struct BookInfo {
    char bookName[25];
    char author[35];
    int year;
    char publishing[20];
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

void SortArray(BookInfo* libraryData) {
    BookInfo temp;
    for (int i = 0; i < SIZE_ARR - 1; i++) {
        for (int j = 0; j < SIZE_ARR - i - 1; j++) {   // подробнее про strcmp - http://cppstudio.com/post/707/
            if (strcmp(libraryData[j].bookName, libraryData[j + 1].bookName) > 0) {  // сортировка по алфавиту 
                temp = libraryData[j];
                libraryData[j] = libraryData[j + 1];
                libraryData[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BookInfo libraryData[SIZE_ARR];

    ifstream fin;
    fin.open("data.txt");

    if (!fin) {
        cout << "[ERROR] File was not opened" << endl;
        exit(0);
    }

    char buff[256];

    for (int i = 0; i < SIZE_ARR; i++) {
        fin.get(libraryData[i].bookName, 25);
        fin.get(libraryData[i].author, 35);
        fin >> libraryData[i].year;
        fin.getline(libraryData[i].publishing, 256);
        DeleteSpace(libraryData[i].bookName);
        DeleteSpace(libraryData[i].author);
        DeleteSpace(libraryData[i].publishing);
    }

    SortArray(libraryData);
    
    for (int i = 0; i < SIZE_ARR; i++)
        cout << libraryData[i].bookName << '\t' << libraryData[i].author << '\t' << libraryData[i].year << '\t' << libraryData[i].publishing << endl;
}