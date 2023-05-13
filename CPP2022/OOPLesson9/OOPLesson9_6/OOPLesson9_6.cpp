// Сериализация объекта. Вывод в бинарный файл.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

int RussianMenu()
{
	int choice;
	cout << R"(1 - для добавления новой структуры в файл;
2 - для показа всех структур из файла;
3 - для выхода;)";
	cin >> choice;
	return choice;
}

class Man
{
	//переменная для возраста
	int age;
	//переменная для имени
	string name;
	//переменная для фамилии
	string surname;
public:
	//конструктор с параметрами
	Man(string n, string s, int a);
	//конструктор
	Man();
	//деструктор
	~Man();
public:
	//функция ввода данных
	void Put();
	//функция показа данных
	void Show();
	//функция сохранения в файл
	void SaveToFile();
	//функция показа содержимого файла
	static void ShowFromFile();
};

//конструктор с параметрами
Man::Man(string n, string s, int a) :name{ n }, surname{ s }, age{ a }
{
}
//конструктор
Man::Man() : Man("Имя", "Фамилия", 10)
{
}


//деструктор
Man::~Man()
{

}

//функция ввода данных
void Man::Put() {
	cout << "\nВведите имя:\n";
	cin >> name;
	cout << "\nВведите фамилию:\n";
	cin >> surname;
	cout << "\nВведите возраст\n";
	cin >> age;
}

//функция показа данных
void Man::Show() {
	cout << "\nИмя:\n" << name;
	cout << "\nФамилия:\n" << surname;
	cout << "\nВозраст:\n" << age << "\n";
}

//функция сохранения в файл
void Man::SaveToFile()
{
	int size;
	fstream f("men.txt", ios::out | ios::binary | ios::app);
	if (!f) {
		cout << "Файл не открылся для записи !!!";
		exit(1);
	}
	//Записываем возраст
	f.write((char*)&age, sizeof(age));
	size = name.length();
	//Записываем количество символов в имени
	f.write((char*)&size, sizeof(int));
	//Записываем имя
	f.write((char*)name.c_str(), size * sizeof(char));
	size = surname.length();
	//Записываем количество символов в фамилии
	f.write((char*)&size, sizeof(int));
	//Записываем фамилию
	f.write((char*)surname.c_str(), size * sizeof(char));
	f.close();
}

//функция показа содержимого файла
void Man::ShowFromFile()
{
	fstream f("men.txt", ios::in | ios::binary);
	if (!f) {
		cout << "Файл не открылся для чтения !!!";
		exit(1);
	}
	string n, s;
	int a;
	int temp;
	//В цикле зачитываем содержимое файла
	while (f.read((char*)&a, sizeof(int)))
	{
		cout << "\nИмя:\n";
		f.read((char*)&temp, sizeof(int));
		//n = temp;
		n.resize(temp);
		f.read((char*)n.c_str(), temp * sizeof(char));
		cout << n;

		cout << "\nФамилия:\n";
		f.read((char*)&temp, sizeof(int));
		//s = temp;
		s.resize(temp);
		f.read((char*)s.c_str(), temp * sizeof(char));
		cout << s;

		cout << "\nВозраст:\n";
		cout << a << "\n";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD i;
	Man* chel;
	bool flag = true;
	//Основной цикл программы
	do {
		switch (RussianMenu())
		{
		case 1: //Добавление записи
			chel = new Man;
			chel->Put();
			chel->SaveToFile();
			delete chel;
			break;
		case 2: //Показ всех записей
			Man::ShowFromFile();
			break;
		case 3: //Прощание с пользователем
			cout << "До Свидания\n";
			flag = false;
			break;

		default: //Неправильный ввод
			cout << "Неверный Ввод\n";
			break;
		}
	} while (flag == true);

	return 0;
}
