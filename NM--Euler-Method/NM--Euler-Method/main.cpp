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


//MARK: - Equations

// Zadanie 7.
// x′ = t - x + 1       x(1) = 3,   1 < t < 2
double differentialEquationI(double t, double x) {
    return t-x+1;
}
// x′′ = 1 - x'
double differentialEquationII(double t, double x) {
    return x-t;
}
// x′′′ = -x′′
double differentialEquationIII(double t, double x) {
    return t-x;
}
// x = Cexp(-t) + t
// C = 2e    - z warunków początkowych.
double solutionFunction(double t, double x) {
    return 2*exp(1) * exp(-t) + t;
}


//MARK: - Calculating error from aproximated result and known value
double ApproxError(double t, double x, double h, functionPtr f) {
    return solutionFunction(t, x) - x;
}

//MARK: - LaTeX-Ready printing function
void PrintOutcome(double t, double x, double h, double i, functionPtr fun = NULL) {
    cout    << t
            << " & "
            << x
            << " & "
            << solutionFunction(t, x)
            << " & "
            << ApproxError(t, x, h, fun)
            << " \\\\ \\hline"
            << endl;
}


//MARK: - Aproximation methods

double Euler(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    int interv = floor(((tf-ts)/h)/10);
    
    for(int i = 0; t <= tf+h; ++i) {
        if (i % interv == 0) {
            PrintOutcome(t, x, h, i, f);
        }
        x += h * f(t, x);
        t += h;
    }
    
    return x;
}


double EulerMidPoint(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    int interv = floor(((tf-ts)/h)/10);
    
    for(int i = 0; t <= tf+h; ++i) {
        if (i % interv == 0) {
            PrintOutcome(t, x, h, i, f);
        }
        x += f(t + h/2, x + f(t, x) * h/2) * h;
        t += h;
    }
    
    return x;
}


double TaylorIII(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    int interv = floor(((tf-ts)/h)/10);
    
    for(int i = 0; t <= tf+h; ++i) {
        if (i % interv == 0) {
            PrintOutcome(t, x, h, i, f);
        }
        
        double xI = differentialEquationI(t, x);
        double xII = differentialEquationII(t, x);
        double xIII = differentialEquationIII(t, x);
        
        x += h*xI + (pow(h, 2)/2)*xII + (pow(h, 3)/6)*xIII;
        t += h;
    }
    
    return x;
}


double Runge_KuttaIV(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    int interv = floor(((tf-ts)/h)/10);
    
    for(int i = 0; t <= tf+h; ++i) {
        if (i % interv == 0) {
            PrintOutcome(t, x, h, i, f);
        }
        
        double k1 = h*differentialEquationI(t, x);
        double k2 = h*differentialEquationI(t+(h/2), x+(0.5*k1));
        double k3 = h*differentialEquationI(t+(h/2), x+(0.5*k2));
        double k4 = h*differentialEquationI(t+h, x+k3);
        
        x += (k1 + 2*k2 + 2*k3 + k4)/6;
        t += h;
    }
    
    return x;
}


double EulerHeun(double ts, double tf, double xs, double h, functionPtr f) {
    double t = ts, x = xs;
    int interv = floor(((tf-ts)/h)/10);
    
    for(int i = 0; t <= tf+h; ++i) {
        if (i % interv == 0) {
            PrintOutcome(t, x, h, i, f);
        }
        x += h * (f(t, x) + f(t+h, x + f(t, x) * h)) / 2;
        t += h;
    }
    
    return x;
}



int main(int argc, const char * argv[]) {
    double ts, tf, xs, h;
    functionPtr f;
    
    // x′ = t - x + 1       x(1) = 3,   1 < t < 2
    ts = 1, tf = 2, xs = 3, h = 0.01, f = differentialEquationI;
    
    
    cout << "PASTE THIS OUTPUT INTO LATEX TABLE!" << endl << endl;
    cout << "Euler (podstawowy):" << endl << endl;
    cout << "$t_k$ & $x_k$ & $x(t_k)$ & $\\epsilon$ \\\\ \\hline\n";
    Euler(ts, tf,xs, h, f);
    cout << endl << endl << "Euler (midpoint)" << endl << endl;
    cout << "$t_k$ & $x_k$ & $x(t_k)$ & $\\epsilon$ \\\\ \\hline\n";
    EulerMidPoint(ts, tf,xs, h, f);
    cout << endl << endl << "Taylor" << endl << endl;
    cout << "$t_k$ & $x_k$ & $x(t_k)$ & $\\epsilon$ \\\\ \\hline\n";
    TaylorIII(ts, tf,xs, h, f);
    cout << endl << endl << "Runge_Kutta rzędu IV" << endl << endl;
    cout << "$t_k$ & $x_k$ & $x(t_k)$ & $\\epsilon$ \\\\ \\hline\n";
    Runge_KuttaIV(ts, tf,xs, h, f);
    
    cout << endl << endl << "Euler (Heun):" << endl << endl;
    cout << "$t_k$ & $x_k$ & $x(t_k)$ & $\\epsilon$ \\\\ \\hline\n";
    EulerHeun(ts, tf, xs, h, f);
    cout << endl << endl;

    return 0;
}
