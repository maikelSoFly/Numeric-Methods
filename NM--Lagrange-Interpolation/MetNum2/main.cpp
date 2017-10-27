//
//  main.cpp
//  MetNum2
//
//  Created by Mikołaj Stępniewski on 08.03.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
using namespace std;
double Interpolation(double[], double[], double x, size_t);

int main(int argc, const char * argv[]) {
    double x[] = { 0, 10, 20, 80 };
    double y[] = { 0, -100, 20, 30 };
    
    for (int i = 0; i <= 80; i++) {
        if (i % 2==0) {
            cout << i << " " << Interpolation(x, y, i, 4) << endl;
        }
    }
    
    return 0;
}

double Interpolation(double xs[], double ys[], double x, size_t size) {
    double y = 0.0;
    double t;
    for(int i = 0; i < size; i++) {
        t = 1.0;
        for (int j = 0; j < size; j++){
            if(i != j) {
                t *= (x - xs[j]) / (xs[i] - xs[j]);
            }
        }
        y += ys[i] * t;
    }
    
    return y;
}
