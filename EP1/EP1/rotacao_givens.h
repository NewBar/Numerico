#if !defined(__ROTACAO_GIVENS__)
#define __ROTACAO_GIVENS__

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

class Givens {
    private:
        
        

    public:
        double tau = 0, aux = 0;
        vector<vector<double>> w, a, h; // primeiro vector são as linhas 
        int m, n, p;
        Givens(vector<vector<double>> w,vector<vector<double>> a);
        ~Givens();
        double s = 0;
        double c = 0;
        void fatoracao();
        void Rot_givens(int i, int j, int k);

};

#endif