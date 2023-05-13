// Указатель — это переменная, содержащая адрес другой переменной. Указатели очень широко используются
//в языке C++.С помощью указателей вы можете обращаться к ячейкам оперативной памяти.Для этого вам нужно
//знать адрес ячейки.

#include <iostream>
#include <time.h>
#include <windows.h>


using namespace std;


int main()
{
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int a = 1;
    int b = 2;

    int* px; //указатель на тип ИНТ.
    int* py;

    px = &a; // взятие адреса, не можем брать адрес &3  &(a-1) 
    b = *px; // разыменовывание = b=a

    int** pz;

    int y = *px + 1; // 2

    cout << px << " : " << *px << endl;
    cout << y << endl;

    *px = 7;
    cout << a << endl;
    *px += 2;
    cout << a << endl;

    py = px;
    cout << py << " : " << *py << endl;

    py = &y;
    cout << py << " : " << *py << endl;


    // Указатели и массивы.

    int arr[10];
    int* parray;
    int x;

    parray = &arr[0];
    x = *parray;
    // *(parray+i) равносильно arr[i]   arr*(parray+i)  *(arr+i)

    parray = arr;
    parray[4] = 3;


}


