// ЦИКЛЫ
//
// с ПередУсловием
//while (условие)
//{
//    // выполняемые действия
//}

#include <iostream>


using namespace std;

int main()
{
	system("cls");
	setlocale(LC_ALL, "Rus");
	{
		int i = 0;
		cout << " Таблица Умножения \n";

		while (i < 9) // можно (i++<9)
		{
			i++;
			cout << i << " * " << i << " = " << i * i << endl;
		}
	}
	// с ПостУсловием
	// do
	//
	// выполняемые действия
	// 
	//while (условие)
	{

		int i;
		do
		{
			cout << "Введите число от 1 до 3х";
			cin >> i;
		} while (i < 1 || i > 3);

		cout << "Вы вышли из замкнутого круга! \n";
	}

	//for (выражение_1; выражение_2; выражение_3)
	//{
	//	// тело цикла
	//}


	for (int i = 1;i < 10; i++) 
	{
		cout << i << " * " << i << " = " << i * i << endl;
	}
	cout << endl;
	//int i = 1;
	//for (;i < 10;)
	//{
	//	i++;
	//	cout << i << " * " << i << " = " << i * i << endl;
	//}

	//for (int i = 1, j=10;i < 10; i++, j--)
	//{
	//	cout << i << " * " << i << " = " << i * i << endl;
	//}

	// Вложенные циклы
	cout << " Таблица Умножения \n";
	for (int i = 1;i < 10; i++)
	{
		for (int j = 1;j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	
		cout << endl;
	}


	cout << " Таблица Умножения Пифагора \n";
	for (int i = 1;i < 10; i++)
	{
		for (int j = 1;j < 10; j++)
		{
			cout << "\t" << i * j ;
		}
		cout << endl;
	}




}