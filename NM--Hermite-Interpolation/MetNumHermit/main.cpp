//
//  main.cpp
//  MetNumHermit
//
//  Created by Mikołaj Stępniewski on 29.03.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//
#include <iostream>
using namespace std;

double *HermiteInterpolation( double xs[], double ys[], double *derivatives, int size ) {
    double *a = new double[size];
    a = ys;
    
    for( int i = 0; i < size; i++ ) {
        if(xs[i] == xs[i-1])
            derivatives[i] = derivatives[i-1] + 1;
        else
            derivatives[i] = 0;
    }
    
    for( int i = 1; i < size; i++) {
        for( int j = size - 1; j >=i; j-- ) {
            if( derivatives[j] == 0 )
                ys[j] = ( ys[j] - ys[ ((int)( j-1 - derivatives[j-1] ))]);
            else {
                ys[j] /= (double)i;
                derivatives[j]--;
            }
        }
    }
    
    return a;
}



int main(int argc, const char * argv[]) {
    
    int size = 4;
    double xs[] = { 1, 1, 3, 3 };
    double ys[] = { 2, 3, 5, 6 };
    
    double *a = new double[size];
    double *derivatives = new double[size];
    
    a = HermiteInterpolation( xs, ys, derivatives, size );
    
    cout <<  endl <<  "Współczynniki: " << endl;
    for( int i = 0; i < size; i++ ) {
        cout << "a'" << i << ": " << ys[i] << endl;
    }
    
    
    return 0;
}
