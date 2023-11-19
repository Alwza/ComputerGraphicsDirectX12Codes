// written with vs code 

#include <iostream>
#include <math.h>

using namespace std;

void getMatrix(double **matrix, int size);
void display(double **matrix, int size);
void multiplyNumberMatrix(int number, double **matrix , int size);
void transposeMatrix(double **matrix, int size);
double determinant(double **matrix, int n);
void submatrix(double **mat, double **temp, int p, int q, int size);
void nimsaz(double **kehad, int size);
void inverse(double **matrix, int size);

int main()
{
    int check;
    cout << "\n\nHiiii Welcome to our program , Matrix calculator \n\nWhat dou you want to do ??\n\nEnter 1 for transpose , 2 for determinant , 3 for inverse : ";
    cin >> check;
    int size;
    cout << "\nEnter the size of the matrix : ";
    cin >> size;

    double **matrix = new double *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
    }

    getMatrix(matrix, size);

    if (check == 1)
    {
        transposeMatrix(matrix, size);
        display(matrix, size);
    }
    else if (check == 2)
    {
        cout << "\nThe determenant of matrix is : " << determinant(matrix, size) << "\n\n";
    }
    else if (check == 3)
    {
        inverse(matrix, size);
    }
}

void getMatrix(double **matrix, int size)
{
    cout << "\nEnter the elements of matrix : \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void display(double **matrix, int size)
{
    cout << "\nThe result is :\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "| ";
        for (int j = 0; j < size; j++)
        {
            cout << "\t" << matrix[i][j] << "\t";
        }
        cout << "|\n\n";
    }
}

void multiplyNumberMatrix(int number, double **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] *= number;
        }
    }
}

void transposeMatrix(double **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

double determinant(double **matrix, int size)
{
    double det = 0;
    if (size == 1)
    {
        det == matrix[0][0];
        return det;
    }
    else if (size == 2)
    {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
        return det;
    }
    else
    {
        double **submatrix = new double *[size - 1];
        for (int j = 0; j < size - 1; j++)
        {
            submatrix[j] = new double[size - 1];
        }
        for (int x = 0; x < size; x++)
        {
            int subi = 0;
            for (int i = 1; i < size; i++)
            {
                int subj = 0;
                for (int j = 0; j < size; j++)
                {
                    if (j != x)
                    {
                        submatrix[subi][subj] = matrix[i][j];
                        subj++;
                    }
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, size - 1));
        }
    }
    return det;
}

void submatrix(double **mat, double **temp, int p, int q, int size)
{
    int i = 0, j = 0;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            if (row != p && column != q)
            {
                temp[i][j++] = mat[row][column];
                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void nimsaz(double **kehad, int size)
{
    int sign = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            kehad[i][j] *= sign;
            sign *= -1;
        }
        sign *= -1;
    }
}

void inverse(double **matrix, int size)
{
    double **temp = new double *[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = new double[size];
    }
    double **kehad = new double *[size];
    for (int i = 0; i < size; i++)
    {
        kehad[i] = new double[size];
    }
    int det = determinant(matrix, size);
    if (det == 0)
    {
        cout << "Does NOT have inverse !!"
             << "\n\n";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                submatrix(matrix, temp, i, j, size);
                kehad[i][j] = determinant(temp, size - 1);
            }
        }
        nimsaz(kehad, size);
        transposeMatrix(kehad,size);
        multiplyNumberMatrix(1/det , kehad,size);
        display(kehad,size);
    }
}