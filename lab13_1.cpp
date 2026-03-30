#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double X[],int N,double Y[]){
    for(int i = 0; i < 6; i++){
        Y[i] = 0;
    }

    double sum = 0;
    double sumSq = 0;
    double product = 1;
    double sumReciprocal = 0;

    Y[4] = X[0];
    Y[5] = X[0];

    for(int i = 0; i < N; i++){
        sum += X[i];
        sumSq += X[i] * X[i];
        product *= X[i];
        sumReciprocal += 1.0 / X[i];

        if(X[i] > Y[4]) Y[4] = X[i];
        if(X[i] < Y[5]) Y[5] = X[i];
    }
    Y[0] = sum / N;

    Y[1] = sqrt((sumSq / N) - (Y[0] * Y[0]));

    Y[2] = pow(product, 1.0 / N);

    Y[3] = N / sumReciprocal;
}
