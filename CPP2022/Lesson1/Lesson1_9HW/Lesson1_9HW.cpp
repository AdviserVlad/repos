// Решение каждой задачи реализовано в отдельной функции. "Дано" задачи прописано в первом cout-е

#include <iostream>
#include <Windows.h>
#include <string> 

using namespace std;
const int SIZE_ARRAY20 = 20;
const int SIZE_ARRAY10 = 10;
const int SIZE_ARRAY5 = 5;
const int MONTHS_IN_A_YEAR = 12;

// Функция printMonth - для задачи 2.
std::string printMonth(int month)
{
    switch (month)
    {
    case(0):    return "январь";
    case(1):    return "февраль";
    case(2):    return "март";
    case(3):    return "апрель";
    case(4):    return "май";
    case(5):    return "июнь";
    case(6):    return "июль";
    case(7):    return "август";
    case(8):    return "сентябрь";
    case(9):    return "октябрь";
    case(10):   return "ноябрь";
    case(11):   return "декабрь";
    }
}



// Задание 1.
void task1()
{
    cout << "Задание 1. В одномерном массиве, заполненном случайными числами, определить\n"
        << "минимальный и максимальный элементы.\n" << endl;

    int array[SIZE_ARRAY20];
    int arrayMin, arrayMax, counter = 0;

    cout << "Текущий объём массива - 20 значений. Диапазон чисел - от 10 до 100. Для проверки\n"
        << "корректного определения предельных значений выведем весь массив по порядку и следом пределы:\n\n";

    for (int i = 0; i < SIZE_ARRAY20; i++)
    {
        array[i] = rand() % (100 - 10 + 1) + 10;
        cout << array[i] << "\t";
        if (i == 0)
        {
            arrayMin = array[0];
            arrayMax = array[0];
        }
        counter++;
        if (counter % 10 == 0)
        {
            cout << endl;
        }

        if (array[i] > arrayMax)
        {
            arrayMax = array[i];
        }

        if (array[i] < arrayMin)
        {
            arrayMin = array[i];
        }
    }

    cout << "Минимальное значение в массиве - " << arrayMin
        << "\nМаксимальное значение в массиве - " << arrayMax << endl;

    cout << "\n*********************************************************************************************\n" << endl;
    cin.ignore(32767, '\n');
}


// Задание 2.
void task2()
{
    cout << "Задание 2: Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь\n"
        << "вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо определить\n"
        << "месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с\n"
        << "учетом выбранного диапазона.\n" << endl;

    // Заполняем данные о прибыли
    int income[MONTHS_IN_A_YEAR];
    cout << "Заполните данные о прибыли за каждый месяц (с точностью до рублей):\n";

    for (int i = 0; i < MONTHS_IN_A_YEAR; i++)
    {
        cout << "Прибыль за " << printMonth(i) << ": ";
        cin >> income[i];
    }

    // Определяем диапазон вычисления MAX и MIN заработка
    int firstMonth, lastMonth, monthOfIncomeMAX, monthOfIncomeMIN, incomeMAX, incomeMIN;

    cout << "Теперь давайте выявим наибольшую и наименьшую прибыль в необходимом промежутке времени.\n";
    while (1)
    {
        "Введите номера первого и последнего месяцев диапазона (через Пробел): ";
        cin >> firstMonth >> lastMonth;
        if (firstMonth < lastMonth)
        {
            break;
        }
        cout << "Некорректый ввод. Попробуйте ещё раз.\n" << endl;
    }

    // Пользователь вводит числа месяца от 1 до 12, а счёт у на от 0 до 11, поэтому уменьшаем значения на 1.
    monthOfIncomeMAX = --firstMonth;
    monthOfIncomeMIN = --lastMonth;

    // Вычиляем MAX и MIN в заданном диапазоне
    incomeMAX = income[firstMonth];
    incomeMIN = income[lastMonth];

    for (int i = firstMonth; i <= lastMonth; i++)
    {
        if (incomeMAX < income[i])
        {
            incomeMAX = income[i];
            monthOfIncomeMAX = i;
        }
        if (incomeMIN > income[i])
        {
            incomeMIN = income[i];
            monthOfIncomeMIN = i;
        }
    }

    cout << "Наибольшая прибыль в диапазоне \"" << printMonth(firstMonth) << " - " << printMonth(lastMonth) << "\" выручена за " << printMonth(monthOfIncomeMAX) << ".\n";
    cout << "Наименьшая прибыль в диапазоне \"" << printMonth(firstMonth) << " - " << printMonth(lastMonth) << "\" выручена за " << printMonth(monthOfIncomeMIN) << ".\n";

    cout << "\n*********************************************************************************************\n" << endl;

    cin.ignore(32767, '\n');
}


