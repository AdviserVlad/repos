// Условные Операторы. Конструкции выбора.
// if  - если
	//if (утверждение или выражение) 
	//{
	//	действие 1; // если Истина
	//}
	//else // Иначе (не Истина, Ложь)
	//{
	//	действие 2;
	//}

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	system("cls");          // Очистка экрана
	
	int goldInChest = 10;
	int goldInHand = 0;
	
	cout << "Хо-хо-хо! У меня в сундучке " << goldInChest << " золотых монет!" << endl;

	if (goldInHand < goldInChest)
	{
		cout << "Эх, я еще мало заработал!" << endl;
	}
	
	if (goldInHand - goldInChest) // проверяем на отклонение от 0
	{
		cout << "Золото в руке != Золоту в сундуке" << endl;
	}
	else
	{
		cout << "Золото в руке == Золоту в сундуке" << endl;
	}

	goldInHand = 0;
	if (goldInHand++)  // goldInHand = goldInHand + 1
	{
		cout << "Все хорошо!" << endl;
		cout << "Хо-хо-хо! У меня теперь " << goldInHand << " золотых монет!" << endl; //
	}
	else
	{
		cout << "Что-то пошло не так. :)" << endl;
		cout << "Хо-хо-хо! У меня теперь " << goldInHand << " золотых монет!" << endl; //
	}
	
	cout << endl;
	goldInHand = 0;
	if (++goldInHand)
	{
		cout << "Все хорошо!" << endl;
		cout << "Хо-хо-хо! У меня теперь " << goldInHand << " золотых монет!" << endl; //
	}
	else
	{
		cout << "Что-то пошло не так. :)" << endl;
		cout << "Хо-хо-хо! У меня теперь " << goldInHand << " золотых монет!" << endl; //
	}

	cout << endl;
	// Это не goldInChest == goldInHand !!!  false только если goldInHand = 0
	if (goldInChest = goldInHand)
	{
		cout << "Все хорошо!" << endl;
		cout << "Хо-хо-хо! У меня теперь в сундуке " << goldInChest << " золотых монет!" << endl; //
	}

	cout << endl;
	goldInChest = 10;
	if (10 == goldInChest)
	{
		cout << "Все хорошо!" << endl;
		cout << "Хо-хо-хо! Я - Богатенький Буратино! :) \n У меня  в сундуке " << goldInChest << " золотых монет!" << endl; //
	}

	cout << endl;

	int num;
	cout << "Введите число от 1 до 10: ";
	cin >> num;
	if ((num >= 1) && (num <= 10))
	{
		cout << "Молодец! Вы ввели правильное число.\n";
	}
	else
	{
		cout << "Попробуйте в следующий раз вводить то, что попросили :).\n";
	}


	if ((num >= 1) && (num <= 10))
	{
		cout << "Молодец! Вы ввели правильное число.\n";
	}
	else if (num == 0)
	{
		cout << "Вы нашли ПАСХАЛОЧКУ! Но, в следующий раз вводите то, что попросили :).\n";
	}
	else  
	{
		if (true)
		{

		}
		else
		{
			if (true)
			{

			}
		}
		cout << "Попробуйте в следующий раз вводить то, что попросили :).\n";
	}
	
	goldInHand = 0;
	if (goldInHand == 0) cout << "А кармашки-то пустые!";
	// равносильный вариант
	if (!goldInHand) cout << "А кармашки-то пустые!";
	

	// избегайте таких формулировок условий
	if (goldInHand)    // проверка на отклонение от 0
		cout << "ничего не делаем";
	else
		cout << "А кармашки-то пустые!";

	//инкремент ++     i++ --> i=i+1
	//декремент --     i-- --> i=i-1
	//  += -= /= %= *= синтаксический "сахар"
	// i += 2  --> i = i +2		x+=y -->  x=x+y
	// i -= 2  --> i = i -2
	// i *= 2  --> i = i *2
	// i /= 2  --> i = i /2
	// i %= 2  --> i = i %2




}

