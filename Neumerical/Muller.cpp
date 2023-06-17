/**
 *    author: A K M S Limon
 *    created: 17-June-2023  21:29:28
**/
#include <bits/stdc++.h>
using namespace std;

double cnterror(double x3, double x2){
    return abs(x3-x2)/x3;
}

double f(double x){
    return x*x*x-13*x-12;
}

double Muller(double x0, double x1, double x2, double ea){
    double ca = 1, x3, h0, h1, y0, y1, a, b, c, det;
    while(ca>ea){
        h0 = x1-x0; 
        h1 = x2-x1;
        y0 = (f(x1)-f(x0))/(x1-x0);
        y1 = (f(x2)-f(x1))/(x2-x1);
        a = (y1-y0)/(h1+h0);
        b = a*h1+y1;
        c = f(x2);
        det = sqrt(b*b-4*a*c);
        x3 = x2-((2*c)/max(b+det, b-det));
        if(f(x3)==0) break;
        ca = cnterror(x3, x2);
        x0 = x1; 
        x1 = x2; 
        x2 = x3;
    }
    return x3;
}

int main() {
    double x0, x1, x2; cin>>x0>>x1>>x2;
    double ea = 0.0001;
    double root = Muller(x0, x1, x2, ea);
    cout<<root<<'\n';
    return 0;
}