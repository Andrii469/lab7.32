#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;


//ĞÅÊÓĞÑÈÂÍÈÉ ÑÏÎÑ²Á
void CreateMatrix(int** a, const int n, const int low, const int high, int i, int j);
void PrintMatrix(int** a, const int n, int i, int j);
void Search(int** a, int* row, int* col, const int n, int i, int num, int f, int r);
int Suma(int** a, int n, int S, int i, int num);
int find(int** a, const int n, int i, int num);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    int low = -35;
    int high = 45;

    cout << "Ââåä³òü ğîçì³ğ êâàäğàòíî¿ ìàòğèö³ ğîçì³ğîì (n*n): "; cin >> n;


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    int* Row = new int[n];
    int* Col = new int[n];


    //ĞÅÊÓĞÑÈÂÍÈÉ ÑÏÎÑ²Á
    cout << "\\ĞÅÊÓĞÑÈÂÍÈÉ ÑÏÎÑ²Á:" << endl; cout << endl;
    CreateMatrix(a, n, low, high, 0, 0);
    PrintMatrix(a, n, 0, 0); cout << endl;
    cout << "S =";
    Search(a, Row, Col, n, 0, 0, 0, 0); cout << endl;
    cout << "\\Cóìà åëåìåíò³â ó òèõ ğÿäêàõ, ÿê³ ì³ñòÿòü õî÷à á îäèí â³ä’ºìíèé åëåìåíò: ";
    cout << Suma(a, n, 0, 0, 0) << endl;

    delete[] Col;
    delete[] Row;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


//ĞÅÊÓĞÑÈÂÍÈÉ ÑÏÎÑ²Á

void CreateMatrix(int** a, const int n, const int low, const int high, int i, int j)
{
    if (j < n)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return CreateMatrix(a, n, low, high, i, j + 1);
    }
    if (i < n - 1)
        return CreateMatrix(a, n, low, high, i + 1, 0);
}
void PrintMatrix(int** a, const int n, int i, int j)
{
    if (j < n)
    {
        cout << setw(4) << a[i][j];
        return PrintMatrix(a, n, i, j + 1);
    }
    cout << endl;
    if (i < n - 1)
        return PrintMatrix(a, n, i + 1, 0);
}
void Search(int** a, int* row, int* col, const int n, int i, int num, int f, int r)
{
    if (i < n)
    {
        row[f] = a[num][i];
        col[f] = a[i][num];
        if (row[f] == col[f])
            r++;
        if (r == n)
            cout << setw(3) << num + 1;
        f++;
        return Search(a, row, col, n, i + 1, num, f, r);
    }
    f = 0;
    r = 0;
    if (num < n - 1)
        return Search(a, row, col, n, 0, num + 1, r, f);
}
int Suma(int** a, int n, int S, int i, int num)
{
    if (i < n)
    {
        if (find(a, n, i, num) < 0)
            S += a[num][i];
        return Suma(a, n, S, i + 1, num);
    }
    i = 0;
    if (num < n - 1)
        return Suma(a, n, S, i, num + 1);
    return S;
}
int find(int** a, const int n, int i, int num)
{
    if (i < n)
    {
        if (a[num][i] < 0)
            return a[num][i];
        return find(a, n, i + 1, num);
    }
}