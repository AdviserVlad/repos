// "Быстрая" сортировка +
// Двоичный поиск
//

#include <iostream>
#include <windows.h>

using namespace std;
// отображение массива

const int SIZEarr = 10;

void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20 + 1;
    }
}

//Прототип шаблона функции "Быстрой сортировки"
template <typename T, typename L> void  quickSort(T[], L, char type = '<');

// Прототип функции "Бинарный поиск"
int BinarySearch(int Array[], int bgn, int fin, int key, char type);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int array[SIZEarr];
    cout << "---Программа для сортировки массивов!---" << endl;
    initArray(array, SIZEarr);
    showArray(array, SIZEarr);
    char type;   //тип сортировки
    cout << R"(Выберите как отсортировать массив:
< - от меньшего к большему
> - от большего к меньшему
)";
    cin >> type;
    //Быстрая сортировка
    quickSort(array, SIZEarr - 1, type); //Вызов для массива size-1
    showArray(array, SIZEarr);

    int key, result;
    cout << "Введите искомый элемент: "; cin >> key;
    result = BinarySearch(array, 0, SIZEarr, key, type);
    if (result >= 0)
        cout << "Индекс искомого элемента равен: " << result << endl;


}

template<typename T, typename L>
void quickSort(T Array[], L size, char type)
{
    L i = 0, j = size;
    T tmp, cnt;  //буфер и опорный элемент
    cnt = Array[size / 2];
    do
    {
        if (type == '<')
        {
            while (Array[i] < cnt) i++;
            while (Array[j] > cnt) j--;
        }
        else
            if (type == '>')
            {
                while (Array[i] > cnt)i++;
                while (Array[j] < cnt)j--;
            }
            else
            {
                cout << "Неверный выбор типа сортировки!" << endl;
                return;
            }
        if (i <= j)
        {
            tmp = Array[i];
            Array[i] = Array[j];
            Array[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    showArray(Array, SIZEarr);
    if (j > 0) quickSort(Array, j, type);
    //Array+i сдвиг "начала массива" на i элементов
    if (size > i) quickSort(Array + i, size - i, type);

}


//Функция "Бинарный поиск"
int BinarySearch(int Array[], int bgn, int fin, int key, char type)
{
    int cnt;
    //while (1)
    //{

        cnt = (bgn + fin) / 2; //индекс центрального элемента отрезка массива от bgn до fin
        switch (type)
        {
        case '<':
            if (key < Array[cnt]) fin = cnt - 1;
            else
                if (key > Array[cnt]) bgn = cnt + 1;
                else return cnt;
            if (bgn > fin)
            {
                cout << "Искомый элемент не найден!" << endl;
                return -1;
            }
            //break;  // решение через бесконечный цикл
            return BinarySearch(Array, bgn, fin, key, type); // решение с рекурсией

        case '>':
            if (key > Array[cnt])fin = cnt - 1;
            else
                if (key < Array[cnt])bgn = cnt + 1;
                else return cnt;
            if (bgn > fin)
            {
                cout << "Искомый элемент не найден!" << endl;
                return -1;
            }
            //break;
            return BinarySearch(Array, bgn, fin, key, type);
        }




//    }
}