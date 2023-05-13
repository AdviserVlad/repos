// Линейный ПОИСК 
//

#include <iostream>

using namespace std;

int lineSearch(int array[], const int ArraySize, const int searchKey)
{
	//int flag = -1;
	for (size_t i = 0; i < ArraySize; i++)
		if (array[i] == searchKey) return i;
	return -1;
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int ArraySize = 100;
	int array[ArraySize], searchKey, elementIndex;
	for (int i = 0; i < ArraySize; i++)
	{
		array[i] = rand() % (100 - (-100)) - 100;
		//Array[i] = (char)rand() % 255;    //char
		//Array[i] = (rand() % (100 - (-100)) - 100)/3.0;  //double
		if (i % 20 == 0) cout << endl;
		cout << array[i] << "; ";
	}

	cout << "\nВведите значение искомого элемента: "; 
	cin >> searchKey;
	elementIndex = lineSearch(array, ArraySize, searchKey);
	if (elementIndex != -1)
		cout << "Индекс искомого элемента равен: " << elementIndex << endl;
	else cout << "Искомый элемент не найден!" << endl;

}

