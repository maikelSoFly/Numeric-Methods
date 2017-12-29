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
const double e = 2.721828;


//FUNCTIONS
double f1(double x, double y) {
    return x+y;
}



// nvm...
double f2(double x, double y) {
    return 3 * pow(x, 2) - 2 * pow(y, 2);
}

double f3(double x, double y) {
    return -1.2 * y + 7 * pow(e, -0.3 * x);
}

double f1Derivative(double x, double y) {
    return NULL;
}

double ApproxError(double x, double y, double h, functionPtr f) {
    functionPtr fTemp;
    
    if(f == f1)
        fTemp = f1Derivative;
    else if (f == f2)
        fTemp = NULL;
    else if(f == f3)
        fTemp = NULL;
    
    if(fTemp != NULL) {
        return fTemp(x, y) * pow(h, 2) / 2;
    }
    else
        return NULL;
}

void PrintOutcome(double x, double y, double h, double i, functionPtr fun = NULL) {
    cout << setw(4)
         << left
         << "x = "
         << setw(20)
         << x
         << left
         << "i"
         <<  setw(2)
         << i
         << left
         << " = "
         << setw(20)
         << y
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
    
//    xs = 0, xf = 1, ys = 1, h = 0.1, f = f2; // Function 2
//
//    cout << "Funkcja 2" << endl << endl << "Euler (podstawowy):" << endl;
//   Euler(xs, xf, ys, h, f);
//    cout << endl << "Euler (Heun):" << endl;
//    EulerHeun(xs, xf, ys, h, f);
//    cout << endl << "Euler (midpoint)" << endl;
//    EulerMidPoint(xs, xf, ys, h, f);
//    cout << endl << endl;
//
//    xs = 0,xf = 2, ys = 3, h = 0.5, f = f3; // Function 3
//
//    cout << "Funkcja 3" << endl << endl << "Euler (podstawowy):" << endl;
//    Euler(xs, xf, ys, h, f);
//    cout << endl << "Euler (Heun):" << endl;
//    EulerHeun(xs, xf, ys, h, f);
//    cout << endl << "Euler (midpoint)" << endl;
//    EulerMidPoint(xs, xf, ys, h, f);
//    cout << endl << endl;
//
//
    return 0;
}
