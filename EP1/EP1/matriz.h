#if !defined(__MATRIZ_H__)
#define __MATRIZ_H__

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<double>> multiplica(vector<vector<double>> m1, vector<vector<double>> m2);

void imprimematriz(vector<vector<double>> m1);

vector<vector<double>> transposta(vector<vector<double>> m1);

void fat_n_negativa(vector<vector<double>> a, int m, int n, int p);

#endif // __MATRIZ_H__