//
//  main.cpp
//  MetNumIntegralsLive
//
//  Created by Mikołaj Stępniewski on 28.04.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
using namespace std;

double f(double x) {
    return 3 * x + 1;
}

double f(double x, double y) {
    return x * y + 1;
}

double randMC(double a, double b) {
    return (double)(rand()) / RAND_MAX*(b-a);
}

int isIn(double x, double y) {
    if(y > 0 && y <= f(x))
        return 1;
    return 0;
}

int isIn(double x, double y, double z){
    if((z > 0) && (z <= f(x, y)))
        return 1;
    return 0;
}


//MAIN FUNCTIONS
double trapezoidal (double xp, double xk, int n) {
    double h = (xk - xp)/n;
    double sum = 0., a = f(xp), b;
    
    for(int i = 1; i <= n; i++){
        b = f(xp + h*i);
        sum += a + b;
        a = b;
    }
    
    return sum * 0.5 * h;
}

double monteCarlo(double xp, double xk, int n) {
    double hits = 0., yp = 0., yk = f(xk);
    
    for(int i = 0; i < n; i++) {
        double x = xp + randMC(xp, xk);
        double y = yp + randMC(yp, yk);
        hits += isIn(x, y);
    }
    return ((xk - xp)*(yk - yp) * hits) / n;
}

double monteCarloII(double xp, double xk, double yp, double yk, int n) {
    double hits = 0., zp = 0., zk = f(xk, yk);
    
    for(int i = 0; i < n; i++) {
        double x = xp + randMC(xp, xk);
        double y = yp + randMC(yp, yk);
        double z = zp + randMC(zp, zk);
        hits += isIn(x, y, z);
    }
    return ((xk - xp) * (yk - yp) * (zk - zp) * hits) / n;
}

double trapezoidalII(double xp, double xk, double yp, double yk, int n) {
    double sum = 0.;
    double h1 = (xk - xp) / n;
    double h2 = (yk - yp) / n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum += f(xp + h1 * i, yp + h2 * j);
        }
    }
    return sum * h1 * h2;
}



int main(int argc, const char * argv[]) {
    srand(static_cast<int>(time(NULL)));
    
    double xp = 0., xk = 4.;
    cout << "Metoda trapezów\n";
    cout << "16:    " << trapezoidal(xp, xk, 16) << endl;
    cout << "128:    " << trapezoidal(xp, xk, 128) << endl;
    cout << "10000:    " << trapezoidal(xp, xk, 10000) << endl << endl;
    
    cout << "Metoda Monte Carlo\n";
    cout << "16:    " << monteCarlo(xp, xk, 16) << endl;
    cout << "128:    " << monteCarlo(xp, xk, 128) << endl;
    cout << "10000:    " << monteCarlo(xp, xk, 10000) << endl << endl << endl;
    
    
    
    xp = 0;
    xk = 2;
    double yp = 0;
    double yk = 2;
    
    cout << "Metoda prostopadłościanów dla całki podwójnej\n";
    cout << "16:    " << trapezoidalII(xp, xk, yp, yk, 16) << endl;
    cout << "128:    " << trapezoidalII(xp, xk, yp, yk, 128) << endl;
    cout << "10000:    " << trapezoidalII(xp, xk, yp, yk, 10000) << endl << endl;
    
    cout << "Metoda Monte Carlo dla całki podwójnej\n";
    cout << "16:    " << monteCarloII(xp, xk, yp, yk, 16) << endl;
    cout << "128:    " << monteCarloII(xp, xk, yp, yk, 128) << endl;
    cout << "10000:    " << monteCarloII(xp, xk, yp, yk, 10000) << endl << endl;
    
    
    
    return 0;
}
