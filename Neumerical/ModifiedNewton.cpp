/**
 *    author: A K M S Limon
 *    created: 17-June-2023  20:56:22
**/
#include <bits/stdc++.h>
using namespace std;

double cnterror(double c,double c0){
    return abs(c-c0)/c;
}

double f(double x){
    return x*x*x+1.2*x*x-4*x-4.8;
}

double dif1(double x){
    return 3*x*x+2.4*x-4;
}

double dif2(double x){
    return 6*x+2.4;
}

double ModifiedNewton(double c0,double ea){
    double ca=1,c=c0;
    while(ca>ea){
        c0 = c;
        c = c0 - (f(c)*dif1(c))/(dif1(c)*dif1(c) - f(c)*dif2(c));
        if(f(c)==0) break;
        ca = cnterror(c, c0);
    }
    return c;
}

int main() {
    double c0,ea=0.0000000001;
    cin>>c0;
    double root=ModifiedNewton(c0,ea);
    cout<<root<<endl;
    return 0;
}