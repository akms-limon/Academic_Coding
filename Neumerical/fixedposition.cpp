#include <bits/stdc++.h>
using namespace std;

double g(double x)
{
    return (-x * x * x * x + 3 * x * x * x - 5 * x * x + 5) / 5;
}

double fixedpos(double low, double es, double &ea, int &it)
{
    it = 1e9;
    double xrold, xr = low;
    while (it--)
    {
        xrold = xr;
        xr = g(xrold);
        if (xr != 0)
        {
            ea = fabs((xr - xrold) / xr) * 100;
        }
        if (ea < es)
        {
            break;
        }
    }
    return xr;
}

int main()
{
    double low;
    cout << "The function x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Estimate root:" << endl;
    cin >> low;
    int it;
    double es, ea;
    cin >> es;
    double root = fixedpos(low, es, ea, it);
    cout << "Root of the function : " << root << endl;
    cout << "Approximate error: " << ea << endl;
    cout << "Number of iteration: " << 1e9 - it << endl;
    return 0;
}