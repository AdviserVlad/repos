/// СТРОКИ
// 
//

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
const int n = 15;

string monthName(int month);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //setlocale

	for (size_t i = 0; i < n; i++)
	{
		cout << "Номер месяца " << i << " - " << monthName(i) << "\n";
	}


	string name[] = {
    "none",
    "Январь",
    "Февраль",
    "Март",
    "Апрель",
    "Май",
    "Июнь",
    "Июль",
    "Август",
    "Сентябрь",
    "Октябрь",
    "Ноябрь",
    "Декабрь"
	};


	for (string month : name)
	{
		cout << "Название месяца - " << month << "\n";
	}



}


string monthName(int month)
{
    string name[] = {
    "none",
    "Январь",
    "Февраль",
    "Март",
    "Апрель",
    "Май",
    "Июнь",
    "Июль",
    "Август",
    "Сентябрь",
    "Октябрь",
    "Ноябрь",
    "Декабрь"
    };

    return (month < 1 || month >12) ? name[0] : name[month];

}