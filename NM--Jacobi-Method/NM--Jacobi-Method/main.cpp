//
//  main.cpp
//  NM--Jacobi-Method
//
//  Created by Mikołaj Stępniewski on 02.06.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    /*  Jacobi method is an iterative algorithm for determining the
        solutions of a (n x n) diagonally dominant system of linear equations  */
    
    const int n = 4;
    const int ITERATIONS_NUMBER = 20;
    
    double **A = new double* [n];
    double *B = new double[n];
    
    for(int i = 0; i < n; ++i)
        A[i] = new double[n];
    
    
    A[0][0] = 4;        A[0][1] = -1;       A[0][2] = -0.2;        A[0][3] = 2;    /**/    B[0] = 30;
    A[1][0] = -1;       A[1][1] = 5;        A[1][2] = 0;           A[1][3] = -2;   /**/    B[1] = 0;
    A[2][0] = 0.2;      A[2][1] = 1;        A[2][2] = 10;          A[2][3] = -1;   /**/    B[2] = -10;
    A[3][0] = 0;        A[3][1] = -2;       A[3][2] = -1;          A[3][3] = 4;    /**/    B[3] = 5;
    
   
    double *N = new double[n];
    for(int i = 0; i < n; ++i)
        N[i] = 1/A[i][i];
    
    double **M = new double* [n];
    for(int i = 0; i < n; ++i)
        M[i] = new double[n];
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) M[i][j] = 0;
            else M[i][j] = -N[i] * A[i][j];
        }
    }
    
    double *x1 = new double[n];
    double *x2 = new double[n];
    
    for(int i = 0; i < n; ++i) {
        x1[i] = 0;
        x2[i] = 0;
    }
    
    for(int i = 0; i < ITERATIONS_NUMBER; ++i) {
        cout << "x^" << i << "\t";
        
        for(int j = 0; j < n; ++j) {
            x2[j] = N[j] * B[j];
            
            for(int k = 0; k < n; ++k)
                x2[j] += M[j][k] * x1[k];
        }
        
        for(int j = 0; j < n; ++j)
            x1[j] = x2[j];
        
        for(int j = 0; j < n; ++j)
            cout << x1[j] << "\t";
        
        cout << endl;
    } cout << endl << endl;
    
    
    cout << "Results:\n";
    for(int i = 0; i < n; ++i)
        cout << i+1 << ".\t" << x1[i];
    cout << endl;
    
    

    return 0;
}
