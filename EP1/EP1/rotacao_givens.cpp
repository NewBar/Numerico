#include "rotacao_givens.h"

Givens::Givens(vector<vector<double>> w,vector<vector<double>> a) : w(w), a(a) {
    this->n = a.size(); 
    this->m = a[0].size();
    this->p = w[0].size();
    vector<vector<double>> y(this->p, vector<double>(this->m, 0));
    this->h = y;
}

Givens::~Givens(){
}

void Givens::fatoracao () { 
    for(int k = 0; k < this->p; k++){
        for(int j = this->n-1; j > k; j--){ 
            int i = j - 1;
            if(this->w[j][k] != 0){
                Rot_givens(i, j, k);
            }                    
        }
    }     
    for(int k = p - 1; k >= 0; k--){
        for (int j = 0; j < m; j++){
            double x = 0;
            for (int i = k; i < p; i++){
                x +=this->w[k][i] * this->h[i][j];
            }
            if(this->w[k][k] != 0)
                this->h[k][j] = (this->a[k][j] - x) / this->w[k][k];
            else
            {
                this->h[k][j] = this->a[k][j] - x;
            }            
        }
    }    
}


void Givens::Rot_givens(int i, int j, int k) {      
    // Calculo de C e S
    if (abs(this->w[i][k]) > abs(this->w[j][k])) {
        this->tau = -this->w[j][k]/this->w[i][k]; 
        this->c = 1/sqrt(1 + pow(this->tau, 2.0));
        this->s =this->c * this->tau;
    } else {
        this->tau = -this->w[i][k]/this->w[j][k];
        this->s = 1/sqrt(1 + pow(this->tau, 2.0));
        this->c = this->s * this->tau;
    }

    // Rotação de Givens em W
    for (int r = 0; r < (int)w[i].size(); r++) {
        this->aux = (this->c * this->w[i][r]) - (this->s * this->w[j][r]);
        this->w[j][r] = (this->s * this->w[i][r]) + (this->c * this->w[j][r]);
        this->w[i][r] = this->aux;
    }

    // Rotação de Givens em A
    for (int r = 0; r < (int)a[i].size(); r++) {
        this->aux = (this->c * this->a[i][r]) - (this->s * this->a[j][r]);
        this->a[j][r] = (this->s * this->a[i][r]) + (this->c * this->a[j][r]);
        this->a[i][r] = this->aux;
    }
    
}