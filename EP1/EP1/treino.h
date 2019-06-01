#if !defined(__TREINO__)
#define __TREINO__

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <limits>
#include <vector>
#include "rotacao_givens.h"
#include "matriz.h"

using namespace std;

class Treino {
    private:
        
        

    public:
        int n;
        vector< vector< vector<double> > > mW;
        vector< vector< vector<double> > > mH;
        int p;
        vector< vector<double> > w, a, h; // primeiro vector são as linhas
        vector< vector<double> > cj;
        int n_test;
        int m;
        Treino(int ndig_treino, int p, int n_test);
        ~Treino();
        vector <double> digprov;
        vector <double> erro;
        
        
        
        void matrizA();
};

#endif // __TREINO__