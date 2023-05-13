// МАССИВЫ 2D
// ЗАДАЧИ
// генератор "случайных" чисел rand

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
        
    const int ROW = 5; //строки
    const int COL = 5; //колонки

    int array[ROW][COL];
  
    cout << endl;

    srand(time(NULL));
 
    // Заполнение двумерного массива
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // гсч от -100 до 100
            array[i][j] = rand() % (100 - (-100) + 1) + (-100);
            
        }
    }

    // 
    cout << "Матрица! : " << endl;

    //int max = array[0][0];
    int maxX=0, maxY=0;
    // Вывод на экран двумерного массива
    // поиск максимального элемента
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout.width(4);
            cout << array[i][j] << "\t";
            if (array[maxY][maxX] < array[i][j])
            {
                //max = array[i][j];
                maxX = j;
                maxY = i;
            }
        }
        cout << endl;
    }
    cout << "Максимальный элемент = " << array[maxY][maxX] << endl;
    cout << "Строка = " << maxY << "Столбец = " << maxX << endl;
    cout << "Всего хорошего!" << endl;
    system("pause");
    return 0;


}

