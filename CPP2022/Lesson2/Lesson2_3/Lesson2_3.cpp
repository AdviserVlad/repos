//ФУНКЦИИ

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

/* инициализируем матрицу внутри функции случайными
числами в отличии от обычных переменных изменения
элементов массива, происходящие внутри функции
при выходе из функции сохраняются*/
void initArray2D(int arr[][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 10; // от 0 до 9
        }
    }
}

// отображение массива
void showArray2D(int arr[][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }        
        cout << endl;
    }   
    cout << endl;
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

    const int mRows = 3;
    const int mCols = 3;
    int iMatr[5][5];
    initArray2D(iMatr,mRows,mCols);
    showArray2D(iMatr, mRows, mCols);

}


