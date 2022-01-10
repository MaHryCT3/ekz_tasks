#include <windows.h>
#include <iostream>
#include <fstream>

/*Задача 22
Имеется массив записей (500 записей) о книгах отдела книжного магазина.
Каждая запись включает следующие данные:
а) название книги;
6) автор;
в) год издания;
Г) издательство;
Определить функцию, параметром которой является массив записей о
книгах. Функция сортирует и выводит записи на экран в алфавитном порядке по
названию книги, но только книги определенного издательства. Название
издательства передать в функцию через параметр.
*/

using namespace std;

const int SIZE_ARR = 4;

struct BookInfo {
    char bookName[25];
    char author[35];
    unsigned int year;
    char publishing[25];
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

void SortArray(BookInfo* bookStoreData, char publishingName[]) {
    BookInfo temp;
    for (int i = 0; i < SIZE_ARR - 1; i++) {
        for (int j = 0; j < SIZE_ARR - i - 1; j++) {   // подробнее про strcmp - http://cppstudio.com/post/707/
            if (strcmp(bookStoreData[j].bookName, bookStoreData[j + 1].bookName) > 0) {  // сортировка по алфавиту 
                temp = bookStoreData[j];
                bookStoreData[j] = bookStoreData[j + 1];
                bookStoreData[j + 1] = temp;
            }
        }
    }
    cout.setf(ios::left);
    cout << "Книги издательства - " << publishingName << ":\n";
    for (int i = 0; i < SIZE_ARR ; i++) {
        if (strcmp(bookStoreData[i].publishing, publishingName) == 0) {
            cout << bookStoreData[i].bookName << endl;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BookInfo bookStoreData[SIZE_ARR];
    char publisingName[] = "Детская литература";

    ifstream fin;
    fin.open("data.txt");

    if (!fin) {
        cout << "[ERROR] File was not opened" << endl;
        exit(0);
    }

    for (int i = 0; i < SIZE_ARR; i++) {
        fin.get(bookStoreData[i].bookName, 25);
        fin.get(bookStoreData[i].author, 35);
        fin >> bookStoreData[i].year;
        fin.getline(bookStoreData[i].publishing, 256);
        DeleteSpace(bookStoreData[i].bookName);
        DeleteSpace(bookStoreData[i].author);
        DeleteSpace(bookStoreData[i].publishing);
    }

    SortArray(bookStoreData, publisingName);
    //for (int i = 0; i < SIZE_ARR; i++)
    //    cout << bookStoreData[i].bookName << '\t' << bookStoreData[i].author << '\t' << bookStoreData[i].year << '\t' << bookStoreData[i].publishing << endl;
    return 0;
}