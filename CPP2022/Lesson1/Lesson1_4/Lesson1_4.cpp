// Напишите программу вычисления площади прямоугольника.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	//cout << "---Программа вычисления площади прямоугольника!---\n";
	//int height=0, width=0, square=0;
	//cout << "Введите ширину прямоугольника: ";
	//cin >> width;
	//cout << "Введите высоту прямоугольника: ";
	//cin >> height;
	//square = width * height; // вычисляем площадь
	//cout << "Площадь прямоугольника = " << square << endl;

	// + - / * %
	// Литералы  5 'F'  
	// 5.0f - литерал типа float

	cout << "---Программа вычисления стороны прямоугольника!---\n";
	int height = 0, width = 0, square = 0;
	cout << "Введите Площадь прямоугольника: ";
	cin >> square;
	cout << "Введите сторону прямоугольника: ";
	cin >> height;
	//width = square / height; // вычисляем сторону
	//cout << "Площадь прямоугольника = " << 8 % 5 << endl;

	square = pow(height, 2);
	cout << "Площадь квадрата = " << square << endl;
}

