// СТРОКИ
// 
//

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//char Stroka[12] = { 'П','р','и','в','е','т',',',' ','м','и','р','!' };
	char Stroka[13] = { 'П','р','и','в','е','т',',',' ','м','и','р','!','\0' };
	for (int i = 0; i < 12; i++)
	{
		cout << Stroka[i];
	}
	cout << endl;
	cout << Stroka << endl;
	
	char* message;
	message = Stroka;
	cout << message << endl;

	char STR[255] = { "Игра Началась! :)" };
	cout << STR << endl;
	
	//cout << "Введите строку:" << endl;
	//cin >> STR;
	//cout << STR << endl;
    	
	//cout << "и еще разик. Введите строку:" << endl;
	//gets_s(STR);  //ввести строку с клавиатуры
 //   cout << STR << endl;

	//cout << strlen(STR) << endl;  //получить размер строки
	//  '\0'  - символ конца строки

	string Line = "Всем пока!";
	Line += " Завтра Воскресенье! ";
	Line += STR;
	cout << Line << endl;
	cout << "Введите строку:" << endl;
	getline(cin, Line);
	cout << Line << endl;

	cout << Line.length() << endl;
	cout << Line.size() << endl;

	if (Line.empty())
		cout << "Введена пустая строка" << endl;// ""

	string s1 = "Hallo";
	string s2 = "Hell";
	bool result = s1 > s2;
	cout << result << endl;

	s1[1] = 'e';
	cout << s1 << endl;

	cout << (char)tolower(s1[0]) << endl; //toupper - верхний регистр



}
