// Рекурсия — это прием программирования, при кото-
// ром функция вызывает саму себя либо непосредственно,
// либо косвенно
// N! = 1 * 2 * 3 * ... * N
// N! = N * (N-1)!
//«Для того, чтобы понять рекурсию, надо просто понять рекурсию» :)

#include <iostream>
#include <windows.h>

using namespace std;

long int fact(long int N)
{
	// если произведена попытка вычислить
	// факториал нуля
	if (N < 1) return 0;
	/* если вычисляется факториал единицы
	именно здесь производится выход из рекурсии
	*/
	else if (N == 1) return 1;
	// любое другое число вызывает функцию заново
	// с формулой N-1
	else return N * fact(N - 1);
}

long int fact2(long int N)
{
	long int F = 1;
	// цикл осуществляет подсчет факториала
	for (int i = 2; i <= N; i++)
		F *= i;
	return F;
}




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
	long number = 5;
	// первый вызов рекурсивной функции
	long result = fact(number);
	cout << "Результат " << number << "! это - " << result << "\n";

}

