// Перегрузка функций
//

#include <iostream>
using namespace std;

long max_element(int size, int array[])
{
	long max = array[0];
	for (int i = 0; i < size; i++)
	{
		max = max > array[i] ? max : array[i];
	}
	cout << "Для типа int: ";
	return max;
}

long max_element(int size, long array[])
{
	long max = array[0];
	for (int i = 0; i < size; i++)
	{
		max = max > array[i] ? max : array[i];
	}
	cout << "Для типа long: ";
	return max;
}

double max_element(int size, float array[])
{
	double max = array[0];
	for (int i = 0; i < size; i++)
	{
		max = max > array[i] ? max : array[i];
	}
	cout << "Для типа float: ";
	return max;
}

double max_element(int size, double array[])
{
	double max = array[0];
	for (int i = 0; i < size; i++)
	{
		max = max > array[i] ? max : array[i];
	}
	cout << "Для типа double: ";
	return max;
}

double multy(double x)
{
	return 2 * x;
}
double multy(double x, double y)
{
	return x * y;
}
double multy(double x, double y, double z)
{
	return x * y * z;
}
//с параметрами по умолчанию нужно быть осторожными, чтобы не вызвать 
// неопределенность в выборе конкретной функции
//double multy(double x, double y, double z = 2.14, double w = 3.14)
//{
//	return x * y * z * w;
//}


int main()
{
	setlocale(LC_ALL, "rus");
	
	int x = 9, y = 7;
	
	int A[5] = { 1,2,3,4,5 };
	long B[5] = { 11L,12L,13L,14L,15L };
	float C[5] = { 0.1,0.2,0.3,0.4,0.5 };
	double D[5] = { 0.01,0.02,0.03,0.04,0.05 };
	cout << max_element(5, A) << endl;
	cout << max_element(5, B) << endl;
	cout << max_element(5, C) << endl;
	cout << max_element(5, D) << endl;
	//max(x,y);
	cout << multy(0.4) << endl;
	cout << multy(0.4, 3.14) << endl;
	cout << multy(0.4, 3.14, 2.2) << endl;
//	cout << multy(0.4, 3.14, 2.2, 1.5) << endl;



}

