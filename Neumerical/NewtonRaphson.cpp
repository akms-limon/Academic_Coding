/**
 *    author: A K M S Limon
 *    created: 17-June-2023  20:46:15
**/
#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return 3*x-cos(x)-1;
}

double df(double x){
    return 3+sin(x);
}

double cnterror(double c0,double c){
    return abs(c0-c)/c;
}

double NewtonRaphson(double c0, double ea){
    double ca=1,c;
    while(ca>ea){
        c=c0-(f(c0)/df(c0));
        if(f(c)==0) break;
        ca=cnterror(c0,c);
        c0 = c;
    }
    return c;
}

int main() {
    double c0, ea = 0.000001;
    cin>>c0;
    double root = NewtonRaphson(c0, ea);
    cout<<root<<'\n';
    return 0;
}