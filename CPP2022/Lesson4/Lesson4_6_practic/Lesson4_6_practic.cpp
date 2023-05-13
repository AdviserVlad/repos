// Даны два массива: А[M] и B[N] (M и N вводятся
//с клавиатуры).Необходимо создать третий массив
//минимально возможного размера, в котором нужно
//собрать элементы обоих массивов.
// 
// 2. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
// Необходимо создать третий массив
//минимально возможного размера, в котором нужно
//собрать элементы массивов A и B, которые не являются 
//общими для них, без повторений.

//4. Дан массив : А[M](M вводится с клавиатуры).Необ -
//ходимо удалить из массива четные или нечетные зна -
//чения.Пользователь вводит данные в массив, а также
//с помощью меню решает, что нужно удалить.

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void showArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void initArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}


void joinArr(int* arr1, int* arr2, int* arr3, int size1, int size2)
{

    for (int i = 0;i < size1;i++)
        arr3[i] = arr1[i];

    for (int i = size1, j = 0;j < size2;i++,j++)
        arr3[i] = arr2[j];

}


void reSizeArray(int* arr1, int &size1)
{
    //Изменяем размер массива, удаляя повторы элементов.


}



void calcMinSize(int* arr1, int* arr2, int size1, int size2, int &size3)
{
    //Считаем минимальный размер для третьего массива.

}






int main()
{
    srand(time(0));

    setlocale(LC_ALL, "Rus");

    int size1 = 0, size2 = 0, size3 = 0;
    int* arr1 = nullptr;
    int* arr2 = nullptr;
    int* arr3 = nullptr;

    size1 = rand() % 10 +1;
    size2 = rand() % 10 +1;

    arr1 = new int[size1];
    arr2 = new int[size2];
    //arr3 = new int[size1+size2];

    if (!arr1 || !arr2 || !arr3)  //необходимо проверить была ли выделена память 
    {
        cout << "ERROR: Ошибка выделения памяти!" << endl;
        exit(0); //выход из программы
    }
    initArray(arr1, size1);
    initArray(arr2, size2);
    cout << "Размер Массива 1 = " << size1 << endl;
    showArray(arr1, size1);
    cout << "Размер Массива 2 = " << size2 << endl;
    showArray(arr2, size2);

    joinArr(arr1, arr2, arr3, size1, size2);
    showArray(arr3, size1+size2);

    if (arr1)
    {
        delete[] arr1;
        arr1 = nullptr;
    }

    if (arr2)
    {
        delete[] arr2;
        arr2 = nullptr;
    }

    if (arr3)
    {
        delete[] arr3;
        arr3 = nullptr;
    }

}