// Задание 3.
void task3()
{
    cout << "Задание 3: В одномерном массиве, состоящем из N вещественных чисел вычислить:\n"
        << " - Сумму отрицательных элементов.\n"
        << " - Произведение элементов, находящихся между min и max элементами.\n"
        << " - Произведение элементов с четными номерами.\n"
        << " - Сумму элементов, находящихся между первым и последним отрицательными элементами.\n" << endl;

    cout << "Текущий объём массива N - 20 значений. Диапазон чисел - от -10 до 10. Для проверки\n"
        << "корректной работы программы сначала выведем весь массив, а следом - решение подзадач:\n\n";

    int array[SIZE_ARRAY20];
    int indexArrayMin, indexArrayMax, firstNegativeElementIndex = 0, lastNegativeElementIndex = 0, counter = 0, negativeState = 0;


    for (int i = 0; i < SIZE_ARRAY20; i++)
    {
        // Заполняем массив случайными числами
        array[i] = rand() % (10 - (-10) + 1) + (-10);
        // При первой итерации определяем МАХ, MIN первым значением массива
        if (counter == 0)
        {
            indexArrayMin = i;
            indexArrayMax = i;
        }
        // Выводим массив на экран для контроля правильности выполнения кода
        cout << array[i] << "\t";
        counter++;
        if (counter % 10 == 0)
        {
            cout << endl;
        }

        // Определяем индексы крайних элементов с отрицательными значениями. если такой элемент 1, то он запомнится и как первый, и как последний.
        if (array[i] < 0 && negativeState == 0)
        {
            firstNegativeElementIndex = i;
            negativeState = 1;
        }
        if (array[i] < 0)
        {
            lastNegativeElementIndex = i;
        }

        // Определяем МАХ и MIN
        if (array[indexArrayMax] < array[i])
        {
            indexArrayMax = i;
        }
        if (array[indexArrayMin] > array[i])
        {
            indexArrayMin = i;
        }

    }


    // Считаем и выводим сумму всех отрицательных чисел массива
    int sumOfNegative = 0;
    for (int i = 0; i < SIZE_ARRAY20; i++)
    {
        if (array[i] < 0)
        {
            sumOfNegative += array[i];
        }
    }

    cout << "\nСумма отрицательных элементов массива равна " << sumOfNegative << ".\n" << endl;

    // Считаем произведение всех чисел массива между MIN и MAX.
    long long int multiplicationInRange = 1;
    if (indexArrayMax < indexArrayMin)
    {
        swap(indexArrayMax, indexArrayMin);
    }

    for (int i = indexArrayMin; i <= indexArrayMax; i++)
    {
        multiplicationInRange *= array[i];
    }
    cout << "Произведение элементов массива в диапазоне от " << array[indexArrayMin] << " до " << array[indexArrayMax]
        << " составляет " << multiplicationInRange << ".\n" << endl;

    // Считаем произведение всех чисел массива с чётным индексом.
    long int multiplicationOfEvenElements = 1;
    for (int i = 0; i < SIZE_ARRAY20; i++)
    {
        if (i % 2 == 0)
        {
            multiplicationOfEvenElements *= array[i];
        }
    }
    cout << "Произведение всех элементов массива с чётными номерами составляет " << multiplicationOfEvenElements << ".\n" << endl;

    // Считаем сумму элементов между первым и последним элементами с отрицательными числами.
    int sumOfNegativeInRange = 0;
    if (negativeState == 0)
    {
        cout << "В массиве нет отрицательных чисел.\n" << endl;
    }
    else
    {
        for (int i = firstNegativeElementIndex; i <= lastNegativeElementIndex; i++)
        {
            sumOfNegativeInRange += array[i];
        }
        cout << "Сумма элементов в диапазоне от элемента с индексом " << firstNegativeElementIndex << " до элемента с индексом " << lastNegativeElementIndex
            << " равна " << sumOfNegativeInRange << ".\n" << endl;
    }

    cout << "\n*********************************************************************************************\n" << endl;

}


