// ССЫЛКИ
// <имя типа>& <имя ссылки> = <выражение>; 
// <имя типа>& <имя ссылки>(<выражение>);


#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int X = 15;
	//ссылка на значение переменной X
	int& refX = X;
	cout << "X= " << X << endl;
	cout << "X= " << refX << endl;
	
	X += 15;
	cout << "X= " << X << endl;
	cout << "X= " << refX << endl;
	
	refX += 15;
	cout << "X= " << X << endl;
	cout << "X= " << refX << endl;
	
	int Y = 17;
	int& refY = Y;
	//присвоение значения переменной X по ссылке (refX) значения переменной Y
	refX = Y;
	//присвоение значения переменной X по ссылке (refX) значения переменной Y
	//по ссылке (refY)
	refX = refY;
	cout << "X= " << X << endl;
	cout << "X= " << refX << endl;
	X++;
	refX = X + Y;
	cout << "X= " << X << endl;
	cout << "X= " << refX << endl;

	int* ptrX = &X; //указатель на переменную X
	int* prefX = &refX; //указатель на ссылку
	//В указатель prefX будет помещен адресс содержимого,
	//находящегося по ссылке refX (адрес переменной X)
	cout << "Переменная X " << X << endl;
	cout << "Ссылка на перемнную X " << refX << endl;
	cout << "Указатель на X - ptrX " << ptrX << endl;
	cout << "Разыменованный указатель на X - ptrX " << *ptrX << endl;
	cout << "Указатель на ссылку refX - prefX " << prefX << endl;
	cout << "Разыменованный указатель на на ссылку refX - prefX " << *prefX << endl;

	int* ptrN = nullptr;
	{
		int N = 37;
		ptrN = &N;
		cout << "N= " << N << endl;
		cout << "ptrN= " << ptrN << endl;
		cout << "*ptrN= " << *ptrN << endl;
		*ptrN += 3;
		cout << "N= " << N << endl;
		cout << "ptrN= " << ptrN << endl;
		cout << "*ptrN= " << *ptrN << endl;
		//ptrN = nullptr; //после окончания жизни объекта 
		//указатель на объект нужно обнулить, либо не использовать
		//либо заставить указывать на другой объект
	}
	*ptrN += 3;
	//cout << "N= " << N << endl;
	cout << "ptrN= " << ptrN << endl;
	cout << "*ptrN= " << *ptrN << endl;

	//ссылка на указатель
	int M = 70;
	int* ptrM = &M;
	int*& ref_ptrM = ptrM;
	cout << "ref_ptrM= " << ref_ptrM << endl;
	cout << "&ref_ptrM= " << &ref_ptrM << endl;
	cout << "&ptrM= " << &ptrM << endl;
	{
		int P = 90;
		int& refP = P;
		refP += 10;
		cout << "P= " << P << endl;
		cout << "refP= " << refP << endl;
		//ref_ptrM = &P;
		//ref_ptrM = P;
	}
	//cout << "P= " << P << endl;
	//cout << "refP= " << refP << endl;
	cout << "ref_ptrM= " << ref_ptrM << endl;
	cout << "&ref_ptrM= " << &ref_ptrM << endl;
	cout << "M= " << M << endl;
	cout << "&ptrM= " << &ptrM << endl;



}

