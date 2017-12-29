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
    return f1Deriv(t, x) - x;
}

// paste it to LaTeX table
void PrintOutcome(double t, double x, double h, double i, functionPtr fun = NULL) {
    cout    << t
            << " & "
            << x
            << " & "
            << f1Deriv(t, x)
            << " & "
            << ApproxError(t, x, h, fun)
            << " \\\\ \\hline"
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
    
    cout << "PASTE THIS OUTPUT TO LATEX TABLE!" << endl << endl;
    cout << "Euler (podstawowy):" << endl << endl;
    cout << "t_k & x_k & x(t_k) & \\epsilon \\\\ \\hline\n";
    Euler(ts, tf,xs, h, f);
    cout << endl << endl << "Euler (midpoint)" << endl << endl;
    cout << "t_k & x_k & x(t_k) & \epsilon \\\\ \\hline\n";
    EulerMidPoint(ts, tf,xs, h, f);
    
    cout << endl << endl << "Euler (Heun):" << endl << endl;
    cout << "t_k & x_k & x(t_k) & \epsilon \\\\ \\hline\n";
    EulerHeun(ts, tf, xs, h, f);
    cout << endl << endl;

    return 0;
}
