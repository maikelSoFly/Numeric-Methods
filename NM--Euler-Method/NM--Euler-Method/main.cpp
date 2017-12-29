//
//  main.cpp
//  NM--Euler-Method
//
//  Created by Mikołaj Stępniewski on 24.05.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef double (*functionPtr)(double, double);


//FUNCTIONS

// Zadanie 7.
// x' = t - x + 1       x(1) = 3,   1 < t < 2
double f1(double t, double x) {
    return t-x+1;
}
// x = Cexp(-t) + t
// C = 2e    - z warunków początkowych.
double f1Deriv(double t, double x) {
    return 2*exp(1) * exp(-t) + t;
}

double ApproxError(double t, double x, double h, functionPtr f) {
    return abs(x - f1Deriv(t, x));
}


void PrintOutcome(double t, double x, double h, double i, functionPtr fun = NULL) {
    cout << setw(4)
         << left
         << "t = "
         << setw(20)
         << t
         << left
         << "x"
         <<  setw(2)
         << i
         << left
         << " = "
         << setw(20)
         << x
         << left
         << "x(t) = "
         << setw(20)
         << f1Deriv(t, x)
         << left
         << "err: "
         << ApproxError(t, x, h, fun)
         << endl;
}


double Euler(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    
    for(int i = 0; t <= tf; ++i) {
        PrintOutcome(t, x, h, i, f);
        x += h * f(t, x);
        t += h;
    }
    
    return x;
}

double EulerHeun(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    
    for(int i = 0; t <= tf; ++i) {
        PrintOutcome(t, x, h, i, f);
        x += h * (f(t, x) + f(t+h, x + f(t, x) * h)) / 2;
        t += h;
    }
    
    return x;
}

double EulerMidPoint(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    
    for(int i = 0; t <= tf; ++i) {
        PrintOutcome(t, x, h, i, f);
        x += f(t + h/2, x + f(t, x) * h/2) * h;
        t += h;
    }
    
    return x;
}



int main(int argc, const char * argv[]) {
    double ts, tf, xs, h;
    functionPtr f;
    
    // x' = t - x + 1       x(1) = 3,   1 < t < 2
    ts = 1, tf = 2, xs = 3, h = 0.1, f = f1;
    
    cout << "Euler (podstawowy):" << endl;
    Euler(ts, tf,xs, h, f);
    cout << endl << "Euler (midpoint)" << endl;
    EulerMidPoint(ts, tf,xs, h, f);
    
    cout << endl << "Euler (Heun):" << endl;
    EulerHeun(ts, tf, xs, h, f);
    cout << endl << endl;

    return 0;
}
