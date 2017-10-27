//
//  main.cpp
//  MetNum7Aprox
//
//  Created by Mikołaj Stępniewski on 12.04.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

void calculateLeftMatrix(double xs[], double ys[], int n, int size, double *leftMatrix) {
    
    for(int k = 0; k < n; k++) {
        for(int j = 0; j < n; j++) {
            leftMatrix[k*n+j] = 0;  //k*n+j - index [0,1,2, ... n*n]
            for(int i = 0; i < size; i++) {
                if( (k*n+j) % n == 0 && (k*n+j) != 0) leftMatrix[k*n+j] = leftMatrix[(k*n+j)-(n-1)];  //Values like fi1fi2 and fi2fi1 are the same
                else leftMatrix[k*n+j] += pow(xs[i], k) * pow(xs[i], j);
            }
        }
    }
}

void calculateRightMatrix(double xs[], double ys[], int n, int size, double *rightMatrix) {
    
    for(int j = 0; j < n; j++) {
        rightMatrix[j] = 0;
        for(int i = 0; i < size; i++ ) {
            rightMatrix[j] += ys[i] * pow(xs[i], j);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    //Data
    double xs[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 5};
    double ys[] = { -110, -60, -20, -10, -1.5, 2, 7, 18, 50, 170 };
    int size = 10;
    

    int degree;
    cout << "Degree of polynomial: " << endl;
    cin >> degree;
    int n = degree + 1;
    
    double *leftMatrix = new double[n*n];
    double *rightMatrix = new double[n];
    
    
    //Getting left and right matrixes
    calculateLeftMatrix(xs, ys, n, size, leftMatrix);
    calculateRightMatrix(xs, ys, n, size, rightMatrix);
    
    
    //Printing matrixes for Wolfram
    cout << "Paste line below to WolframAlpha\n\n{{";
    for(int i = 0; i < n*n; i++) {
        cout << leftMatrix[i];
        if( (i+1) % n == 0 && i+1 != n*n ) cout << "},{";
        else if ( (i+1) == n*n ) cout << "}}";
        else cout << ",";
    }
    
    cout << "*{";
    for(int i = 0; i < n; i++) {
        cout << "{a"<<i<<"}";
        if(i != n-1) cout <<",";
    }
    
    cout << "}={";
    for(int i = 0; i < n; i++) {
        cout << "{" << rightMatrix[i];
        if(( i+1) % n != 0 ) cout << "},";
    }
    cout << "}}"<< endl << endl;
    
    
    delete[] leftMatrix;
    delete[] rightMatrix;
    
    return 0;
}
