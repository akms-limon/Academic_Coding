#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x + x * x - 3 * x - 5;
}

void muller(double xr, double h, double eps) {
    double x2 = xr;
    double x1 = xr + h * xr;
    double x0 = xr - h * xr;
    int iter = 0, maxit = 1000;
    double dxr;

    do {
        iter++;
        double h0 = x1 - x0;
        double h1 = x2 - x1;
        double d0 = (f(x1) - f(x0)) / h0;
        double d1 = (f(x2) - f(x1)) / h1;
        double a = (d1 - d0) / (h1 + h0);
        double b = (a * h1) + d1;
        double c = f(x2);
        double rad = sqrt((b * b) - (4 * a * c));
        double den;
        if (abs(b + rad) > abs(b - rad)) {
            den = b + rad;
        } else {
            den = b - rad;
        }

        dxr = -2 * c / den;
        xr = x2 + dxr;

        cout << "Iter: " << iter << " root: " << xr << endl;

        if ((abs(dxr) < eps * abs(xr)) || iter >= maxit) {
            return;
        }

        x0 = x1;
        x1 = x2;
        x2 = xr;
    } while (true);
}

int main() {
    double xr = 2, eps = 0.0000001;
    cout << "Enter estimate root: ";
    cin >> xr;

    // cout << "Enter tolarance error: ";
    // cin >> eps;
    muller(xr, 0.1, eps);
}