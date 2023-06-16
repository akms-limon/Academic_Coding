#include <math.h>

#include <iostream>
using namespace std;

float fn(float x) {
    return x * x + (3 * x) + 1;
}

float de(float x) {
    return 2 * x + 3;
}

int main() {
    float a, e = 0, z;
    cout << "Function is x^2 + 3x + 1" << endl;
    cout << "Enter Number: ";
    cin >> a;
    float es, err;
    cout << "Estimate precision: ";
    cin >> es;

    do {
        e++;
        z = a - (fn(a) / de(a));
        err = fabs((z - a) / z) * 100;
        cout << "The iterative " << e << " root is " << z << " error is " << err << endl;
        a = z;
    } while (err > es);

    cout << "The root is " << z << endl;
    return 0;
}