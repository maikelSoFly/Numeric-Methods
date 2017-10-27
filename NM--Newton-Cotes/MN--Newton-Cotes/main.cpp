//
//  main.cpp
//  NM--Newton-Cotes
//
//  Created by Mikołaj Stępniewski on 19.05.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

double f1(int x) {
    return 3 * x*x*x - 1;
}

double f2(int x) {
    return sin(x);
}

double f3(int x) {
    return pow(2.7182, -x);
}

double NewtonCotes(double a, double b, int segments, int degree, double divisor, double multiplier, const double tab[], int s) {
    double h = (b - a) / (double)segments;
    double fval = 0.;
    
    for(int i = 0; i < segments; ++i) {
        double seg_a = a + i*h;
        double seg_b = seg_a + h;
        double dx = (seg_b - seg_a)/(double)degree;
        
        double fsubVal = 0.;
        
        for(int j = 0; j <= degree; ++j){
            switch(s) {
                case 1:
                    fsubVal += tab[j] * f1(seg_a + j*dx);
                    break;
                case 2:
                    fsubVal += tab[j] * f2(seg_a + j*dx);
                    break;
                case 3:
                    fsubVal += tab[j] * f3(seg_a + j*dx);
                    break;
                default:
                    break;
            }
        }
        fval += (((seg_b - seg_a) * multiplier) / divisor) * fsubVal;
    }
    return fval;
}

//I Rząd
double Trapezoids(double a, double b, int segments, int s) {
    int degree = 1;
    double multiplier = 1.;
    double divisor = 2.;
    double tab[] = {1.,1.};
    
    return NewtonCotes(a, b, segments, degree, divisor, multiplier, tab, s);
}

//II Rząd
double Simpson(double a, double b, int segments, int s) {
    int degree = 2;
    double multiplier = 1.;
    double divisor = 6.;
    double tab[] = {1.,4., 1.};
    
    return NewtonCotes(a, b, segments, degree, divisor, multiplier, tab, s);
}

//III Rząd
double Method38(double a, double b, int segments, int s) {
    int degree = 3;
    double multiplier = 3.;
    double divisor = 8.;
    double tab[] = {1.,3.,3.,1.};
    
    return NewtonCotes(a, b, segments, degree, divisor, multiplier, tab, s);
}

//IV Rząd
double Boole(double a, double b, int segments, int s) {
    int degree = 4;
    double multiplier = 2.;
    double divisor = 45.;
    double tab[] = {7., 32., 12., 32., 7.};
    
    return NewtonCotes(a, b, segments, degree, divisor,multiplier, tab, s);
}


int main(int argc, const char * argv[]) {
    cout << "Funkcja 1.:\n";
    cout << Trapezoids(0, 10, 1, 1) << endl;
    cout << Simpson(0, 10, 1, 1) << endl;
    cout << Method38(0, 10, 1, 1) << endl;
    cout << Boole(0, 10, 1, 1) << endl << endl;
    
    cout << "Funkcja 2.:\n";
    cout << Trapezoids(0, 10, 1, 2) << endl;
    cout << Simpson(0, 10, 1, 2) << endl;
    cout << Method38(0, 10, 1, 2) << endl;
    cout << Boole(0, 10, 1, 2) << endl << endl;
    
    cout << "Funkcja 3.:\n";
    cout << Trapezoids(0, 10, 1, 3) << endl;
    cout << Simpson(0, 10, 1, 3) << endl;
    cout << Method38(0, 10, 1, 3) << endl;
    cout << Boole(0, 10, 1, 3) << endl << endl;
    
//    cout << "Złozone\n";
//    cout << "Funkcja 1.:\n";
//    cout << Trapezoids(0, 10, 32, 1) << endl;
//    cout << Simpson(0, 10, 32, 1) << endl;
//    cout << Method38(0, 10, 32, 1) << endl;
//    cout << Boole(0, 10, 1, 1) << endl << endl;
//    
//    cout << "Funkcja 2.:\n";
//    cout << Trapezoids(0, 10, 1, 2) << endl;
//    cout << Simpson(0, 10, 1, 2) << endl;
//    cout << Method38(0, 10, 1, 2) << endl;
//    cout << Boole(0, 10, 1, 2) << endl << endl;
//    
//    cout << "Funkcja 3.:\n";
//    cout << Trapezoids(0, 10, 1, 3) << endl;
//    cout << Simpson(0, 10, 1, 3) << endl;
//    cout << Method38(0, 10, 1, 3) << endl;
//    cout << Boole(0, 10, 1, 3) << endl << endl;
    

    
    return 0;
}
