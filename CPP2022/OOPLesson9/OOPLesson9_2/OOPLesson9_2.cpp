// //Функциональный объект - функтор
// Лямбда-выражения.

#include <iostream>
#include <string>

using namespace std;

// функтор принимает сообщение и выводит его на экран
class PrintToScreen
{
public:
    void operator()(const std::string& message) const
    {
        std::cout << message << std::endl;
    }
};

class Square
{
public:
    int operator()(int x) const
    {
        return x * x;
    }
};


class Сondition
{
private:
    unsigned x{};

public:
    unsigned operator()()
    {
        return ++x;
    }
};


int main()
{
    //std::cout << "Hello World!\n";
    PrintToScreen print;
    print("Hello World!\n");
    
    Square sqr;
    int result{sqr(2)}; //Инициализируем переменную значением функтора
    print(to_string(result));

    print(to_string(sqr(5))); //вызываем функтор как функцию
    
    Сondition z;

    print(to_string(z())); //вызываем функтор как функцию
    print(to_string(z())); //вызываем функтор как функцию
    print(to_string(z())); //вызываем функтор как функцию

    
}

