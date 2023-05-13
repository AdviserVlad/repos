// Операторы.

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	system("cls");          // Очистка экрана
	int goldInChest = 10;  
	
	cout << "Хо-хо-хо! У меня в сундучке " << goldInChest << " золотых монет!" << endl;
	
	// + - * / %
	goldInChest = goldInChest + 2;	// Эти действия равнозначны
	goldInChest += 2;				// Эти действия равнозначны
	
	goldInChest += 1;
	cout << "Хо-хо-хо! У меня в сундучке " << goldInChest << " золотых монет!" << endl; //15
	
	// Инкремент и Декремент
	//goldInChest++; // +1
	cout << "Хо-хо-хо! А теперь У меня в сундучке " << goldInChest++ << " золотых монет!" << endl;
	//++goldInChest; // +1
	
	cout << "Хо-хо-хо! Больше Золота! У меня в сундучке " << goldInChest << " золотых монет!" << endl;

	// Преобразование типов
	//bool, char, short - int - unsigned int - 
		//long - unsigned long - float - double - long double
	int gold = 25.5; // сужающее преобразование не явное
	
	unsigned int gold2 = 25; // расширяющее преобразование не явное

	float money = 10.25; // double стал float сужающее преобразование не явное

	double goldInSafe = 1000.01;
	money = (int)goldInSafe; //явное сужающее
	cout << "Грабим сейф! Теперь У меня в кармане " << money << " золотых монет!" << endl;

	float moneyInHands = { 10.25 };
	float moneyInFlour { 10.5 };
	char ch{ 777 };



}

