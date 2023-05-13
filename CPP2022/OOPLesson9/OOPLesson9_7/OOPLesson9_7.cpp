// Умные указатели.
// https://learn.microsoft.com/ru-RU/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160
// Почитать у Микрософт.

#include <iostream>
#include <memory>

class Xperiment
{
    int a;
    double b;
public:
    bool funcX()
    {
        return false;
    };

    bool funcY()
    {
        return true;
    };

};


void func(std::unique_ptr<Xperiment> a) {};

void func2(Xperiment* a) {};


int main()
{
    Xperiment objX;

    { // это просто область видимости :)
        Xperiment objY;
    } // уничтожится objY

    Xperiment* ptrX = nullptr;
    
    {
        Xperiment* ptrY = new Xperiment();
        ptrX = ptrY;
    } // что произойдет здесь? уничтожится указатель ptrY, объект останется в памяти.

    if (objX.funcX()) //А если вызвать funcY() ?
    {
        bool flag = objX.funcY();
        return 0;
    }

    delete ptrX; //вызовется деструктор, объект уничтожится.


    // unique_ptr Заменяет auto_ptr, использовать который не рекомендуется.
    // 
    // при использовании умного указателя.
    {
        std::unique_ptr<Xperiment> smartPtrX(new Xperiment());

        if (objX.funcX())
        {
            bool flag = objX.funcY();
            return 0;
        }
    }

    // передача уникального указателя в функцию
    auto uptrX = std::make_unique<Xperiment>();

    //func(uptrX);//ошибка. попытка скопировать уникальную штуку!
    func(std::move(uptrX));//переместить уникальную штуку можно.

    func2(uptrX.get()); // получили обычный указатель, передали его в функцию.

    // общий указатель. shared_ptr
    {
        auto sptrX = std::make_shared<Xperiment>();
        {
            auto sptrY = sptrX; // скопировали указатель sptrX в новый указатель.
        }// при выходе из области sptrY уничтожится, но объект в памяти останется.

    }// при выходе из области sptrX и Объект уничтожатся, память освободится.

    return 0;
}// уничтожится objX

