// Fraction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <windows.h>
#include "RationalFraction.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RationalFraction a(1, 2), b(1, 3), c(5), d;

	cout << "------------- 1 ------------- " << endl <<
		"a: " << a << endl <<
		"b: " << b << endl <<
		"c: " << c << endl <<
		"d: " << d << endl;
	
		cout << "b = (введите через <пробел> числитель и знаменатель): ";
		cin >> b;
	

		d = 2 * a / b;
		c = d * 1;

		cout << "------------- 2 ------------- " << endl <<
			"a: " << a << endl <<
			"b: " << b << endl <<
			"c: " << c << endl <<
			"d: " << d << endl;

		if (d == c) {
			cout << "d == c" << endl;
		}
		else {
			cout << "d НЕ = c" << endl;
		}

		a = a - d;
		c /= -d;

		cout << "------------- 3 ------------- " << endl <<
			"a: " << a << endl <<
			"b: " << b << endl <<
			"c: " << c << endl <<
			"d: " << d << endl;

		b = --c;

		cout << "------------- 4 ------------- " << endl <<
			"a: " << a << endl <<
			"b: " << b << endl <<
			"c: " << c << endl <<
			"d: " << d << endl;

		b = d--;

		cout << "------------- 5 ------------- " << endl <<
			"a: " << a << endl <<
			"b: " << b << endl <<
			"c: " << c << endl <<
			"d: " << d << endl;

		if (a < c) {
			cout << "a < c" << endl;
		}
		else {
			cout << "a НЕ < c" << endl;
		}

		if (d < d) {
			cout << "d < d" << endl;
		}
		else {
			cout << "d НЕ < d" << endl;
		}

		if (d <= d) {
			cout << "d <= d" << endl;
		}
		else {
			cout << "d НЕ <= d" << endl;
		}

		if (d > 2) {
			cout << "d > 2" << endl;
		}
		else {
			cout << "d НЕ > 2";
		}

	}
