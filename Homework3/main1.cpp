// written with vs code

#include <iostream>
#include <vector>
#include <string>
#define N 4

using namespace std;

void getMatrix(int a[N][N], int b[N][N]);
void display(int check[N][N]);
void add(int a[N][N], int b[N][N], int c[N][N]);
void mines(int a[N][N], int b[N][N], int c[N][N]);
void initializerr(int c[N][N]);
void multiply(int a[N][N], int b[N][N], int c[N][N]);

int main()
{
    cout << "\n\nHiiii welcome to our program , Matrix calculator\n\nwhat do you want to calculate\n\nEnter 1 for sum , 2 for subtraction , 3 for mal : ";
    int check;
    cin >> check;
    int a[N][N];
    int b[N][N];
    int c[N][N];
    getMatrix(a, b);
    if (check == 1)
    {
        add(a, b, c);
    }
    else if (check == 2)
    {
        mines(a, b, c);
    }
    else if (check == 3)
    {
        multiply(a, b, c);
    }
    display(c);
}
void display(int check[N][N])
{
    cout << "\nThe result is :\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "| ";
        for (int j = 0; j < N; j++)
        {
            cout << check[i][j] << " ";
        }
        cout << "|\n\n";
    }
}
void add(int a[N][N], int b[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void mines(int a[N][N], int b[N][N], int c[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void getMatrix(int a[N][N], int b[N][N])
{
    cout << "Enter the elements of matrix 1 : \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the elements of matrix 2 : \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> b[i][j];
        }
    }
}
void initializerr(int c[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
        }
    }
}
void multiply(int a[N][N], int b[N][N], int c[N][N])
{
    initializerr (c);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}