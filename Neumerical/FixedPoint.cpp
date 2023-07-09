/**
 *    author: A K M S Limon
 *    created: 17-June-2023  20:34:17
**/
#include <bits/stdc++.h>
using namespace std;

double cnterror(double c, double c0){
    return abs(c-c0)/c;
}

double f(double x){
    return 3*x-cos(x)-1;
}

double g(double x){
    return (cos(x)+1)/3;
}

double FixedPosition(double c0, double ea){
    double ca = 1, c;
    while(ca>ea){
        c = g(c0);
        if(f(c)==0) break;
        ca = cnterror(c, c0);
        c0 = c;
    }
    return c;
}
int main() {
    double c0=3.2, ea=0.000001; //For trigonometry, log, exponentiation c0 = 3.2, otherwise c0 = 0.5
    double root = FixedPosition(c0, ea);
    cout<<root<<'\n';
    return 0;
}