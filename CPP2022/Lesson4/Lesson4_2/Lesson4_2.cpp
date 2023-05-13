// Указатели и Массивы 2
// Указатели и Функции

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

// подсчёт суммы элементов массива
int getAmount(int* ptr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++, ptr++) {
        sum += *ptr;
    }
    return sum;
}

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << x << " - " << y << endl;
}

void swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    cout << *px << "  " << *py << endl;
}




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    const int size = 5;
    int arr[size] = { 33, 44, 7, 8, 9 };

    // записываем адрес нулевого элемента массива
    // в указатель
    int* ptr = arr;
    /* отображаем весь массив через указатель
    на экране 33 44 7 8 9
    */
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " "; // ptr[i]
    }
    cout << endl;

    cout << "Сумма элементов : " << getAmount(arr, size) << endl;

    // изменяем значение первого элемента
    *(ptr + 1) = 55;

    // изменяем значение второго элемента
    *(ptr + 2) = 12;

    cout << endl << endl;
    /* отображаем весь массив через указатель
    на экране 33 55 12 8 9
    */
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    cout << "Сумма элементов : " << getAmount(ptr, size) << endl;

    cout << endl;

    swap((ptr + 1), (ptr + 3));

    swap(&ptr[4], &ptr[0]); // передача по значению лечится &


    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;


}
