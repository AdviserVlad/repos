#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <vector>

//����� ������� ���� � ����� ��������� �����(���� ��������� � ������� ���� �� �������(�� ��� ����� ���� ��� ����� ����������� ��������� �������� � ��������� ������ ���������))
//�������� ��������� ����� ��������� ��������� ������ ������� � �������� ��� ��������.
//����� � ������� �� ���������� � �������� ������ ���� ��...

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum field�ells//��������� �������� �����
{
	empty,//������ ������
	ship,//������ �������
	miss,//������ ������
	hit,//������ �������� �������
	destroyed,//������ ������������ �������
	NEAR_SHIP//������ ����� � ����������� / ��������
} myMap;//��������� ���������

const int sizeMap = 10;
int firstMap[sizeMap][sizeMap] = { 0 };//����� ������������������ ������(������ ������)
int* ptrFirstMap = (int*)firstMap;//��������� �� ������ �����
int secondMap[sizeMap][sizeMap] = { 0 };//��� ��� ����������� ��������� ������ ��� ����� ��������(������ ����� ����� ������ ������� �� ������ ����������), ����� �������� � ���
int* ptrSecondMap = (int*)secondMap;//��������� �� ������ �����
vector <string> coordsString;//������ �� ����������� ���������� ��������� ��� ��������� ������� ��� ������ ���������� ������ 

//���������� ��� ��������� � ������� ����������� ����
//int lenY = 5;

//�������� ����� 

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
//			for (unsigned int i = 0; i <= str.size(); i++) { cout << " "; } //��������� ��������� ��������
//			putCursorPos(x0, y0);
//		}
//	}
//}

//������ ����������� ���� ���
void mapDisplay(field�ells* field�ells, int* ptrFirstMap, int* ptrSecondMap);
//����� � ������� ��������� ������ ����
void cellMapDisplay(int* pntMap);
//������� ���� � ������ �������
int getIndex(char firingCoordinates, bool& checkCoord);
//��������� ��������� X/Y ��� ����������� ������� ��� ��������� ��������� ������
int getCoordXWhereYWantADeck(char coordinate, int battlefieldStartNum);
int getCoordYWhereYWantADeck(char coordinate);
//����������� ����� ������� ��� ������
void arrangementDeck(field�ells* myMap, int* ptrFirstMap, int& shipSize, vector<string>& coord);
//�������� ���������� ��������� ����� ������� ����� ������ ������������
bool CheckSettingupShipDeck(field�ells* myMap, int* ptrFirstMap, int* deckIndexPosition, int* numPlacedDeck);
//����������� ��������� �������
int getCoord(bool selectorXY);
//������� �������
void moveCursor(int x, int y);
//��������� ������ "�������" ����������
void doArrEmpty(int* ptrMap, field�ells* myMap);
//������ �����
void clearScreen(int numYForStartClean);
//������ ���
void clearLog();


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	//���������� ��� ������� ����� ��� ����������� ��������
	//����������� ���������� ������ � 4� ���������
	int shipSize = 4;
	//���������� ������ ���������� �������� = ������
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

