//Дан массив из 20 целых чисел со значениями от 1 до 20.
//Необходимо:
//■ написать функцию, разбрасывающую элементы мас -
//сива произвольным образом;
//■ создать случайное число из того же диапазона и найти
//позицию этого случайного числа в массиве;
//■ отсортировать элементы массива, находящиеся сле -
//ва от найденной позиции по убыванию, а элементы
//массива, находящиеся справа от найденной позиции
//по возрастанию.

#include <iostream>
#include <windows.h>

using namespace std;

// отображение массива
void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20 + 1;
    }
}

void randomSort(int arr[], int size)
{
    int randIndex, tmp;
    for (int i = 0; i < size; i++)
    {
        randIndex = rand() % size;
        tmp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = tmp;
        //swap(arr[i], arr[randIndex]); // для ленивых :)
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int SIZE = 10;
    int array[SIZE];
    initArray(array, SIZE);
    showArray(array, SIZE);
    randomSort(array, SIZE);
    showArray(array, SIZE);
    

}

