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

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

// отображение массива
void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* инициализируем массив внутри функции случайными
числами в отличии от обычных переменных изменения
элементов массива, происходящие внутри функции
при выходе из функции сохраняются*/
void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    
}



int main()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    srand(time(NULL));
    
    const unsigned int aSize = 10;
    int iArr[aSize];
    initArray(iArr, aSize);
    showArray(iArr, aSize);


}


