// Функторы - функциональные объекты
// специализированный вид классов, которые включают
// в себя перегруженный оператор вызова функции
// 
// Предикат - специальная функция, которая возвращает 
// логическое значение(true либо false).
// 
// Алгоритмы
// reverse() — меняет порядок следования элементов на обратный;
// random_shuffle() — перемещает элементы согласно случайному 
// равномерному распределению(«тасует» последовательность);
//  

#include <iostream>
#include <algorithm>
#include <windows.h>
#include <list>  //библиотека контейнера списка

using namespace std;

//Функциональный объект, содержащий два поля :
//1. для хранения значения приращения(delta)
//2. для текущего значения генерируемого числа(current)
class addNumberFrom
{
    int delta;   // приращение
    int current; // текущее значение

public:
    addNumberFrom(int number, int from = 0) :
        delta{ number },
        current{ from } {}

    int operator()()
    {
        return current += delta;
    }
};

//предикат
bool isEven(int num)
{
    return !bool(num % 2);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Таблица умножения" << endl;

    for (int i = 1; i <= 10; i++)
    {
        //Cоздание контейнера-списка.
        list<int> row(10);

        generate_n(row.begin(), row.size(), addNumberFrom(i));

        copy(row.begin(), row.end(),
            ostream_iterator<int>(cout, "\t"));
        cout << endl;
    }


    cout << "\n Работа предиката" << endl;
    cout << endl << endl;
    list<int> numbers;
    list<int>::iterator t;
    for (int i = 1; i <= 10; i++)
        numbers.push_back(i);

    copy(numbers.begin(), numbers.end(),
        ostream_iterator<int>(cout, "\t"));
    cout << endl << endl;

    t = remove_if(numbers.begin(), numbers.end(), isEven);
    // после работы алгоритма вернется 
    // итератор на конец области неудаленных значений
    copy(numbers.begin(), t,
        ostream_iterator<int>(cout, "\t"));

}
