//Написать функцию, которая принимает в качестве па -
//раметров вещественное число и количество знаков
//после десятичной точки, которые должны остаться.
//Задачей функции является округление вышеуказанного
//вещественного числа с заданной точностью

#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T> 
T myround(T num, int precesion)
{
	//int intNum = (int)num;
	//double decimalNum = num - intNum;
	//num -= intNum;

	for (size_t i = 0; i < precesion; i++)
	{
		num *= 10;
	}
	int inum = (int)num;
	if (num - inum >=0.5)
	{
		inum++;
	}
	num = inum;

	for (size_t i = 0; i < precesion; i++)
	{
		num /= 10;
	}
	
	return num;

}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	double x = 12.0;
	float y = 34.0;
	int p = 2;
	cout << myround(x, p)<<endl;
	cout << myround(y, p)<<endl;
}

