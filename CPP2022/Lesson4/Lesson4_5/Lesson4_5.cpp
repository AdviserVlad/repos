// ССЫЛКИ 2 Передача аргументов по ссылке
//
#include <iostream>
#include <time.h>

using namespace std;

//функция swap через указатели
void Swap_pointer(int* pX, int* pY)
{
	int tmp = *pX;
	*pX = *pY;
	*pY = tmp;
}

//функция swap через ссылки
void Swap_reference(int& refX, int& refY)
{
	int tmp = refX;
	refX = refY;
	refY = tmp;
}


//функция возвращает ссылку на максимальный элемент для замены его на 0
int& Ref_max_elem(int Array[], int size)
{
	int index_max = 0;
	for (int i = 1; i < size; i++)
	{
		index_max = Array[index_max] > Array[i] ? index_max : i;
	}
	cout << "\nМаксимальный элемент A[" << index_max << "]= " << Array[index_max] << ";\n" << endl;
	return Array[index_max];
}


int& rf(int index); // Прототип функции.
int a[10][2];



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int A, B;
	A = rand() % (100 - (-100)) - 100;
	B = rand() % (100 - (-100)) - 100;
	cout << "A= " << A << "; B= " << B << endl;
	Swap_pointer(&A, &B); // Передаем адреса
	cout << "A= " << A << "; B= " << B << endl;
	Swap_reference(A, B); // Передаем переменные
	cout << "A= " << A << "; B= " << B << endl;

	const int size_A = 50;
	int Array[size_A];
	for (int i = 0; i < size_A; i++)
	{
		Array[i] = rand() % (100 - (-100)) - 100;
		cout << "A[" << i << "]= " << Array[i] << "; ";
	}
	cout << endl;
	int maxElement = Ref_max_elem(Array, size_A);
	Ref_max_elem(Array, size_A) = 0; //помещаем в результат функции по ссылке на 
	//максимальный элемент значение 0	
	for (int i = 0; i < size_A; i++)
	{
		cout << "A[" << i << "]= " << Array[i] << "; ";
	}
	cout << endl;

	cout << "maxElement= " << maxElement << endl;
	
	//=== Заполнение массива
	int b;
	cout << "Fill array.\n";
	cin >> b;
	for (int i = 0; i < 10; i++)
	{
		//cout << i + 1 << " element:";
		//cin >> b;
		a[i][0] = b;
		rf(i) = b;
	}
	cout << "Show array.\n";
	cout << "1-st column 2-nd column" << "\n";
	for (int i = 0; i < 10; i++)
		cout << a[i][0] << "\t\t" << rf(i) << "\n";
}

int& rf(int index)
{
	return a[index][1]; // Возврат ссылки на элемент массива.
}

