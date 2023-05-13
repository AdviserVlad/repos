// МАССИВЫ
//  тип_данных имя_массива[количество_элементов];
//  базовый адрес + размер базового типа * индекс;
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a1, a2, a3, a4, a5;
    const int SIZE = 5;


    int numbers[SIZE] = {1,2,3}; //numbers[5] {1,2,3,0,0}
    //numbers[0] = 1;
    //numbers[1] = 2;
    //numbers[2] = 3;
    //numbers[3] = 4;
    //numbers[4] = 5;
    //numbers[5] = 1; // плохая идея выйти за границу массива

    int numbers2[] = {1000,20000,34500,49090,5909};
    short numbers3[] = { 1,2,3 }; // будет массив на 3 элемента
                                //(при неуказанной размерности)

    int train[SIZE] { 2,20,25,15,8 };

    cout << "Начальный адрес: " << train << endl;
    cout << "Значение переменных (количество человек в вагонах): " << endl;
    cout << "train[0] " << train[0] << endl;
    cout << "train[1] " << train[1] << endl;
    cout << "train[2] " << train[2] << endl;
    cout << "train[3] " << train[3] << endl;
    cout << "train[4] " << train[4] << endl;
    cout << "train[5] " << train[5] << endl; // так делать не хорошо. :)

    cout << endl;
    
    // Инициализация с помощью цикла
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Введите количество человек в вагоне №" << i + 1 << " : ";
        cin >> train[i];
    }
    cout << endl;
    
    // Вывод на экран в цикле
    int sum = 0;
    cout << "Количество человек в вагонах : " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Количество человек в вагоне №" << i + 1 << " : " << train[i];
        sum += train[i]; //sum = sum + train[i];
        
        cout << endl;
    }
    cout << "Количество человек в поезде : " << sum;

    system("pause");
    return 0;

}



