#include <iostream>
#include<Windows.h>
#include<ctime>

using namespace std;
#include"single-connected List.h"

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List<int> a;
    int value, index;

    for (int i = 0; i < rand()%10 + 1; i++)
    {
        a.push_back(rand() % 10);
    }

    cout << "Кількість елементів в списку: " << a.Get_Size() << endl << endl;

    cout << "Виведення списку:" << endl;
    a.PRINTLIST();

    cout << "Введіть елемет та його індекс який хочете вставити у список: ";
    cin >> value >> index;
    a.INSERT(value, index);

    cout << "Виведення списку:" << endl;
    a.PRINTLIST();

    cout << "Введіть елемент позицію якого хочете знайти: ";
    cin >> value;
    cout << "Позиція елемента: " << a.LOCATE(value) << endl;

    cout << "Введіть індекс елемета який хочете знайти: ";
    cin >> index;
    cout << "Елемент: " << a.RETRIEVE(index) << endl << endl;

    cout << "Введіть індекс елемета який хочете видалити: ";
    cin >> index;
    a.data_DELETE(index);

    cout << "Виведення списку:" << endl;
    a.PRINTLIST();

    return 0;
}
//- MAKENULL(створює порожній список) +
//
//- END(повертає кінець списку)
//
//- FIRST(повертає початок списку)
//
//- INSERT(додає елемент до списку в задану позицію) +
//
//- DELETE(видаляє елемент з списку) + 
//
//- LOCATE(знаходить позицію елементу в списку) + 
//
//- RETRIEVE(повертає значення елементу списку) + 
//
//- NEXT(повертає вказівник на наступний елемент списку)