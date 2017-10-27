//
//  main.cpp
//  MetNum-01
//
//  Created by Mikołaj Stępniewski on 01.03.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//
// Very simple algorithms for computing value of the polynomial

#include <iostream>
#include <cmath>
using namespace std;

int met11(double *wsp, int x, int n) {
    int val = 0;
    
    
    for(int i = 0; i < n; i++) {
        int tmpx = 1;
        for (int j = 0; j < i; j++) {
            tmpx *= x;
        }
        val += tmpx * wsp[i];
    }
    
    return val;
}

int met12(double *wsp, int x, int n) {
    int val = 0;
    
    for(int i = 0; i < n; i++) {
        val += pow(x, i) * wsp[i];
    }
    
    return val;
}

int met2(double *wsp, int x, int n) { //x^k = x^k-1 * x
    int val = 0;
    int tmpx = 1;
    
    for(int i = 0; i < n; i++) {
        int tmp = wsp[i] * tmpx;
        val += tmp;
        tmpx *= x;
    }
    
    return val;
}

int met3(double *wsp, int x, int n) { //Horner's method
    int val = 0;
    
    int tmp = wsp[n-1] * x + wsp[n-2];
    
    for (int i = n-2; i > 0; i--){
        tmp *= x;
        tmp += wsp[i-1];
    }
    
    val = tmp;
    
    return val;
}

int main(int argc, const char * argv[]) {
    int n, x;
    double *wsp;

    cout << "> n: ";
    cin >> n;
    wsp = new double[n];
    
    for (int i = 0; i < n; i ++) {
        wsp[i] = (rand() % 12) + 1;
    }
    
    cout << endl << "f(x) = ";
    for(int i = n-1; i > 0; i--) {
        (wsp[i] != 1) ? cout << wsp[i] : cout << "";
        cout << "x^" << i << " + ";
    } cout << wsp[0];
    cout << endl << endl;
    
    cout << "> x: ";
    cin >> x;
    
    cout << "> met1.1: " << "f(" << x << ") = " << met11(wsp, x, n) << endl;
    cout << "> met1.2: " << "f(" << x << ") = " << met12(wsp, x, n) << endl;
    cout << "> met2: " << "f(" << x << ") = " << met2(wsp, x, n) << endl;
    cout << "> met3: " << "f(" << x << ") = " << met3(wsp, x, n) << endl;
    
    return 0;
}
