#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <vector>

//нужно фиксить вход и выход основного цикла(либо костылить с выводом инфы на консоль(но что тогда если уже будет проставлено несколько кораблей и захочется убрать несколько))
//Проблема возникает когда полностью поставили первый корабль и решаемся его отменить.
//вывод в консоль не корректный и передача данных идет по...

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct fieldСells//структура значений полей
{
	const int empty = 0;//пустая ячейка
	const int ship = 1;//ячейка корабля
	const int miss = 2;//ячейка промах
	const int hit = 3;//ячейка раненого корабля
	const int destroyed = 4;//ячейка разрушенного корабля
	const int nearShip = 5;//ячейка рядом с разрушенным / кораблем
} myMap;//экземпляр структуры

const int sizeMap = 10;
int firstMap[sizeMap][sizeMap] = { 0 };//карта инициализированная нулями(пустая ячейка)
int* ptrFirstMap = (int*)firstMap;//указатель на первую карту
int secondMap[sizeMap][sizeMap] = { 0 };//так как статический двумерный массив все равно линейный(первый адрес новой строки следует за концом предыдущей), будем работать с ним
int* ptrSecondMap = (int*)secondMap;//указатель на вторую карту
vector <string> coordsString;//вектор со стринговыми значениями координат для навигации курсора при отмене постановки палубы 

//переменные для навигации и очистки консольного окна
//int lenY = 5;

//проверка ввода 

//bool yesNoInput()
//{
//	while (true)
//	{
//		int x0 = getXcoord();
//		int y0 = getYcoord();
//		string str;
//		cin >> str;
//		if (str.size() == 1 && str[0] == '1') return 1;
//		else if (str.size() == 1 && str[0] == '0') return 0;
//		else
//		{
//			putCursorPos(x0, y0);
//			for (unsigned int i = 0; i <= str.size(); i++) { cout << " "; } //Затирание введенных символов
//			putCursorPos(x0, y0);
//		}
//	}
//}

//полное отображение карт боя
void mapDisplay(fieldСells* fieldСells, int* ptrFirstMap, int* ptrSecondMap);
//вывод в консоль отдельной ячейки поля
void cellMapDisplay(int* pntMap);
//перевод букв в индекс массива
int getIndex(char firingCoordinates, bool& checkCoord);
//получение координат X/Y для перемещения курсора для отрисовки отдельной палубы
int getCoordXWhereYWantADeck(char coordinate, int battlefieldStartNum);
int getCoordYWhereYWantADeck(char coordinate);
//расстановка палуб корабля для игрока
void arrangementDeck(fieldСells* myMap, int* ptrFirstMap, int& shipSize, vector<string>& coord);
//проверка правильной установки палуб корабля после первой устаовленной
bool CheckSettingupShipDeck(fieldСells* myMap, int* ptrFirstMap, int* deckIndexPosition, int* numPlacedDeck);
//определение положения курсора
int getCoord(bool selectorXY);
//перенос курсора
void moveCursor(int x, int y);
//заполняем массив "пустыми" значениями
void doArrEmpty(int* ptrMap, fieldСells* myMap);
//чистим экран
void clearScreen(int numYForStartClean);
//чистим лог
void clearLog();


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	//переменная для расчета палуб при расстановке кораблей
	//расстановка начинается всегда с 4х палубного
	int shipSize = 4;
	//переменная общего количества кораблей = жизней
	int numShips = 1;

	mapDisplay(&myMap, ptrFirstMap, ptrSecondMap);
	for (size_t i = shipSize; i > 0; i--)
	{
		if (shipSize == 4)
		{
			arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
			--shipSize;
		}
		else if (shipSize == 3)
		{
			do
			{
				moveCursor(0, 16);
				arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
				numShips++;
			} while (numShips != 3);
			--shipSize;
		}
		else if (shipSize == 2)
		{
			do
			{
				moveCursor(0, 16);
				arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
				numShips++;
			} while (numShips != 6);
			--shipSize;
		}
		else if (shipSize == 1)
		{
			do
			{
				moveCursor(0, 16);
				arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
				numShips++;
			} while (numShips != 10);
		}
	}

	/*switch (shipSize)
	{
	case 4:
		arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
		--shipSize;
	case 3:
		do
		{
			moveCursor(0, 16);
			arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
			numShips++;
		} while (numShips != 3);
		--shipSize;
	case 2:
		do
		{
			moveCursor(0, 16);
			arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
			numShips++;
		} while (numShips != 6);
		--shipSize;
	case 1:
		do
		{
			moveCursor(0, 16);
			arrangementDeck(&myMap, ptrFirstMap, shipSize, coordsString);
			numShips++;
		} while (numShips != 10);
		break;
	default:
		break;
	}*/


}