// Задание 4.
void task4()
{
    cout << "Задание 4: Написать программу, копирующую последовательно элементы одного массива размером 10\n"
        << "элементов в 2 массива размером 5 элементов каждый.\n" << endl;

    int array10[SIZE_ARRAY10], array5_1[SIZE_ARRAY5], array5_2[SIZE_ARRAY5];
    cout << "Для начала заполним массив из 10 элементов и выведем его на экран. Диапазон - от 50 до 100\n"
        << "После этого скопируем элементы в массивы по 5 элементов и выведем их друг за другом.\n" << endl;

    cout << "Массив из 10 чисел:\n";
    for (int i = 0; i < SIZE_ARRAY10; i++)
    {
        array10[i] = rand() % (100 - 50 + 1) + 50;
        cout << "#" << i << " - " << array10[i] << endl;
    }

    for (int i = 0, j = SIZE_ARRAY10 / 2; (i < SIZE_ARRAY10 / 2) || (j < SIZE_ARRAY10); i++, j++)
    {
        array5_1[i] = array10[i];
        array5_2[i] = array10[i+5];
    }

    cout << "\nПервый массив чисел из 5 элементов:\n";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        cout << "#" << i << " - " << array5_1[i] << endl;
    }

    cout << "\nВторой массив чисел из 5 элементов:\n";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        cout << "#" << i << " - " << array5_2[i] << endl;
    }

    cout << "\n*********************************************************************************************\n" << endl;

}


// Задание 5.
void task5()
{
    cout << "Задание 5: Напишите программу, которая выполняет поэлементную сумму двух массивов и результат\n"
        << "заносит в третий массив.\n" << endl;

    cout << "Результат выполнения программы выведем в виде таблицы, где Массив 3 содержит\n"
        << "значения поэлементого сложения Массивов 1 и 2. Массив 1 содержит числа от 10 до 20, массив 2 - от 20 до 40.\n" << endl;

    int summands1[SIZE_ARRAY5], summands2[SIZE_ARRAY5], sum[SIZE_ARRAY5];
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        summands1[i] = rand() % (20 - 10 + 1) + 10;
        summands2[i] = rand() % (40 - 20 + 1) + 20;
    }

    cout << "\n---------------------------------------------------------------------------------------------------------\n";
    cout << "|   Массивы\\Индексы\t|";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        cout << "\t" << i << "\t|";
    }

    cout << "\n---------------------------------------------------------------------------------------------------------\n";
    cout << "|    \tМассив 1    \t|";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        cout << "\t" << summands1[i] << "\t|";
    }

    cout << "\n---------------------------------------------------------------------------------------------------------\n";
    cout << "|\tМассив 2\t|";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        cout << "\t" << summands2[i] << "\t|";
    }

    cout << "\n---------------------------------------------------------------------------------------------------------\n";
    cout << "|\tМассив 3\t|";
    for (int i = 0; i < SIZE_ARRAY5; i++)
    {
        sum[i] = summands1[i] + summands2[i];
        cout << "\t" << sum[i] << "\t|";
    }
    cout << "\n---------------------------------------------------------------------------------------------------------\n";

    cout << "\n*********************************************************************************************\n" << endl;

}


int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    cout << "Данная программа выводит в консоль решение заданий: либо одно по выбору, либо все попорядку.\n"
        << "Для начала работы введите цифру соответствующего задания (т.е. от 1 до 5),\n"
        << "либо 0 для запуска всех программ по порядку.\n\n";

    short userChoice;
    char desireToContinue;
    do
    {
        while (1)
        {
            cout << "Введите цифру от 0 до 5: ";
            cin >> userChoice;
            if (userChoice >= 0 && userChoice <= 5)
            {
                break;
            }
            cout << "Некорректный ввод. Повторите попытку.\n" << endl;

        }
        switch (userChoice)
        {
        case(0):
            system("cls");
            task1();
            cout << "Для продолжения работы введите клавишу Enter... ";
            getchar();

            cout << endl;
            task2();
            cout << "Для продолжения работы введите клавишу Enter... ";
            getchar();

            cout << endl;
            task3();
            cout << "Для продолжения работы введите клавишу Enter... ";
            getchar();

            cout << endl;
            task4();
            cout << "Для продолжения работы введите клавишу Enter... ";
            getchar();

            cout << endl;
            task5();
            cout << "Для продолжения работы введите клавишу Enter... ";
            getchar();
            break;
        case(1):
            system("cls");
            task1();
            break;
        case(2):
            system("cls");
            task2();
            break;
        case(3):
            system("cls");
            task3();
            break;
        case(4):
            system("cls");
            task4();
            break;
        case(5):
            system("cls");
            task5();
            break;
        }
        cout << "Хотите запустить ещё раз?(Y/N): ";
        cin >> desireToContinue;
    } while (desireToContinue == 'Y' || desireToContinue == 'y');

    cout << "До новых встреч! :)\n" << endl;
}
