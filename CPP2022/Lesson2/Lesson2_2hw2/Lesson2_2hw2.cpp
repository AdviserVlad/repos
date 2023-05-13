/*
Написать игру «Кубики». Пользователь и ком-
пьютер по очереди бросают 2 кубика. Победитель — тот,
у кого по результатам 3х бросков сумма больше. Преду-
смотреть красивый интерфейс игры.
*/

// ---=== Блок подключения библиотек ===---

#include <Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

void ShowDice(int d1, int d2)
{
	for (int i = 0; i < 5; i++) //Цикл рисования первого и второго кубика игрока в зависимости от значения
	{
		//						0			  1			  2				 3			  4				5
		char dice[][10] = { "*********", "*       *", "*     x *",  "* x   x *", "*   x   *", "* x     *" };

		// Крышка и Донышко
		if (i == 0 || i == 4) { cout << dice[0] << "\t"; }
		if (i == 0 || i == 4) { cout << dice[0] << "\n"; }
		// 1я линия 1й кубик
		if (i == 1 && d1 == 1) { cout << dice[1] << "\t"; } //"*       *\t"
		if (i == 1 && (d1 == 2 || d1 == 3)) { cout << dice[2] << "\t"; } //"*     x *\t";
		if (i == 1 && (d1 == 4 || d1 == 5 || d1 == 6)) { cout << dice[3] << "\t"; } //"* x   x *\t";
		// 1я линия 2й кубик
		if (i == 1 && d2 == 1) { cout << dice[1] << "\n"; }
		if (i == 1 && (d2 == 2 || d2 == 3)) { cout << dice[2] << "\n"; }
		if (i == 1 && (d2 == 4 || d2 == 5 || d2 == 6)) { cout << dice[3] << "\n"; }
		// 2я линия 1й кубик
		if (i == 2 && (d1 == 1 || d1 == 5 || d1 == 3)) { cout << dice[4] << "\t"; } //"*   x   *\t"; 
		if (i == 2 && (d1 == 4 || d1 == 2)) { cout << dice[1] << "\t"; } //"*       *\t";
		if (i == 2 && d1 == 6) { cout << dice[3] << "\t"; } //"* x   x *\t"; 
		// 2я линия 2й кубик
		if (i == 2 && (d2 == 1 || d2 == 3 || d2 == 5)) { cout << dice[4] << "\n"; }
		if (i == 2 && (d2 == 2 || d2 == 4)) { cout << dice[1] << "\n"; }
		if (i == 2 && d2 == 6) { cout << dice[3] << "\n"; }
		// 3я линия 1й кубик
		if (i == 3 && (d1 == 1)) { cout << dice[1] << "\t"; } //"*       *\t"; 
		if (i == 3 && (d1 == 2 || d1 == 3)) { cout << dice[5] << "\t"; } //"* x     *\t";
		if (i == 3 && (d1 == 4 || d1 == 5 || d1 == 6)) { cout << dice[3] << "\t"; } //"* x   x *\t"
		// 3я линия 2й кубик
		if (i == 3 && (d2 == 1)) { cout << dice[1] << "\n"; }
		if (i == 3 && (d2 == 2 || d2 == 3)) { cout << dice[5] << "\n"; }
		if (i == 3 && (d2 == 4 || d2 == 5 || d2 == 6)) { cout << dice[3] << "\n"; }
	}
}

void ShowScore(int arr[][5], int maxThrow)
{
	cout << "  Раунд   | 1 | 2 | 3 | 4 | 5 |\n";
	cout << "-------------------------------\n";
	for (int i = 0; i < 2; i++)
	{
		cout << "Кубик [" << i + 1 << "] |";
		for (int j = 0; j < maxThrow + 1; j++)
		{
			cout << " " << arr[i][j] << " |";
		}
		cout << "\n";
	}
}


int main()

// ---=== Блок объявления переменных ===---
{
	int ThrowHuman[2][5]; // Броски человека
	int ThrowComp[2][5];  // Броски компьютера

	int SumUser = 0; //Сумма очков игрока
	int SumCom = 0; // Сумма очков компьютера

	srand(time(0));
	setlocale(LC_ALL, "Rus");   // Установка русского языка для вывода в консоли

// Здесь будет меню игры

	//cout << "Для броска кубиков нажмите <ПРОБЕЛ> \n";
	//_getch();//system("pause");

	for (int a = 0; a < 5; a++) // Начинаем цикл бросков. Всего три броска
	{
		system("cls");
		cout << "    ---=== Игра КОСТИ. ===---\n";
		cout << "Для броска кубиков нажмите <ПРОБЕЛ> \n";
		(a == 0) ? _getch() : a;//system("pause");

		cout << "Раунд " << a + 1 << "\n";

		// Здесь и ниже присваеваем случайные значения для кубиков игрока и компютера
		ThrowHuman[0][a] = rand() % 6 + 1;
		ThrowHuman[1][a] = rand() % 6 + 1;

		ThrowComp[0][a] = rand() % 6 + 1;
		ThrowComp[1][a] = rand() % 6 + 1;

		SumUser += ThrowHuman[0][a] + ThrowHuman[1][a]; // Считаем суммарное количество очков игрока
		SumCom += ThrowComp[0][a] + ThrowComp[1][a]; // Считаем суммарное количество очков компьютера

		cout << "Ваш бросок: " << endl; //<< ThrowHuman[0][a] << " и " << ThrowHuman[1][a] << endl;
		cout << "У вас " << SumUser << " очков " << endl;

		ShowDice(ThrowHuman[0][a], ThrowHuman[1][a]);

		cout << "Бросок компьютера: " << endl; // << ThrowComp[0][a] << " и " << ThrowComp[1][a]
		cout << "У компа " << SumCom << " очков " << endl;

		ShowDice(ThrowComp[0][a], ThrowComp[1][a]);

		// Показ таблицы результатов
		ShowScore(ThrowHuman, a);
		ShowScore(ThrowComp, a);

		_getch();//system("pause");
	}
	ShowScore(ThrowComp, 4);



	if (SumUser > SumCom) { cout << "Вы победили !\n"; }
	else if (SumUser < SumCom) { cout << "Вы проиграли !\n"; }
	else { cout << "Ничья !\n"; }

	system("pause");
	return 0;
}