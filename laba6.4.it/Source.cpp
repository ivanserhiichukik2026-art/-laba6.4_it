
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Input(double a[], int n) // введення масиву
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Print(const double a[], int n) // виведення масиву
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << fixed << setprecision(2) << a[i];
    }

    cout << endl;
}

int Max(const double a[], int n) // пошук індексу максимального за модулем елемента
{
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) > abs(a[index]))
        {
            index = i;
        }
    }

    return index;
}

double Sum(const double a[], int n) // сума елементів після першого додатного 
{
    int index = -1; // спочатку додатного числа ще не знайшли

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            index = i;
            break; // потрібно лише перше додатньє
        }
    }

    if (index == -1) // якщо додатного числа немає, повертаємо ноль
    {
        return 0;
    }

    double sum = 0;

    for (int i = index + 1; i < n; i++) // index + 1, щоб не додавати саме перше додатне число
    {
        sum += a[i];
    }

    return sum;
}

bool Check(double x, int low, int high) // перевірка цілої частини числа на належність інтервалу
{
    int c = (int)x; // x в ціле число

    return c >= low && c <= high;
}

void Change(double a[], int n, int low, int high) // переставляння елементів масиву
{
    double* b = new double[n]; // спочатку записать потрібний рядок в b , а потім в а
    int k = 0;

    for (int i = 0; i < n; i++) // переносим числа які підходять
    {
        if (Check(a[i], low, high))
        {
            b[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++) // переносим всі інші числа які не входять в інтервал
    {
        if (!Check(a[i], low, high))
        {
            b[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++) // копіруєм кожен ел. з  б в а
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
    Input(a, n);

    cout << "Original array:" << endl;
    Print(a, n);

    cout << "Max abs index = " << Max(a, n) << endl; // .

    cout << "Sum after first positive = " << Sum(a, n) << endl;

    Change(a, n, low, high);

    cout << "Modified array:" << endl;
    Print(a, n);

    delete[] a;

    return 0;
}
