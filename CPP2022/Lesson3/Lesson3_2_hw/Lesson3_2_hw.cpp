
/*Задача 5.
Функции
Написать функцию, которая определяем является  ли "счастливым" шестизначное число

Это программа-симулятор типичного кондуктора в троллейбусе (с проверкой на "счастливость" билетов)*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>;
using namespace std;

int isHappy(unsigned int num) /*функция для проверки "счастливости" номеров*/
{
	if (num < 100000 || num > 999999)
		return -1;
	return ((num / 100000) + ((num / 10000) % 10) + ((num / 1000) % 10)) == (((num / 100) % 10) + ((num / 10) % 10) + (num % 10));
}

void phraseGenerator() /*функция для генерации типичных фраз*/
{
	const int size = 7;
	string phrases[size] = { " не стоим, проезд оплачивать собираемся?", " быстрее заходим, не задерживаем транспорт.", " вас много, а я одна!", " уступите место женщине"," мелочь - это тоже деньги, где я вам крупные найду? ", " да пройдите вы по салону, тут же свободно!", " хотите быстрее \- вызывайте такси." };
	string passengers[size] = { "Мужчина,", "Девушка,", "Молодой человек,", "Уважаемый,", "Гражданин,", "Так,", "Граждане," };
	cout << passengers[rand() % 7] << phrases[rand() % 7] << endl;
}
void ticketUp(); /*прототип функции для показа верха билета*/
void ticketDown();/*прототип для показа нижней части билета*/
void trolleybusMoving();/*захотелось добавить немного визуала*/

int main()
{
	//srand(time(nullptr));
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	_getch();
	trolleybusMoving();
	cout << "\n\tПРОГРАММА-СИМУЛЯТОР \n      КОНДУКТОРА В ТРОЛЛЕЙБУСЕ\n\n";
	char answer; /*переменная для ввода букв пользователем*/

	do
	{
		cout << "\n(введите любые буквы для продолжения,\n          или q для выхода)\n";
		cin >> answer;
		system("cls");

		if (answer == 'q')
		{
			cout << "\nЯ ВАС СЕЙЧАС ВЫСАЖУ!\n\n\n";
			break;
		}

		int number = (rand() % 1000000 + 99999);
		cout << "\n   Ваш билетик\n";
		Sleep(1000);
		ticketUp();
		cout << number;
		ticketDown();

		int res = isHappy(number);
		if (res == 1)
			cout << "\nСчастливый, повезло!\n" << endl;
		else if (res == 0)
			cout << "\n   Несчастливый." << endl;
		cout << "Кто еще без билетика? \n" << endl;
		phraseGenerator();
	} while (answer != 'q');

	return 0;
}
void ticketUp()
{
	cout << ".______________.\n";
	cout << "|              |\n";
	cout << "| ООО ЧелябГЭТ |\n";
	cout << "|              |\n";
	cout << "|              |\n";
	cout << "|     БИЛЕТ    |\n";
	cout << "|              |\n";
	cout << "|  троллейбус  |\n";
	cout << "|              |\n";
	cout << "|              |\n|    ";
}

void ticketDown()
{
	cout << "    |\n";
	cout << "|              |\n";
	cout << "|    23 руб.   |\n";
	cout << "|              |\n";
	cout << "|______________|\n";
}
void trolleybusMoving()
{
	cout << "\n\t\t\t\t\t\t    / / " << endl;
	cout << "\t\t\t\t\t\t  / / " << endl;
	cout << "\t\t\t\t\t\t/ / " << endl;
	cout << "\t\t\t\t\t  _____ПППП__________ " << endl;
	cout << "\t\t\t\t\t |   |   |     |     |" << endl;
	cout << "\t\t\t\t\t о___/___|_____|_____|" << endl;
	cout << "\t\t\t\t\t |__//\\\\_|_____|//\\\\_|" << endl;
	cout << "\t\t\t\t\t    \\\\//        \\\\//" << endl;
	Sleep(500);
	system("cls");

	cout << "\n\t\t\t\t    / / " << endl;
	cout << "\t\t\t\t  / / " << endl;
	cout << "\t\t\t\t/ / " << endl;
	cout << "\t\t\t  _____ПППП__________ " << endl;
	cout << "\t\t\t |   |   |     |     |" << endl;
	cout << "\t\t\t о___/___|_____|_____|" << endl;
	cout << "\t\t\t |__//\\\\_|_____|//\\\\_|" << endl;
	cout << "\t\t\t    \\\\//        \\\\//" << endl;
	Sleep(500);
	system("cls");
	cout << "\n\t\t    / / " << endl;
	cout << "\t\t  / / " << endl;
	cout << "\t\t/ / " << endl;
	cout << "\t  _____ПППП__________ " << endl;
	cout << "\t |   |   |     |     |" << endl;
	cout << "\t о___/___|_____|_____|" << endl;
	cout << "\t |__//\\\\_|_____|//\\\\_|" << endl;
	cout << "\t    \\\\//        \\\\//" << endl;
}