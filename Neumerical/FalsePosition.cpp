/**
 *    author: A K M S Limon
 *    created: 17-June-2023  20:12:21
**/
#include <bits/stdc++.h>
using namespace std;
 
double cnterror(double c0, double c){
    return abs(c-c0)/c;
}

double f(double x ){
    return 3*x-cos(x)-1;
}

double FalsePosition(double a, double b, double ea){
    double ca = 1, c0, c = b;
    int i = 1;
    while(ca>ea){
        c0 = c;
        c = (a*f(b)-b*f(a))/(f(b)-f(a));
        if(f(c)==0){
            break;
        }
        if(f(a)*f(c)>0){
            a = c;
        }
        else {
            b = c;
        }
        ca = cnterror(c0, c);
    }
    return c;
}

int main() {
    double a, b, ea = 0.00000001; cin>>a>>b;
    double root = FalsePosition(a, b, ea);
    cout<<root<<endl;
    return 0;
}