#include <bits/stdc++.h>

using namespace std;
double f(double x) {
    return x * x * x - 5 * x - 9;
}

double mullerMethod(double x1, double x2, double x3, double eps) {
    double error = INT_MAX;
    double x4;
    while (error > eps) {
        double h1 = x2 - x1;
        double h2 = x3 - x2;
        double d1 = (f(x2) - f(x1)) / h1;
        double d2 = (f(x3) - f(x2)) / h2;
        double d = (d2 - d1) / (h2 + h1);
        double a = d;
        double b = d2 + h2 * a;
        double c = f(x3);
        double rad = sqrt(b * b - 4 * a * c);
        x4 = x3 - (2 * c) / (b + ((b > 0) ? rad : -rad));
        error = fabs(((x4 - x3) / x4) * 100);
        x1 = x2;
        x2 = x3;
        x3 = x4;
    }

    return x4;
}

int main() {
    double x3, x1, x2, eps;
    cout << "Enter three estimate root: ";
    cin >> x1 >> x2 >> x3;
    cout << "Enter tolarance error: ";
    cin >> eps;
    double root = mullerMethod(x1, x2, x3, eps);
    cout << "The root is: " << root << endl;
    return 0;
}