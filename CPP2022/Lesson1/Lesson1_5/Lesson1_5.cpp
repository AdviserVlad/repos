// УСЛОВНЫЕ Операторы
//

#include <iostream>

using namespace std;

int main()
{
	system("cls");

	setlocale(LC_ALL, "Rus");

// Логические операции
// == != > < >= <= 

	cout << boolalpha << (5 > 3) << endl; // флаг boolalpha

// логические объединения
//  И && ИЛИ || НЕ !

	cout << boolalpha << ((5 > 3) && (6 == 3)) << endl; // флаг boolalpha

	int num;
	cout << "Введите число от 1 до 10: ";
	cin >> num;

	cout << boolalpha << ((num >= 1) && (num <= 10)) << endl; 
	cout << "Если вы видите true, то вы ввели правильное число.\n";
	cout << "Если вы видите false, то вы ввели число в другом диапазоне.\n";

	// num=0; !num --- истина 


}

