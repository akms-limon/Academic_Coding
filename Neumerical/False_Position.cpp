#include <cmath>
#include <iostream>
using namespace std;

/**
 * To calculate the volue of f(x) of an equation
 */
double f(double x) {
    // replace this with the actual function you want to find the root of
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

// Prints root of func(x) in interval [a, b]
double regulaFalsi(double a, double b) {
    cout << "Loading..." << endl;
    int MAX_ITER = 1e6;
    double c = a;  // Initialize result

    for (int i = 0; i < MAX_ITER; i++) {
        // Find the point that touches x axis
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Check if the above found point is root
        if (f(c) == 0)
            break;

        // Decide the side to repeat the steps
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double low, high;
    cout << "The function x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Enter range to find the root: ";
    cin >> low >> high;

    if (f(low) * f(high) > 0) {
        cout << "Root may not be lie" << endl;
        exit(0);
    }

    double root = regulaFalsi(low, high);
    cout << "Root of the function " << root << endl;

    return 0;
}