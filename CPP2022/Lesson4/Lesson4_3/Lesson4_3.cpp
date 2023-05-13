// Указатели с особенностями

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    //нулевой указатель в языке C
    int* pB = NULL;
    cout << pB << endl;
    //нулевой указатель в языке C++
    int* pC = nullptr;
    cout << pC << endl;
    //указатель со значением 0
    int* pD = 0;
    cout << pD << endl;
    if (pD == pC)cout << "Равно" << endl;

    

    if (pC == nullptr) {
        cout << "\n\nNull pointer was found!" << endl;
    }
    //========== Константный Указатель
    //тип_данных* const имя_указателя = адрес
    int A = 12;
    //константный указатель на тип int
    int* const pA = &A;
    cout << pA << endl;
    
    cout << *pA << endl;
    *pA = 37;
    cout << *pA << endl;
        
    int E = 55;
    //pA = &E; // нельзя менять адрес
    //pA = pD; // нельзя менять адрес
    
    
    //======указатель на константу
    const int* pE = nullptr;
    pE = &A;
    cout << *pE << endl;
    //*pE = 37;
    A = 45;
    cout << *pE << endl;

    const float PI = 3.14;
    //константный указатель на константу
    const float* pPI = &PI;
    //const float* const pPI = &PI;
    //pPI = pA;
    cout << pPI << endl;
    cout << *pPI << endl;




}
