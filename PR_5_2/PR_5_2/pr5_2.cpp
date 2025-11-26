#include <iostream>  
#include <cmath>
#include <iomanip>

using namespace std;

double A(const double x, const int n, double a);

double S(const double x, const double eps, int& n);

int main()
{
    double xp, xk, x, dx, eps, s;
    int n;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;

    if (abs(xp) <= 1.0) {
        cout << "Error: |xp| must be > 1.\n";
        return 1;
    }

    cout << fixed;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << "|"
        << setw(22) << "f(x) = ln((x+1)/(x-1))" << "|"
        << setw(22) << "S * 2" << "|"
        << setw(6) << "n" << "|"
        << endl;
    cout << "-----------------------------------------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (abs(x) <= 1.0) {
            cout << "|" << setw(10) << setprecision(3) << x << "|"
                << setw(22) << "Undefined" << "|"
                << setw(22) << "Undefined" << "|"
                << setw(6) << " " << "|"
                << endl;
        }
        else {
            s = S(x, eps, n);

            cout << "|" << setw(10) << setprecision(3) << x << "|"
                << setw(22) << setprecision(15) << log((x + 1) / (x - 1)) << "|"
                << setw(22) << setprecision(15) << s * 2 << "|"
                << setw(6) << n << "|"
                << endl;
        }

        x += dx;
    }
    cout << "-----------------------------------------------------------------" << endl;

    return 0;
}

double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = 1.0 / x;
    double s = a;

    while (abs(a) >= eps) {
        n++;
        a = A(x, n - 1, a);

        if (abs(a) >= eps) {
            s += a;
        }
    }
    n++;
    return s;
}

double A(const double x, const int n, double a)
{
    double R = (double)(2 * n + 1) / (2 * n + 3) / (x * x);
    return a * R;
}