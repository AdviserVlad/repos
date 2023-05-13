/*
Дана матрица порядка M×N (M строк, N столб-
цов). Необходимо заполнить ее значениями и написать
функцию, осуществляющую циклический сдвиг строк
и/или столбцов массива указанное количество раз и в ука-
занную сторону.
*/

// ---=== Блок подключения библиотек ===---

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>

using namespace std;

void left(int** arr, int SizeStr, int SizeCol)
{
	int Buf;
	for (int str = 0; str < SizeStr; str++) // Влево
	{
		Buf = arr[str][0]; //Закидываем в буфер первое значение в строчке
		for (int col = 0; col < SizeCol; col++)
		{
			arr[str][col] = arr[str][col + 1]; //Заполняем значение в строчке следующим значением в строчке
		}
		arr[str][SizeCol - 1] = Buf; // Так как крайнему значению в строчке неоткуда брать его следующее число 
	}
}

void right(int** arr, int SizeStr, int SizeCol)
{
	int Buf;
	for (int str = 0; str < SizeStr; str++) // Вправо. Тоже самое, что и влево, только с другого конца.
	{
		Buf = arr[str][SizeCol - 1]; // Закидываем в буфер крайнее значение в строчке
		for (int col = SizeCol - 1; col > 0; col--) //Заходим с конца
		{
			arr[str][col] = arr[str][col - 1]; //Заполняем значение в строчке предыдующим значением в строчке
		}
		arr[str][0] = Buf; //Даем первому числу буферное последнее число
	}
}

void down(int** arr, int SizeStr, int SizeCol)
{
	int Buf;
	for (int col = 0; col < SizeCol; col++) // Вниз. Как вправо, только поменяли местами колонки и строчки 
	{
		Buf = arr[SizeStr - 1][col];
		for (int str = SizeStr - 1; str > 0; str--)
		{
			arr[str][col] = arr[str - 1][col];
		}
		arr[0][col] = Buf;
	}
}

void upp(int** arr, int SizeStr, int SizeCol)
{
	int Buf;
	for (int col = 0; col < SizeCol; col++) // Вверх. Как влево, только поменяли местами колонки и строчки 
	{
		Buf = arr[0][col];
		for (int str = 0; str < SizeStr - 1; str++)
		{
			arr[str][col] = arr[str + 1][col];
		}
		arr[SizeStr - 1][col] = Buf;
	}
}


int main()

// ---=== Блок объявления переменных ===---
{
	srand(time(0));
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	int SizeStr = 4;
	int SizeCol = 6;
	char user;//выбор юзера
	bool flag = true;//флажок выхода

// Решение

	int** arr = new int* [SizeStr];//создаем двумерный динамомассив

	for (int i = 0; i < SizeStr; i++)
	{
		arr[i] = new int[SizeCol];
	}

	cout << "Двигаем цифры вверх, вниз, влево, вправо. Управляем клавишами w a s d (q - выход). ВАЖНО! учитывается язык и регистр\n\n";

	for (int str = 0; str < SizeStr; str++) //Заполняем массивчик случайными значениями от 0 до 9 
	{
		for (int col = 0; col < SizeCol; col++)
		{
			arr[str][col] = rand() % 10;
			cout << arr[str][col] << "  ";
		}
		cout << endl;
	}

	while (flag)
	{

		user = _getch();//Ловим клавишу юзверя

		switch (user)
		{

		case 'a': {left(arr, SizeStr, SizeCol);
			break; }

		case 'd': {right(arr, SizeStr, SizeCol);
			break; }

		case 's': {down(arr, SizeStr, SizeCol);
			break; }

		case 'w': {upp(arr, SizeStr, SizeCol);
			break; }

		case 'q': {flag = false;
			break; }

		default:
			break;
		}

		system("cls");

		cout << "Двигаем цифры вверх, вниз, влево, вправо. Управляем клавишами w a s d (q - выход). ВАЖНО! учитывается язык и регистр\n\n";

		for (int str = 0; str < SizeStr; str++) //смтрим
		{
			for (int col = 0; col < SizeCol; col++)
			{
				cout << arr[str][col] << "  ";
			}
			cout << endl;
		}
	}



	for (int i = 0; i < SizeStr; i++) //прибираемся за собой
	{
		delete[]arr[i];
	}

	delete[]arr;

	system("pause");
	return 0;
}