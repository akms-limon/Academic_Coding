#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x * x * x + 3 * x * x - 5 * x + 1;
}

double dF(double x)
{
    return 3 * x * x + 6 * x - 5;
}

int main()
{
    float es, r, e = 0, rold;
    cout << "Function is x^3 + 3x^2 - 5x + 1" << endl;
    cout << "Estimate root: ";
    cin >> rold;

    cout << "Estimate error: ";
    cin >> es;

    float er;
    do
    { 
        rold = r;
        r = rold - (f(rold) / dF(rold));
        er = fabs((r - rold) / r) * 100;
        e++;
    } while (er > es);

    cout << "Root is " << r << endl;
    
    return 0;
}