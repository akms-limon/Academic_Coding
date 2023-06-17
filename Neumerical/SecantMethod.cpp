/**
 *    author: A K M S Limon
 *    created: 17-June-2023  21:18:21
**/
#include <bits/stdc++.h>
using namespace std;

double cnterror(double c2, double c1){
    return abs(c2-c1)/c2;
}

double f(double x){
    return 3*x-cos(x)-1;
}

double Secant(double c0, double c1, double ea){
    double ca = 1, c2;
    while(ca>ea){
        c2 = c1-f(c1)*((c1-c0)/(f(c1)-f(c0)));
        if(f(c2)==0) break;
        c0=c1;
        c1=c2;
        ca = cnterror(c1, c0);
    }
    return c2;
}

int main() {
    double c0, c1; cin>>c0>>c1;
    double ea = 0.00000001;
    double root = Secant(c0, c1, ea);
    cout<<root<<'\n';  
    return 0;
}