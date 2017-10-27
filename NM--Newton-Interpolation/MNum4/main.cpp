//
//  main.cpp
//  MNum4
//
//  Created by Mikołaj Stępniewski on 22.03.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
using namespace std;

double * NewtonInterpolation( double x[], double y[], int size ) {
    
    double *a = new double[ size ];
    int GAP = 1;
    a[ 0 ] = y[ 0 ];
    
    for( int i = size; i > 0; i-- ) {
        for ( int j = 0; j < i; j++ ) {
            y[ j ] = ( y[ j + 1 ] - y[ j ] ) / ( x[ j + GAP] - x[ j ] );
        }
        a[ GAP ] = y[ 0 ];
        GAP++;
    }
    
    return a;
}

int main(int argc, const char * argv[]) {
    double xs[] = { 10, 20, 40, 60, 90, 110, 150 };
    double ys[] = { -20, 10, -30, 20, -10, 30, -20 };
    int size = 7;
    
    double *a = NewtonInterpolation( xs, ys, size );
    
    for( int i = 0; i < size; i++ ) cout << "a'" << i << ":  " << a[i] << endl;
    
    int x;
    cout << "\nPodaj x: ";
    cin >> x;
    double val = a[ 0 ];
    double t = 1;
    
    for( int i = 0; i < size; i++ ) {
        t *= ( x - xs[i] );
        val += a[ i +1 ] * t;
    }
    
    cout << "f(" << x << ") = " << val << endl;
    
    return 0;
}
