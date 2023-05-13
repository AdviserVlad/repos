// Задание 5:
// Написать функцию, которая определяет, является ли "счастливым" шестизначное число.

#include <iostream>
#include <iomanip>

#define DIGITSUM(X) ((X % 10) + ((X / 10) % 10) + (X / 100))

using namespace std;
// Прототипы функций:
// Запрос номера билета у пользователя
int getNumberOfTicket();

// Проверка билета на "счастливость", т.е. сравнение сумм цифр старшего и младшего разрядов
bool digitsIsEqual(int);

// Мини-функция для подсчёта суммы цифр разряда
inline int getSum(int);

int main()
{
    setlocale(LC_ALL, "RUS");

    cout << "Задание 5: Написать функцию, которая определяет, является ли «счастливым» шестизначное число.\n" << endl;
    cout << "------------------------- Программа для определения счастливого билета. -------------------------\n" << endl;

    cout << "Чтобы проверить, счастливый билет или нет, введите его шестизначный номер: ";

    // Запрашиваем у пользователя номер билета
    int ticketNumber = getNumberOfTicket();

    //Выводим результат проверки на "счастливость"
    if (digitsIsEqual(ticketNumber))
    {
        cout << "\nКак видите, они равны! Поздравляем, Вам достался счастливый билет!\n" << endl;
    }
    else
    {
        cout << "\nУвы, билет не счастливый.\n";
        getchar();
        cout << "Ну и ладно! Повезёт в следующий раз!\n" << endl;
    }
    cout << "\n************************************************************************************************************\n" << endl;
}

// Запрос номера билета у пользователя
int getNumberOfTicket()
{
    int ticketNumber = 0;

    //Если пользователь ввёл не шестизначное число, выводим его сами, добовляя нули, и получаем подтверждение, что всё правильно
    while (1)
    {
        cin >> ticketNumber;

        if (ticketNumber >= 0 && ticketNumber <= 999'999)
        {
            cout << "Номер Вашего билета - ";
            cout << setfill('0') << setw(3) << ticketNumber / 1000 << " " << setfill('0') << setw(3) << ticketNumber % 1000;
            cout << "\nВсё верно? (Y/N):";
            if (cin.get() == 'Y' || cin.get() == 'y')
            {
                cin.ignore(32767, '\n');
                cin.sync();
                return ticketNumber;
            }
        }

        cout << "Некорректный ввод.Попробуйте еёщ раз: ";
        cin.ignore(32767, '\n');
        cin.sync();
    }
}

// Проверка билета на "счастливость", т.е. сравнение сумм цифр старшего и младшего разрядов
bool digitsIsEqual(int ticketNumber)
{
    int highDigitSum = getSum(ticketNumber / 1'000); // Передаём и суммируем цифры старшего разряда
    int lowDigitSum = getSum(ticketNumber % 1'000);  // Передаём и суммируем цифры младшего разряда

    cout << "Cумма чисел страшего разряда равна " << highDigitSum << endl;
    cout << "Сумма чисел младшего разряда равна " << lowDigitSum << endl;

    return (highDigitSum == lowDigitSum);
}

// Мини-функция для подсчёта суммы цифр разряда.
inline int getSum(int number)
{
    return DIGITSUM(number);
    //return (number % 10) + ((number / 10) % 10) + (number / 100);
}