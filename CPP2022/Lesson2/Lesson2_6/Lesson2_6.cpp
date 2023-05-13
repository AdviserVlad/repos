// Шаблон функций
//

#include <iostream>
#include <Windows.h>

using namespace std;
//шаблон функции для разных типов данных
// template <typename T> T Max_Element(int size, T Array[])
//Например          int Max_Element(int size, int Array[])

template <typename T> T max_element(int size, T array[])
{
	T max = array[0];
	for (int i = 0; i < size; i++)
	{
		max = max > array[i] ? max : array[i];
	}
	return max;
}

template <typename T1, typename T2>
T1 myMAX(T1 A, T2 B)
{
	return A > B ? A : B;
}

int main()
{
	//setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	const int arraySize = 10;
	int arrayInt[arraySize];
	double arrayDouble[arraySize];
	char arrayChar[arraySize];
	for (size_t i = 0; i < arraySize; i++)
	{
		arrayInt[i] = rand() % (100 - (-100)) - 100;
		arrayDouble[i] = (rand() % (100 - (-100)) - 100) / 3.0;  //double
		arrayChar[i] = (char)rand() % 255;    //char
		cout << arrayInt[i] << "\t" << arrayChar[i] << "\t" << arrayDouble[i] << endl;
	}
	cout << "Максимальный INT: " << max_element(arraySize, arrayInt) << endl;
	cout << "Максимальный DOUBLE: " << max_element(arraySize, arrayDouble) << endl;
	cout << "Максимальный CHAR: " << max_element(arraySize, arrayChar) << endl;
		
	cout << "Max from 8 and 5 = " << myMAX(8, 5);

}

