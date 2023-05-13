// Потоки. Ввод-Вывод.
//  cin, cout, cerr и clog

//fstream() - создает поток, не открывая файла;
//
// fstream(
//    const char* name, //имя файла
//    int omode, //режим открытия
//    int = filebuf::openprot //защита файла
//) - создает поток, открывает файл и связывает его с потоком;
//
// fstream(
//    int f // дескриптор файла
//) - создает поток и связывает его с уже открытым файлом
//
// fstream(
//    int f, //дескриптор файла
//    char* buf, //буфер
//    int len //размер буфера
//) - то же, что предыдущий конструктор, но потоку назначается буфер.

// ios::
//in = 0x01, //открыть только для чтения
//out = 0x02, //открыть только для записи
//ate = 0x04, //установить указатель на конец файла
//app = 0x08,  //дописывать данные в конец файла
//trunc = 0x10, //усечь файл до нулевой длины
//_Nocreate = 0x40, //если файл не существует, ошибка открытия
//_Noreplace = 0x80, //если файл уже существует, ошибка открытия
//binary = 0x20 //открыть файл для двоичного обмена

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>


using namespace std;

int main()
{
	int answer;
	const int messageCount = 8;
	int i, j;
	//Подсказки
	enum
	{
		EXIT = 3, INPUT_FILENAME,
		INPUT_DIMENSIONS, INPUT_ELEMENTS,
		FILE_ERROR
	};

	//Сообщения
	string msg[messageCount] =
	{
"1. Вывести данные из текстового файла\n",
"2. Записать данные в текстовый файл\n",
"3. Выход из программы\n",
"\nВаш выбор: ",
"Введите имя обрабатываемого файла: ",
"Введите размерности матрицы:\n",
"Введите элементы матрицы:\n",
"Невозможно открыть файл\n"
	};

	//Русификация сообщений и вывод меню на экран
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		system("cls");
		//for (i = 0; i < messageCount; i++)
		//	CharToOem(msg[i], msg[i]);
		do
		{
			for (int i = 0; i < 4; i++)
				cout << msg[i];
			cin >> answer;
		} while (answer < 1 || answer > 3);

		if (answer == EXIT) break;

		cin.clear();
		cin.ignore(32767, '\n');

		//Переменная для имени файла
		string fileName;
		//Размерности матрицы
		int rowMatrix, colMatrix;

		int num;
		cout << "\n" << msg[INPUT_FILENAME];
		getline(cin, fileName);

		//Если выбран первый пункт меню,
		//то выводим данные из текстового файла на экран

		if (answer == 1)
		{
			//Если файл с указанным именем не существует,
			//выводим сообщение об ошибке
			ifstream inF(fileName, ios::in | ios::_Nocreate);
			if (!inF)
			{
				cout << endl << msg[FILE_ERROR];
				continue;
			}
			//Считываем размерность массива
			inF >> rowMatrix;
			inF >> colMatrix;
			//Считываем элементы массива из файла и
			//выводим их сразу на экран
			for (i = 0; i < rowMatrix; i++)
			{
				for (j = 0; j < colMatrix; j++)
				{
					inF >> num;
					cout << setw(6) << num;
				}
				cout << endl;
			}
			inF.close();
			_getch();
		}
		else
		{//Если выбран второй пункт меню, то запрашиваем
		 //у пользователя данные и выводим их в текстовый файл
			//Открываем файл для записи.
			//Если файл с указанным именем не существует,
			//то программа создает его
			ofstream outF(fileName, ios::out);
			if (!outF)
			{
				cout << "\n" << msg[FILE_ERROR];
				continue;
			}
			//Запрашиваем размерность матрицы
			//и записываем данные в файл
			cout << msg[INPUT_DIMENSIONS];
			cout << "Введите кол-во строк: ";
			cin >> rowMatrix;
			cout << "Введите кол-во столбцов: ";
			cin >> colMatrix;

			outF << rowMatrix << ' ' << colMatrix << "\n";

			cout << msg[INPUT_ELEMENTS];
			//Запрашиваем элементы массива и записываем их в файл
			for (i = 0; i < rowMatrix; i++)
			{
				for (j = 0; j < colMatrix; j++)
				{
					cout << "A[" << i << "][" << j << "] = ";
					cin >> num;
					outF << num << " ";
				}
				outF << "\n";
			}
			outF.close();
		}

	} while (answer != EXIT);

	return 0;
}

