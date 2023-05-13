// "Быстрая" сортировка
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
