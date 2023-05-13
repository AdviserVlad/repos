// Задание 5:
// В двумерном массиве целых чисел посчитать сумму элементов : в каждой строке; в каждом
// столбце; одновременно по всем строкам и всем столбцам.Оформить следующим образом :
// 3 5 6 7 | 21
// 12 1 1 1 | 15
// 0 7 12 1 | 20
// -------------------- -
// 15 3 19 9 | 56

#include <iostream>
#include <conio.h> 
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    const int COLUMN = 4, STROKE = 4;                            //
    int array[STROKE][COLUMN];                                   //создаем массивы
    int sumStroke = 0, sumColumn = 0, totalsum = 0;              // и назначаем что надо вычислять
                                                                 //
    for (int i = 0; i < STROKE; i++)                             //
    {                                                            //
        cout << "| ";                                            //создаем цикл для выведения строк и столбцов
        for (int j = 0; j < COLUMN; j++)                         // и считаем сразу сумму по строкам
        {                                                        //
            array[i][j] = rand() % (9 - 0 + 1 + 0);              //
                                                                 //
            cout.width(4);                                       //
            sumStroke += array[i][j];                            //
                                                                 //
            cout << array[i][j] << "\t";                        //
        }                                                        //
        totalsum += sumStroke;                                   //  общая сумма строк (нужно в конце программы)
        cout << "|   " << sumStroke << endl << endl << endl;     //
        sumStroke = 0;                                           //
    }                                                            //
                                                                 //
    cout << "--------------------------------------\n\n";        //
                                                                 //
    for (int i = 0; i < STROKE; i++)                             //
    {                                                            //
        for (int j = 0; j < COLUMN; j++)                         // вычисляем суммы по столбцам (меняем местами i и j)
        {                                                        //
            sumColumn += array[j][i];                            //
        }                                                        //
        totalsum += sumColumn;//                              // общая сумма по столбцам
        cout << "   " << sumColumn << "\t";                       //
        sumColumn = 0;                                           //
    }                                                            //
                                                                 //
    cout << " |" << totalsum;                                    //
}

