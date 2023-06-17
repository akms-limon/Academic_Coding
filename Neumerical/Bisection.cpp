/**
 *    author: A K M S Limon
 *    created: 17-June-2023  19:27:20
**/
#include <bits/stdc++.h>
using namespace std;

double cnterror(double c0, double c){
    return abs(c0-c)/c;
}

double f(double x){
    return 3*x-cos(x)-1;
}

double Bisection(double a,double b, double ea){
    double ca=1, c=b, c0;
    while(ca>ea){
        c0 = c;
        c = (a+b)/2;
        if(f(c)==0) {
            break;
        }
        if(f(c)*f(a)<0){
            b = c;
        }
        else{
            a = c;
        }
        ca = cnterror(c0, c);
    }
    return c;
}

int main() {
    
    double a, b; cin>>a>>b;
    double ea = 0.0000000000001;
    double root = Bisection(a, b, ea);
    cout<<root<<endl;
    return 0;
}