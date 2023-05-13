// Задача 4.
// Необходимо отсортировать первые две трети массива в порядке 
// возрастания, если среднее арифметическое всех элементов больше 
// нуля; иначе - лишь первую треть. Остальную часть массива не 
// сортировать, а расположить в обратном порядке. 


#include<iostream>
#include<conio.h>

using namespace std;

const int arrayLimit = 50;

// создание рандомного массива
void randomArrayInput(int array[], int lines);
// вывод массива на экран
void arrayOutput(int array[], int lines);
// расчет среднего арифметического
double arithmeticMean(int array[], int lines, double arithmeticMeanArray);
// сортировка массива по возрастанию
void sortingArrayIncreace(int array[], int lines);
// сортировка массива в обратном порядке
void sortingArrayReverse(int array[], int lines, int partArray);
// вывод отсортированного массива
void sortedArrayOutput(int array[], int lines, int partArray);

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	const int LINES_ARRAY = 20;
	int array[arrayLimit];
	double arithmeticMeanArray = 0;
	int partArray = 0;

	cout << endl;
	cout.width(37);
	cout << "Сортировка массива" << endl;

	randomArrayInput(array, LINES_ARRAY);

	cout << "\n--------------------------------------------------------\n" << endl;
	cout << "Рандомный массив. Вывод данных: " << endl;
	cout << endl;

	arrayOutput(array, LINES_ARRAY);

	cout << endl;
	cout << "\n--------------------------------------------------------\n" << endl;

	cout << "Среднее aрифметическое массива. Вывод данных: ";

	arithmeticMeanArray = arithmeticMean(array, LINES_ARRAY, arithmeticMeanArray);

	cout << arithmeticMeanArray;
	cout << endl;
	cout << "\n--------------------------------------------------------\n" << endl;
	cout << "Сортировка массива." << endl;
	cout << endl;

	if (arithmeticMeanArray < 0)
	{
		cout << "Среднее aрифметическое массива меньше нуля." << endl;
		cout << endl;
		cout << "Условия сортировки:" << endl;
		cout << "- 1/3 массива сортируется по возрастанию;" << endl;
		cout << "- 2/3 массива переворачивается;" << endl;
		cout << endl;

		partArray = LINES_ARRAY / 3;

		sortingArrayIncreace(array, partArray);

		sortingArrayReverse(array, LINES_ARRAY, partArray);

		sortedArrayOutput(array, LINES_ARRAY, partArray);

		cout << endl;
		cout << "\n--------------------------------------------------------\n" << endl;
	}
	else
	{
		cout << "Среднее aрифметическое массива больше нуля." << endl;
		cout << endl;
		cout << "Условия сортировки:" << endl;
		cout << "- 2/3 массива сортируется по возрастанию;" << endl;
		cout << "- 1/3 массива переворачивается;" << endl;
		cout << endl;

		partArray = (LINES_ARRAY * 2) / 3;

		sortingArrayIncreace(array, partArray);

		sortingArrayReverse(array, LINES_ARRAY, partArray);

		sortedArrayOutput(array, LINES_ARRAY, partArray);

		cout << endl;
		cout << "\n--------------------------------------------------------\n" << endl;
	}

	cout << "Конец программы." << endl;

	return 0;
}

void randomArrayInput(int array[], int lines)
{
	for (int i = 0; i < lines; i++)
	{
		array[i] = rand() % (100 - (-100) + 1) + (-100);
	}
}

void arrayOutput(int array[], int lines)
{
	cout << "|";

	for (int i = 0; i < lines; i++)
	{
		cout.width(4);
		cout << array[i] << " |";
		if ((i + 1) % 9 == 0)
		{
			cout << endl;
			cout << "|";
		}
	}
}

double arithmeticMean(int array[], int lines, double arithmeticMeanArray)
{
	double summ = 0;

	for (int i = 0; i < lines; i++)
	{
		summ += array[i];
	}

	arithmeticMeanArray = summ / lines;

	return arithmeticMeanArray;
}

void sortingArrayIncreace(int array[], int lines)
{
	int temp = 0;

	for (int k = 0; k < lines; k++)
	{
		for (int i = lines - 1; i > k; i--)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
			}
		}
	}
}

void sortingArrayReverse(int array[], int lines, int partArray)
{
	int temp = 0;

	for (int i = partArray, j = lines - 1; i < j; i++, j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void sortedArrayOutput(int array[], int lines, int partArray)
{
	cout << "|";

	for (int i = 0; i < partArray; i++)
	{
		cout.width(4);
		cout << array[i] << " |";
		if ((i + 1) % 9 == 0)
		{
			cout << endl;
			cout << "|";
		}
	}

	cout << "|";

	for (int i = partArray; i < lines; i++)
	{
		cout.width(4);
		cout << array[i] << " |";
		if ((i + 1) % 9 == 0)
		{
			cout << endl;
			cout << "|";
		}
	}
}