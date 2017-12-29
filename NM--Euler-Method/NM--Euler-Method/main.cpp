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
double f1(double x, double y) {
    return x+y;
}

double f1Deriv(double x, double y) {
    
    return exp(x) - x - 1;
}

double ApproxError(double x, double y, double h, functionPtr f) {
   
    return abs(y - f1Deriv(x, y));
    
}

void PrintOutcome(double x, double y, double h, double i, functionPtr fun = NULL) {
    cout << setw(4)
         << left
         << "x = "
         << setw(20)
         << x
         << left
         << "y"
         <<  setw(2)
         << i
         << left
         << " = "
         << setw(20)
         << y
         << left
         << "y(x): "
         << setw(20)
         << f1Deriv(x, y)
         << left
         << "err: "
         << ApproxError(x, y, h, fun)
         << endl;
}


double Euler(double xs, double xf, double ys, double h, functionPtr f) {
    double x = xs, y = ys;
    
    for(int i = 0; x <= xf; ++i) {
        PrintOutcome(x, y, h, i, f);
        y += h * f(x, y);
        x += h;
        
    }
    
    return y;
}

double EulerHeun(double xs, double xf, double ys, double h, functionPtr f) {
    double x = xs, y = ys;
    
    for(int i = 0; x <= xf; ++i) {
        PrintOutcome(x, y, h, i, f);
        y += h * (f(x, y) + f(x+h, y + f(x, y) * h)) / 2;
        x += h;
    }
    
    return y;
}

double EulerMidPoint(double xs, double xf, double ys, double h, functionPtr f) {
    double x = xs, y = ys;
    
    for(int i = 0; x <= xf; ++i) {
        PrintOutcome(x, y, h, i, f);
        y += f(x + h/2, y + f(x, y) * h/2) * h;
        x += h;
    }
    
    return y;
}



int main(int argc, const char * argv[]) {
    double xs, xf, ys, h;
    functionPtr f;
    
    xs = 0, xf = 1, ys = 0, h = 0.1, f = f1; // Function 1
    
    cout << "Funkcja 1" << endl << endl << "Euler (podstawowy):" << endl;
    Euler(xs, xf,ys, h, f);
    cout << endl << "Euler (Heun):" << endl;
    EulerHeun(xs, xf, ys, h, f);
    cout << endl << "Euler (midpoint)" << endl;
    EulerMidPoint(xs, xf,ys, h, f);
    cout << endl << endl;
    

    return 0;
}
