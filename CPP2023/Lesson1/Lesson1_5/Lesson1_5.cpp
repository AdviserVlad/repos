// Логические Операции
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	system("cls");          // Очистка экрана

	// Операторы сравнения
	//  < > <= >=
	cout << (5 < 3) << endl; // 0
	cout << (5 > 3) << endl; // 1
	
	cout << boolalpha << (5 < 3) << endl; // false
	cout << boolalpha << (5 > 3) << endl; // true 
	
	// Операторы равенства
	// == !=
	cout << boolalpha << (5 != 3) << endl; // true
	
	// Логические Объединения и отрицательная инверсия
	//  И &&      ИЛИ ||      НЕ !
	cout << boolalpha << ((5 > 3) && (6 == 3)) << endl; // флаг boolalpha
	
	// конъюнкция, логическое умножение
	//Утверждение 1 Утверждение 2    &&
	//	true		true			true      1 1 1
	//	true		false			false     1 0 0
	//	false		true			false
	//	false		false			false

	// дизъюнкция, логическое сложение
	//Утверждение 1 Утверждение 2    ||
	//	true		true			true     1 1 1
	//	true		false			true	 1 0 1
	//	false		true			true
	//	false		false			false    0 0 0

	int num;
	cout << "Введите число от 1 до 10: ";
	cin >> num;
	cout << boolalpha << ((num >= 1) && (num <= 10)) << endl;
	cout << "Если вы видите true, то вы ввели правильное число.\n";
	cout << "Если вы видите false, то вы ввели число в другом диапазоне.\n";

	//num = 0; !num  --- истина


}
