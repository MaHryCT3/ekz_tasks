#include <windows.h>
#include <iostream>

/*Задача 27

Написать рекурсивную функцию (не использовать циклов) для
многократного вывода символьной строки. Строка — параметр функции.

В main ‚ используя эту функцию!10 раз вывести на экран произвольную фразу.

*/

using namespace std;

char ShowStrings(char *phrase, int count) {
    if (count - 1 > 0) {
        cout << phrase << endl;
        return ShowStrings(phrase, count - 1);
    }
    else {
        cout << phrase;
        return 0;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char phrase[] = "[eq pfkegf xkty";

    ShowStrings(phrase, 10);

}