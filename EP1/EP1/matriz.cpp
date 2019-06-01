#include "matriz.h"

vector<vector<double>> multiplica(vector<vector<double>> m1, vector<vector<double>> m2){
    vector<vector<double>> m3((int)m1.size(), vector<double>((int)m2[0].size(), 0));
    

    for(int i = 0; i < (int)m1.size(); i++){
        for(int j = 0 ; j < (int)m2[0].size(); j++){
            for(int k = 0; k < (int)m1[0].size(); k++){
                m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return m3;
}

void imprimematriz(vector<vector<double>> m1){
    for(int i = 0; i < static_cast<int>(m1.size()); i++){
        for(int j = 0; j < static_cast<int>(m1[0].size()); j++){
            cout << setw(10) << right << fixed << setprecision(3) << m1[i][j];
        }
        cout << endl;
    }
}

vector<vector<double>> transposta(vector<vector<double>> m1){
    vector<vector<double>> t(m1[0].size(), vector<double>(m1.size(), 0));
    for (int i = 0; i < (int)m1.size(); i++){
        for(int j = 0; j < (int)m1[0].size(); j++){
            t[j][i] = m1[i][j];
        }
    }

    return t;
}