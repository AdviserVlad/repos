// УСЛОВНЫЕ Операторы
// ? тернарный оператор

#include <iostream>


using namespace std;

int main()
{
	system("cls");

	setlocale(LC_ALL, "Rus");

	// [первый операнд - условие] ? [второй операнд] : [третий операнд]
	
	int num1 , num2 ;
	cout << "Введите 2 числа : ";
	cin >> num1 >> num2;

	(num2 != 0) ? cout << num1 << "/" << num2 << " = " << num1 / num2 :
		cout << " Попытка деления на 0! ";
	
	// написать программу определяющую максимальное и минимальное число
	// из 2х введенных. Использовать тернарный оператор.
	int max, min;

	if (num1 == num2)
	{
		cout << "Вы ввели два одинаковых числа.";
	}

	max = (num1 > num2) ? num1 : num2;
	min = (num1 < num2) ? num1 : num2;
	
	// тоже работает :)
	//(num1 > num2) ? max = num1, min = num2 : max = num2, min = num1;

	cout << "Максимальное = "<< max;
	cout << "Минимальное = " << min;
	
	// Узнать принадлежит ли точка кольцу.
	int x0, y0, r1, r2, x, y;
	double pointVector;
	cin >> x0 >> y0;
	cin >> r1 >> r2;
	cin >> x >> y;

	pointVector = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
	if ((pointVector > r1) && (pointVector < r2))
	{
		cout << "Точка принадлежит кольцу.";
	}
	else
	{
		cout << "Точка за пределами кольца.";
	}
}

