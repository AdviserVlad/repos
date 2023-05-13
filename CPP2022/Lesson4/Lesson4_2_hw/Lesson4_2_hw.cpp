//Хотел добавить ещё остаток от деления,но что-то пошло не так
//Если сделать все переменные типа int,то не будет считаться дробная часть,а это как-то не правильно
//Поэтому пришлось пожертвовать парой функции для нормального подсчета



#include <iostream>
#include <Windows.h>

using namespace std;


HANDLE hConsole;
enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };



void rules()
{
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Программа выполняет функции примитивного калькулятора." << endl;
	cout << "В скобках указаны примеры действий." << endl;
	cout << "Перечень действий:" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\t\t1.Сложение(1+1)" << endl;
	cout << "\t\t2.Вычетание(1-1)" << endl;
	cout << "\t\t3.Умножение(1*1)" << endl;
	cout << "\t\t4.Деление(1/1)" << endl;
	cout << "\t\t5.Остаток от деления(1%1)" << endl;
}

void summa(double* x, double* y, double* tmp)
{
	*tmp = *x + *y;
}

void defference(double* x, double* y, double* tmp)
{
	*tmp = *x - *y;
}

void multiplier(double* x, double* y, double* tmp)
{
	*tmp = *x * *y;
}

void splitting(const double* x, const double* y, double* tmp)
{
	*tmp = *x / *y;
}




int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "Russian");

	double a, b, result;
	char action;

	rules();

	do
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "---------" << endl;
		cin >> a >> action >> b;
		cout << " = " << endl;

		switch (action)
		{

		case '+':

			summa(&a, &b, &result);
			cout << result << endl << endl;
			cout << "---------" << endl;
			break;

		case '-':
			defference(&a, &b, &result);
			cout << result << endl << endl;
			cout << "---------" << endl;
			break;

		case '*':
			multiplier(&a, &b, &result);
			cout << result << endl << endl;
			cout << "---------" << endl;
			break;

		case '/':
			splitting(&a, &b, &result);
			cout << result << endl << endl;
			cout << "---------" << endl;
			break;

		default:
			cout << "Ошибка ввода!";
		}
		SetConsoleTextAttribute(hConsole, 2);
		cout << "Для выхода из программы нажмите любую клавишу .";
		cout << "Для продолжения нажмите 1 : ";
		cin >> a;
		cout << endl;

	} while (a == 1);
}


