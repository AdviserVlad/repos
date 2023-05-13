// Типы данных. Переменные.

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    system("cls");

    setlocale(LC_ALL, "Rus");

    int a = 327;
    int aa;
    aa = 678;
    int Int = 67; //можно но не желательно
    int ЦелоеЧисло = 87; //можно но не желательно
    unsigned int ua = -1124134234;
    int* pa = &a;
    short b = 2;
    float c = 227.3;
    bool d = false;
    char symbol = 'a';
    char endString = '\n'; // эта последовательность - 1 символ

    const int DAYSinWEEK = 7;
    const double PI = 3.14159;

    string str = "какая-то строка";

    int E { 22 }; // Унифицированная инициализация

    cout << "Сейчас будет показана переменная тип bool: " << d << endl;
    cout << "DAYSinWEEK = " << DAYSinWEEK << endl;
    cout << "DAYSinWEEK = " << DAYSinWEEK << "Число Пи = " << PI << endl;
    
    cout << endString << str << endl;

    int aaa;
    cout << "Введите целое число: ";
    cin >> aaa;
    cout << endl;

    //system("pause");


}

