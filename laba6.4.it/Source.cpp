#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void readArray(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(const double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << fixed
            << setprecision(2) << a[i];
    }

    cout << endl;
}

int maxAbsIndex(const double a[], int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (fabs(a[i]) > fabs(a[index]))
        {
            index = i;
        }
    }

    return index;
}

double sumAfterPositive(const double a[], int n)
{
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return 0;
    }

    double sum = 0;

    for (int i = index + 1; i < n; i++)
    {
        sum += a[i];
    }

    return sum;
}

bool belongs(double x, int low, int high)
{
    int part = (int)x;

    return part >= low && part <= high;
}

void rearrange(double a[], int n, int low, int high)
{
    double* b = new double[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (belongs(a[i], low, high))
        {
            b[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!belongs(a[i], low, high))
        {
            b[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

    delete[] b;
}

int main()
{
    int n;
    int low, high;

    cout << "Enter n: ";
    cin >> n;

    if (!cin || n <= 0)
    {
        return 1;
    }

    cout << "Enter a and b: ";
    cin >> low >> high;

    if (!cin || low > high)
    {
        return 1;
    }

    double* a = new double[n];

    cout << "Enter array elements:" << endl;
    readArray(a, n);

    cout << "Original array:" << endl;
    printArray(a, n);

    cout << "Max abs index = "
        << maxAbsIndex(a, n) << endl;

    cout << "Sum after first positive = "
        << sumAfterPositive(a, n) << endl;

    rearrange(a, n, low, high);

    cout << "Modified array:" << endl;
    printArray(a, n);

    delete[] a;

    return 0;
}