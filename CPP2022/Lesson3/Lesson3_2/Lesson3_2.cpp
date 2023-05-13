// Сортировка выбором
// 4 9 7 6 2 3 (исходная) 
// 2 9 7 6 4 3 (4-2)
// 2 3 7 6 4 9 (9-3)
// 2 3 4 6 7 9 (7-4)
// 2 3 4 6 7 9 (6-6)
// 2 3 4 6 7 9 (7-7)

#include <iostream>
#include <windows.h>

using namespace std;
//Прототип шаблона функции "Сортировки Выбором"
template <typename T, typename L> void selectSort(T[], L, char);
//Прототип шаблона функции "Пузырьковая сортировка"
template <typename T, typename L> void bubbleSort(T[], L, char);
//вспомогательная функция нахождения опорного элемента (мин или макс) и уставноки его в начало массива
template <typename T, typename L> void set(T[], L, char);
//Прототип шаблона функции "Сортировка вставками"
template <typename T, typename L> void insertSort(T[], L, char);
//Прототип шаблона функции "Сортировка Шелла"
template <typename T, typename L> void shellSort(T[], L, char);
//Прототип шаблона функции "Сортировка шейкер"
template <typename T, typename L> void shekerSort(T[], L, char);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    cout << "---Программа для сортировки массивов!---" << endl;
    const int size = 6;
    int array[size]{ 4,9,7,6,2,3 };
    
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (100 - (-100)) - 100;
        cout << "A[" << i << "]=" << array[i] << "; ";
    }
    cout << endl;
    char type;   //тип сортировки
    cout << R"(Выберите как отсортировать массив:
< - от меньшего к большему
> - от большего к меньшему
)"; 
    cin >> type;

    //Сортировка выбором
    //selectSort(array, size, type);
    //Пузырьковая сортировка
    bubbleSort(array, size, type);



    //===== вывод массива =====
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "A[" << i << "]=" << array[i] << "; ";
    }
    cout << endl;

}



//Сортировка выбором
template<typename T, typename L>
void selectSort(T array[],L size,char type)
{
   L i, j, k;  //индексы элементов
   T tmp; //вспомогательный буфер для перестановки элементов
   for (i = 0; i < size; i++)
   {
       k = i;  //для исключения отсортированных элементов
       tmp = array[i];
       for (j = i + 1; j < size; j++)
       {
           if (type == '<')
               if (array[j] < tmp)  //от Мин к Макс
               {
                   k = j;  //запоминаем индекс мин. элемента
                   tmp = array[j]; //запоминаем мин. элемент
               }

           if (type == '>')
               if (array[j] > tmp)  //от Макс к Мин
               {
                   k = j;  //запоминаем индекс макс. элемента
                   tmp = array[j]; //запоминаем макс. элемент
               }
       }
       array[k] = array[i]; //помещаем мин. элемент на текущую позицию
       array[i] = tmp;
   }
}

//Пузырьковая сортировка
template<typename T, typename L>
void bubbleSort(T array[], L size, char type)
{
    L i, j, k;  //индексы элементов
    T tmp; //вспомогательный буфер для перестановки элементов
    for (i = 0; i < size; i++)  //цикл кол-ва проходов по массиву
    {
        k = 0;
        for (j = size - 1; j > i; j--) //цикл манипуляции с элементами массива
        {
            switch (type)
            {
            case '<':               //от Мин. к Макс.
                if (array[j - 1] > array[j])
                {
                    tmp = array[j - 1];            //смена
                    array[j - 1] = array[j];       //элементов
                    array[j] = tmp;                //метсами
                    k++;
                }
                break;
            case '>':               //от Макс. к Мин.
                if (array[j - 1] < array[j])
                {
                    tmp = array[j - 1];            //смена
                    array[j - 1] = array[j];       //элементов
                    array[j] = tmp;                //метсами
                    k++;
                }
                break;
            default: {cout << "Некорректный ввод типа сортировки!" << endl; return; }
            }
        }
        cout << "Шаг " << i << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "A[" << i << "]=" << array[i] << "; ";
        }
        cout << endl;
        if (k == 0)return;  //Была ли смена элементов местами
    }

}
