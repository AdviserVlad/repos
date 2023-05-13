/// inLine функции 
// Встраивание кода

#include <iostream>
#include <Windows.h>

#define SQR(X) ((X) * (X))  // SQR(X) X * X  
#define CUBE(X) (SQR(X)*(X)) 
#define ABS(X) (((X) < 0)? -(X) : X)
#define PI 3.14159

using namespace std;

inline float module(float x = 0, float у = 0)
{
	return sqrt(x * x + у * у);
}

int main()
{
	float x = 3, y = 4, a;
	a = module(x, y);
	cout << a;

	int t = 10;
	y = SQR(t + 8) - CUBE(t - 8);   
	// для программы выглядит так:
	// у = ((t+8) * (t+8)) - ((((t-8)) * (t-8)) * (t-8));
	cout << sqrt(ABS(y));   
	//cout << sqrt(((y < 0) ? -(y) : y));

}