void mapDisplay(fieldСells* myMap, int* ptrFirstMap, int* ptrSecondMap)//ПЕРЕКЛЮЧАТЕЛЬ ПОКАЗА ПОЛЕЙ(ТОЛЬКО СВОЕ ИЛИ ЕЩЕ И ПРОТИВНИКА)
{
	//bool selectorXY = true;//переключатель для получения координат по разным осям
	size_t toggle = 1;//РИСУЕМ ДВЕ КАРТЫ
	int x, y;//переменные для навигации по консоли
	int* ptrFirst = ptrFirstMap;
	int* ptrSecond = ptrSecondMap;

	for (size_t i = 0; i <= toggle; i++)
	{
		//int x0 = getCoord(selectorXY);
		//selectorXY = false;
		//int y0 = getCoord(selectorXY);

		switch (i)//координаты начала вывода
		{
		case 0:
			x = 0; y = 5;
			break;
		case 1:
			x = 40; y = 5;
			break;
		case 2:
			x = 0; y = 33;
			break;
		case 3:
			x = 40; y = 33;
			break;
		default:
			cout << "Ошибка отображения поля боя!";
			exit(0);
		}
		SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10)); //изменение цвета фона на синий; шрифта на кислотно\зеленый

		switch (i)//вывод полей
		{
		case 0:
			moveCursor(x, y);														 //
			cout << "    А Б В Г Д Е Ж З И К  \n";									 //
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~\n";									 //
			for (size_t n = 1; n <= 10; n++)										 //
			{																		 //
				if (n == 10)														 //границы
				{																	 //
					cout << n << "|                     |\n";						 //
				}																	 //
				else																 //
					cout << " " << n << "|                     |\n";				 //
			}																		 //
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~\n";									 //

			for (size_t k = 0; k < sizeMap; k++)									 //
			{																		 //
				for (size_t l = 0; l < sizeMap; l++)								 //
				{																	 //
					moveCursor(x + 4 + l * 2, y + 2 + k);							 //
					switch (i)														 //
					{																 //
					case 0:															 //
						cellMapDisplay(ptrFirst);									 //ячейки
						ptrFirst++;													 //
						break;														 //
					case 1:															 //
						cellMapDisplay(ptrSecond);									 //
						ptrSecond++;												 //
						break;														 //
					}																 //
				}																	 //
			}																		 //
			break;
		case 1:
			moveCursor(x, y);
			cout << "    А Б В Г Д Е Ж З И К  ";
			moveCursor(x, y + 1);
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~";
			for (size_t m = 1; m <= 10; m++)
			{
				moveCursor(x, y + 1 + m);
				if (m < 10)
				{
					cout << " " << m << "|                     |";
				}
				else
					cout << m << "|                     |";
			}
			moveCursor(x, y + 12);
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~\n";
			for (size_t k = 0; k < sizeMap; k++)
			{
				for (size_t l = 0; l < sizeMap; l++)
				{
					moveCursor(x + 4 + l * 2, y + 2 + k);
					switch (i)
					{
					case 0:
						cellMapDisplay(ptrFirst);
						ptrFirst++;
						break;
					case 1:
						cellMapDisplay(ptrSecond);
						ptrSecond++;
						break;
					}
				}
			}
			break;
		default:
			break;
		}
	}
	ptrFirst = ptrFirstMap;
	ptrSecond = ptrSecondMap;
}
void cellMapDisplay(int* pntMap)
{
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));//зеленый на синем
	switch (*pntMap)
	{
	case 0:
		cout << char(183) << " ";
		break;
	case 1:
		cout << char(61) << " ";
		break;
	case 2:
		cout << char(111) << " ";
		break;
	case 3:
		cout << char(88) << " ";
		break;
	case 4:
		cout << char(87) << " ";
		break;
	case 5:
		cout << char(43) << " ";
		break;
	default:
		break;
	}
}
int getIndex(char coordinates, bool& checkCoord)
{
	switch (coordinates)
	{
	case 'А':
	case 'а':
	case '1':
		checkCoord = true;
		return (0);
		break;
	case 'Б':
	case 'б':
	case '2':
		checkCoord = true;
		return (1);
		break;
	case 'В':
	case 'в':
	case '3':
		checkCoord = true;
		return (2);
		break;
	case 'Г':
	case 'г':
	case '4':
		checkCoord = true;
		return (3);
		break;
	case 'Д':
	case 'д':
	case '5':
		checkCoord = true;
		return (4);
		break;
	case 'Е':
	case 'е':
	case '6':
		checkCoord = true;
		return (5);
		break;
	case 'Ж':
	case 'ж':
	case '7':
		checkCoord = true;
		return (6);
		break;
	case 'З':
	case 'з':
	case '8':
		checkCoord = true;
		return (7);
		break;
	case 'И':
	case 'и':
	case '9':
		checkCoord = true;
		return (8);
		break;
	case 'К':
	case 'к':
		checkCoord = true;
		return (9);
		break;
	case '0':
		checkCoord = true;
		return (90);
		break;
	default:
		checkCoord = false;
		return (0);
		break;
	}
}
int getCoordXWhereYWantADeck(char coordinate, int battlefieldStartNum)
{
	switch (coordinate)//шаг в две клетки(*2) так как по оси Х по две ячейки между буквами
	{
	case 'А':
	case 'а':
		return (battlefieldStartNum);
		break;
	case 'Б':
	case 'б':
		return (battlefieldStartNum + 2);
		break;
	case 'В':
	case 'в':
		return (battlefieldStartNum + 2 * 2);
		break;
	case 'Г':
	case 'г':
		return (battlefieldStartNum + 2 * 3);
		break;
	case 'Д':
	case 'д':
		return (battlefieldStartNum + 2 * 4);
		break;
	case 'Е':
	case 'е':
		return (battlefieldStartNum + 2 * 5);
		break;
	case 'Ж':
	case 'ж':
		return (battlefieldStartNum + 2 * 6);
		break;
	case 'З':
	case 'з':
		return (battlefieldStartNum + 2 * 7);
		break;
	case 'И':
	case 'и':
		return (battlefieldStartNum + 2 * 8);
		break;
	case 'К':
	case 'к':
		return (battlefieldStartNum + 2 * 9);
		break;
	}
}
int getCoordYWhereYWantADeck(char coordinate)
{
	switch (coordinate)
	{
	case '1':
		return (7);
		break;
	case '2':
		return (8);
		break;
	case '3':
		return (9);
		break;
	case '4':
		return (10);
		break;
	case '5':
		return (11);
		break;
	case '6':
		return (12);
		break;
	case '7':
		return (13);
		break;
	case '8':
		return (14);
		break;
	case '9':
		return (15);
		break;
	case '0':
		return (16);
		break;
	}
}
void arrangementDeck(fieldСells* myMap, int* ptrFirstMap, int& shipSize, vector<string>& coordsString)
{
	//переменные для перемещения курсора при отмене предыдущих координат
	const int x = 42;
	const int y = 21;
	int xForDeck, yForDeck;
	//переменные для навигации по массиву
	string str;
	bool checkCoord = true;
	//счет повторов расстановки палуб
	int numPlacedDeck = 0;

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); //белый на черном
	cout << "\n\nДля размещения палубы корабля введите координату в формате 'А1' или 'а1'\n";
	cout << "Для сброса введенных ранее координат введите '0'\n\n";
	do
	{
		if (numPlacedDeck != 0 || !checkCoord)//для всегда(ситуация при первом неудачном вводе данных места корабля) корректного отображения 
		{
			moveCursor(0, y);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); //белый на черном
		}
		//if (numPlacedDeck >= 0)
		cout << "Введите " << numPlacedDeck + 1 << " координату " << shipSize << "-палубного корабля: ";
		//else
		//{
		//	numPlacedDeck = shipSize;
		//	++shipSize;
		//	cout << "Введите " << numPlacedDeck + 1 << " координату " << shipSize << "-палубного корабля: ";
		//}
		if (!checkCoord)
		{
			for (size_t i = 0; i <= str.size(); i++)
			{
				cout << " ";
			}
			moveCursor(0, y + 1);
			cout << "Повторите ввод координат вашего корабля!";
			moveCursor(x, y);
		}
		int deckIndexPosition = 0;
		getline(cin, str);
		if (str.size() == 2 &&
			int(str[1]) >= 49 && int(str[1]) <= 57 &&
			(int(str[0]) >= -32 && int(str[0]) <= -22) ||
			(int(str[0]) >= -64 && int(str[0]) <= -54))//лень(уже слишком длинное условие...) было прописывать исключение "й", верим что не будет)
		{
			deckIndexPosition = getIndex(str[1], checkCoord);		//посчитали индекс для массива боевого поля
			deckIndexPosition *= 10;								//
			deckIndexPosition += getIndex(str[0], checkCoord);		//
			checkCoord = CheckSettingupShipDeck(myMap, ptrFirstMap, &deckIndexPosition, &numPlacedDeck);//проверили можем ли ставить сюда 
			if (checkCoord)
			{
				*(ptrFirstMap + deckIndexPosition) = myMap->ship;			//поставили там "палубу корабля"
				coordsString.push_back(str);									//записали координату последним значением в вектор
				moveCursor(0, y);										//переместили курсор на место для ввода координат
				clearScreen(y);											//почистили экран
				xForDeck = getCoordXWhereYWantADeck(str[0], 4);			//взяли координаты с введенной строки(четверка - начало отображения боевого поля)
				yForDeck = getCoordYWhereYWantADeck(str[1]);			//
				moveCursor(xForDeck, yForDeck);								//переместились на место отображения палубы
				cellMapDisplay(&ptrFirstMap[deckIndexPosition]);				//отобразили палубу на карте
				++numPlacedDeck;										//увеличили число успешло поставленных палуб(в конце сравниваем с переданным количеством палуб)
			}
		}
		else if (str.size() == 3 &&
			int(str[2]) == 48 && int(str[1]) == 49 &&
			(int(str[0]) >= -32 && int(str[0]) <= -22) ||
			(int(str[0]) >= -64 && int(str[0]) <= -54))
		{
			deckIndexPosition = getIndex(str[0], checkCoord);
			deckIndexPosition += getIndex(str[2], checkCoord);
			checkCoord = CheckSettingupShipDeck(myMap, ptrFirstMap, &deckIndexPosition, &numPlacedDeck);
			if (checkCoord)
			{
				*(ptrFirstMap + deckIndexPosition) = myMap->ship;
				coordsString.push_back(str);
				moveCursor(0, y);
				clearScreen(y);
				xForDeck = getCoordXWhereYWantADeck(str[0], 4);
				yForDeck = getCoordYWhereYWantADeck(str[2]);
				moveCursor(xForDeck, yForDeck);
				cellMapDisplay(&ptrFirstMap[deckIndexPosition]);
				++numPlacedDeck;
			}
		}
		else if (str[0] == '0')
		{
			if (!coordsString.empty())
			{
				str = coordsString.back();
				if (str.size() == 2)
				{
					deckIndexPosition = getIndex(str[1], checkCoord);
					deckIndexPosition *= 10;
					deckIndexPosition += getIndex(str[0], checkCoord);
					xForDeck = getCoordXWhereYWantADeck(str[0], 4);
					yForDeck = getCoordYWhereYWantADeck(str[1]);
				}
				else if (str.size() == 3)
				{
					deckIndexPosition = getIndex(str[0], checkCoord);
					deckIndexPosition += getIndex(str[2], checkCoord);
					xForDeck = getCoordXWhereYWantADeck(str[0], 4);
					yForDeck = getCoordYWhereYWantADeck(str[2]);
				}
				*(ptrFirstMap + deckIndexPosition) = myMap->empty;
				moveCursor(x, y);
				cout << " ";
				moveCursor(xForDeck, yForDeck);//по-моему, не может быть не инициализированными
				cellMapDisplay(&ptrFirstMap[deckIndexPosition]);
				coordsString.pop_back();
				--numPlacedDeck;
				checkCoord = false;
			}
			else
			{
				checkCoord = false;
			}
		}
		else
		{
			checkCoord = false;
		}
	} while (!checkCoord || numPlacedDeck != shipSize);
}
bool CheckSettingupShipDeck(fieldСells* myMap, int* ptrFirstMap, int* deckIndexPosition, int* numPlacedDeck)
{
	if (*numPlacedDeck > 0)
	{
		if (*(ptrFirstMap + *deckIndexPosition) == myMap->empty)
		{
			if (*(ptrFirstMap + (*deckIndexPosition + 10)) == myMap->ship || //проверка по строкам(ось У)
				*(ptrFirstMap + (*deckIndexPosition - 10)) == myMap->ship)
				return true;
			else if (*(ptrFirstMap + (*deckIndexPosition + 1)) == myMap->ship || //проверка по столбцам(ось Х)
				*(ptrFirstMap + (*deckIndexPosition - 1)) == myMap->ship)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else if (*numPlacedDeck == 0)
	{
		if (*(ptrFirstMap + *deckIndexPosition) == myMap->empty)//если поле пустое
			return true;
		else
			return false;
	}
	else
		return false;
}
int getCoord(bool selectorXY)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hConsole, &info);
	if (selectorXY)
		return info.dwCursorPosition.X;
	else
		return info.dwCursorPosition.Y;
}
void moveCursor(int x, int y)
{
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(hConsole, cursorCoord);
}
void doArrEmpty(int* ptrMap, fieldСells* myMap)
{
	for (size_t i = 0; i < sizeMap; i++)
	{
		for (size_t j = 0; j < sizeMap; j++)
		{
			*ptrFirstMap++ = myMap->empty;
		}
	}
}
void clearScreen(int numYForStartClean)
{
	for (int i = numYForStartClean; i <= 22; i++)
	{
		cout << "                                                                   \n";
	}
}
void clearLog()
{
	int logX = 80;
	int logY = 5;
	for (int i = 0; i <= logY; i++)
	{
		moveCursor(logX, i);
		cout << "                                       \n";
	}
}