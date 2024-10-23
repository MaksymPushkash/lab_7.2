#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);

void Print(int** a, const int k, const int n); 

int SumMinEvenColumns(int** a, const int k, const int n); 


int main() 
{
    srand((unsigned)time(NULL));

    int Low = 1;  
    int High = 50;  
    int k, n;

    cout << "Введіть кількість рядків (k): "; cin >> k;
    cout << "Введіть кількість стовпців (n): "; cin >> n;

    
    int** a = new int* [k];
    for (int i = 0; i < k; i++) 
    {
        a[i] = new int[n];
    }

    
    Create(a, k, n, Low, High);
    Print(a, k, n);

    
    int sum = SumMinEvenColumns(a, k, n);
    cout << "Сума мінімальних елементів у парних стовпцях: " << sum << endl;

    
    for (int i = 0; i < k; i++) 
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


void Create(int** a, const int k, const int n, const int Low, const int High) 
{
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}


void Print(int** a, const int k, const int n) 
{
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


int SumMinEvenColumns(int** a, const int k, const int n) 
{
    int sum = 0;  

    for (int j = 0; j < n; j += 2) 
    {  
        int min = a[0][j];  
        for (int i = 1; i < k; i++) 
        {
            if (a[i][j] < min) 
            {
                min = a[i][j]; 
            }
        }
        sum += min;  
    }
    
    return sum;
}