void mapDisplay(field�ells* myMap, int* ptrFirstMap, int* ptrSecondMap)//������������� ������ �����(������ ���� ��� ��� � ����������)
{
	//bool selectorXY = true;//������������� ��� ��������� ��������� �� ������ ����
	size_t toggle = 1;//������ ��� �����
	int x, y;//���������� ��� ��������� �� �������
	int* ptrFirst = ptrFirstMap;
	int* ptrSecond = ptrSecondMap;

	for (size_t i = 0; i <= toggle; i++)
	{
		//int x0 = getCoord(selectorXY);
		//selectorXY = false;
		//int y0 = getCoord(selectorXY);

		switch (i)//���������� ������ ������
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
			cout << "������ ����������� ���� ���!";
			exit(0);
		}
		SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10)); //��������� ����� ���� �� �����; ������ �� ��������\�������

		switch (i)//����� �����
		{
		case 0:
			moveCursor(x, y);														 //
			cout << "    � � � � � � � � � �  \n";									 //
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~\n";									 //
			for (size_t n = 1; n <= 10; n++)										 //
			{																		 //
				if (n == 10)														 //�������
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
						cellMapDisplay(ptrFirst);									 //������
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
			cout << "    � � � � � � � � � �  ";
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
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 10));//������� �� �����
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
	case '�':
	case '�':
	case '1':
		checkCoord = true;
		return (0);
		break;
	case '�':
	case '�':
	case '2':
		checkCoord = true;
		return (1);
		break;
	case '�':
	case '�':
	case '3':
		checkCoord = true;
		return (2);
		break;
	case '�':
	case '�':
	case '4':
		checkCoord = true;
		return (3);
		break;
	case '�':
	case '�':
	case '5':
		checkCoord = true;
		return (4);
		break;
	case '�':
	case '�':
	case '6':
		checkCoord = true;
		return (5);
		break;
	case '�':
	case '�':
	case '7':
		checkCoord = true;
		return (6);
		break;
	case '�':
	case '�':
	case '8':
		checkCoord = true;
		return (7);
		break;
	case '�':
	case '�':
	case '9':
		checkCoord = true;
		return (8);
		break;
	case '�':
	case '�':
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
	switch (coordinate)//��� � ��� ������(*2) ��� ��� �� ��� � �� ��� ������ ����� �������
	{
	case '�':
	case '�':
		return (battlefieldStartNum);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 2);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 3);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 4);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 5);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 6);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 7);
		break;
	case '�':
	case '�':
		return (battlefieldStartNum + 2 * 8);
		break;
	case '�':
	case '�':
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
void arrangementDeck(field�ells* myMap, int* ptrFirstMap, int& shipSize, vector<string>& coordsString)
{
	//���������� ��� ����������� ������� ��� ������ ���������� ���������
	const int x = 42;
	const int y = 21;
	int xForDeck, yForDeck;
	//���������� ��� ��������� �� �������
	string str;
	bool checkCoord = true;
	//���� �������� ����������� �����
	int numPlacedDeck = 0;

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); //����� �� ������
	cout << "\n\n��� ���������� ������ ������� ������� ���������� � ������� '�1' ��� '�1'\n";
	cout << "��� ������ ��������� ����� ��������� ������� '0'\n\n";
	do
	{
		if (numPlacedDeck != 0 || !checkCoord)//��� ������(�������� ��� ������ ��������� ����� ������ ����� �������) ����������� ����������� 
		{
			moveCursor(0, y);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); //����� �� ������
		}
		//if (numPlacedDeck >= 0)
		cout << "������� " << numPlacedDeck + 1 << " ���������� " << shipSize << "-��������� �������: ";
		//else
		//{
		//	numPlacedDeck = shipSize;
		//	++shipSize;
		//	cout << "������� " << numPlacedDeck + 1 << " ���������� " << shipSize << "-��������� �������: ";
		//}
		if (!checkCoord)
		{
			for (size_t i = 0; i <= str.size(); i++)
			{
				cout << " ";
			}
			moveCursor(0, y + 1);
			cout << "��������� ���� ��������� ������ �������!";
			moveCursor(x, y);
		}
		int deckIndexPosition = 0;
		getline(cin, str);
		if (str.size() == 2 &&
			int(str[1]) >= 49 && int(str[1]) <= 57 &&
			(int(str[0]) >= -32 && int(str[0]) <= -22) ||
			(int(str[0]) >= -64 && int(str[0]) <= -54))//����(��� ������� ������� �������...) ���� ����������� ���������� "�", ����� ��� �� �����)
		{
			deckIndexPosition = getIndex(str[1], checkCoord);		//��������� ������ ��� ������� ������� ����
			deckIndexPosition *= 10;								//
			deckIndexPosition += getIndex(str[0], checkCoord);		//
			checkCoord = CheckSettingupShipDeck(myMap, ptrFirstMap, &deckIndexPosition, &numPlacedDeck);//��������� ����� �� ������� ���� 
			if (checkCoord)
			{
				*(ptrFirstMap + deckIndexPosition) = myMap->ship;			//��������� ��� "������ �������"
				coordsString.push_back(str);									//�������� ���������� ��������� ��������� � ������
				moveCursor(0, y);										//����������� ������ �� ����� ��� ����� ���������
				clearScreen(y);											//��������� �����
				xForDeck = getCoordXWhereYWantADeck(str[0], 4);			//����� ���������� � ��������� ������(�������� - ������ ����������� ������� ����)
				yForDeck = getCoordYWhereYWantADeck(str[1]);			//
				moveCursor(xForDeck, yForDeck);								//������������� �� ����� ����������� ������
				cellMapDisplay(&ptrFirstMap[deckIndexPosition]);				//���������� ������ �� �����
				++numPlacedDeck;										//��������� ����� ������� ������������ �����(� ����� ���������� � ���������� ����������� �����)
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
				moveCursor(xForDeck, yForDeck);//��-�����, �� ����� ���� �� �������������������
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
bool CheckSettingupShipDeck(field�ells* myMap, int* ptrFirstMap, int* deckIndexPosition, int* numPlacedDeck)
{
	if (*numPlacedDeck > 0)
	{
		if (*(ptrFirstMap + *deckIndexPosition) == myMap->empty)
		{
			if (*(ptrFirstMap + (*deckIndexPosition + 10)) == myMap->ship || //�������� �� �������(��� �)
				*(ptrFirstMap + (*deckIndexPosition - 10)) == myMap->ship)
				return true;
			else if (*(ptrFirstMap + (*deckIndexPosition + 1)) == myMap->ship || //�������� �� ��������(��� �)
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
		if (*(ptrFirstMap + *deckIndexPosition) == myMap->empty)//���� ���� ������
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
void doArrEmpty(int* ptrMap, field�ells* myMap)
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