// Лямбда-выражения. Анонимные функторы.

#include <iostream>
#include <string>

using namespace std;

// функция принимает в качестве параметра указатель на функцию
void calc(int a, int b, int (*op)(int, int))
{
    std::cout << op(a,b) << std::endl;
}

template<typename T> void calcUni(T a, T b, T (*op)(T, T))
{
    std::cout << op(a, b) << std::endl;
}



int main()
{
    //std::cout << "Hello World!\n";
    // синтаксис лямбды [](параметры) { действия }
    []() { std::cout << "Hello World!\n" << std::endl; }();
    
    auto printNoParam{ []() { std::cout << "Hello World!\n" << std::endl; } };
    printNoParam();

    auto print{ [](const std::string& message) { std::cout << message << std::endl; } };
    print("Hello World!\n");

    auto sqr{ [](int x) { return x * x; } };
    print(to_string(sqr(5)));
    
    // Лямбда, как параметр функции.

    auto sum{ [](int x, int y) { return x + y; } };
    auto sub{ [](int x, int y) { return x - y; } };
    calc(2, 5, sum);
    calc(5, 2, sub);

    calc(12, 6, [](int x, int y) { return x / y; });

    //Универсальные лямбды, когда в параметрах auto или auto&
    auto printUni{ [](const auto& message) { std::cout << message << std::endl; } };
    auto sumUni{ [](auto x, auto y) { return x + y; } };
    printUni(sumUni(2.6, 5.3));
   


}

