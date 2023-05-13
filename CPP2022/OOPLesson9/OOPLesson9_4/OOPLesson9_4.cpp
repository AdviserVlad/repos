// функции библиотеки Алгоритмов
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <vector>  
#include <ranges>

using namespace std;

bool compare(const int left, const int right)
{
    return left > right; //от большего к меньшему
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9};

    sort(begin(numbers), end(numbers), compare);

    sort(begin(numbers), end(numbers), [](int x, int y) { return x < y; });

    for (const auto num: numbers)
    {
        cout << num << "\t";
    }

    cout << endl;

    std::vector<string> 
        names{ "Маша", "Вася", "Вова", "Петя", "Миша", "Юля", "Катя", "Рома", "Дима" };
    
    //накладываем фильтр на нашу коллекцию. Работает на С++20. и VS2022 :)
    //auto filter_view = std::ranges::filter_view{ names, [](const string& str) { return str.substr(0,1) == "М"; } };

    //Задача: Убрать из коллекции всех, чье имя начинается на "В".
    //auto filter_view = std::ranges::filter_view{ names, 
    //    [](const string& str) { return str.substr(0,1) != "В"; } };

    auto filter_view = remove_if(names.begin(), names.end(),
        [](const string& str) { return (str.substr(0, 1) == "В"); });

    for (const auto name : names)
    {
        cout << name << "\t";
    }
    cout << endl;
    
    // выводим на экран.
    copy(names.begin(), filter_view, ostream_iterator<string>(cout, " "));

    //for (const auto name : filter_view)
    //{
    //    cout << name << "\t";
    //}
    //cout << endl;

}
