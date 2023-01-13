#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[], int x, double b[])
{
    int i = 0;
    for (i = 0; i < x; i++)
    {
        b[0] += a[i];
        b[1] += pow(a[i], 2);
        b[2] += log10(a[i]);
        b[3] += 1 / a[i];
    }
    b[0] = b[0] / x;
    b[1] = sqrt((b[1] / x) - (pow(b[0], 2)));
    b[2] = pow(10, b[2] / x);
    b[3] = x / b[3];

    double min = a[0];
    for (int i = 0; i < x; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            b[5] = min;
        }
    }

    double max = a[0];
    for (int i = 0; i < x; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            b[4] = max;
        }
    }
}