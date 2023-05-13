//ФУНКЦИИ
// 
// Тип_возвращаемого_значения имя_функции(параметры) 
//{ 
//  
// блок_повторяющегося_кода(тело); 
// return tmp;
//}
// 
// Вызовы функций
// 
// имя_переменной = имя_функции(параметр1, параметр2,...  параметрN);
// c = abs(d);
// d = myFunc(asd, rty);
// 
// void myFunc2(int qwe, char fg);
// 
// myFunc2(we, g);
#include <iostream>
#include <Windows.h>
//#include <time.h>

using namespace std;

void hello()
{
    // показ на экран строки текста    
    cout << "Начнем Игру!!!\n\n";
}

//функция принимает кол-во звездочек в качестве параметра и 
//вывовдит заданнаное кол-во звездочек на экран
void star(int count) //функция принимает 1 параметр, но не возращает результат
{
    //hello();
    for (int i = 0; i < count; i++)
    {
        cout << "*";
    }
    cout << endl;
}

//Выводит линию заданных символов в заданном кол-ве на экран
//функция принимает 2 параметра, но не возращает результат
void lineChar(char symbol, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << symbol;
    }
    cout << endl;
}

//Фунция вычисляет степень Pow числа Digit
int myPow(int digit, int pow) //приминает 2 параметра и возвращает результат типа int
{
    int key = 1; //промежуточный и конечный результат
    for (int i = 0; i < pow; i++)
    {
        key *= digit;
    }
    //cout << a;
    return key;  //оператор возвращающая значение - результат работы функции
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}


// прототипы
void myFunc();
void myFunc2();

// значения по-умолчанию
//void foot(int i, int j = 7); // допустимо foot(10)
////void foot (int i, int j = 2, int k); // недопустимо
//void foot2(int i, int j = 3, int k = 7); // допустимо
//
//void foot(int i = 1, int j = 2, int k = 3); // допустимо
//void foot (int i=- 3, int j); // недопустимо

// Должна менять значения переменных местами 
void change(int a, int b)
{
    // 1 2     
    cout << a << " " << b << "\n\n";
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << "\n\n";// 2 1
}


int a = 10; //глобальная переменная

int main()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    srand(time(NULL));
    hello();
    char key;
    int count;
    
    star(4);
    star(10);

    lineChar('#', 12);

    //cout << "Ввведите символ: "; 
    //cin >> key;
    //cout << "Ввведите кол-во: "; 
    //cin >> count;
    //lineChar(key, count);
    //star(count + 5);

    count = myPow(2, 3);
    cout << "Результат = " << myPow(2, 3);
    cout << "Результат = " << count; // лучше так.

    int a = 1, b = 2;
    cout << a;
    cout << "глобальная a=" << ::a << "\n\n";
    ::a = 45;

    {
        int b = 7;
    }
    cout << "a=" << a << " b=" << b << "\n\n"; // 1 2
    change(a, b);
    cout << "a=" << a << " b=" << b << "\n\n"; // 1 2





}



void myFunc()
{

}

void myFunc2()
{

}