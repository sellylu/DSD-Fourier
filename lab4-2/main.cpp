#include <iostream>
#include <math.h>
#include <complex>
#include <time.h>

using namespace std;

int main()
{
    int const N_POINT = 8;

//    double w = exp();

    complex<double> w(cos(2*M_PI/N_POINT), -sin(2*M_PI/N_POINT));

    complex<double> x[N_POINT];
    for(int i = 0; i < N_POINT; i++)
        x[i] = complex<double>((double)i+1, (double)i+1);

    complex<double> X[N_POINT];
    clock_t tStart = clock();
    for(int i = 0; i < N_POINT; i++) {
        for(int j = 0; j < N_POINT/2; j++) {
            X[i] += x[2*j] * pow(w, 2*j*i);
            X[i] += x[2*j+1] * pow(w, (2*j+1)*i);
        }
        cout << X[i] << endl;
    }
    clock_t tEnd = clock();
    cout << "Time taken: " << (double)(tEnd - tStart)/CLOCKS_PER_SEC << "s" << endl;

    return 0;
}

