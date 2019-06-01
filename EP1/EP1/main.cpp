#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "rotacao_givens.h"
#include "matriz.h"
#include "treino.h"

using namespace std;

int main() {
    int tarefa, modo;
    int n, m, p;
    cout << "Para tarefa digite 1, para principal digite 2:";
    cin >> modo;

    if(modo == 1){

        cout << "Entre com o numero da tarefa:" << endl;
        cin >> tarefa;
    
        if (tarefa == 1){
            char item;
            cout << "Entre com o item da tarefa 1" << endl;
            cin >> item;
            
            if(item == 'a'){
                vector<vector<double>> w(64, vector<double>(64, 0));
                vector<vector<double>> a(64, vector<double>(1, 0));

                //faz as matrizes de entrada
                for(int i = 0; i < static_cast<int>(w.size()); i++){
                    for(int j = 0; j < static_cast<int>(w[0].size()); j++){
                        if(i == j){
                            w[i][j] = 2;
                        }
                        else{
                            if(abs(i - j) == 1) w[i][j] = 1;
                            else w[i][j] = 0;
                        }
                    }
                }
                for(int i = 0; i < static_cast<int>(a.size()); i++){
                    for(int j = 0; j < static_cast<int>(a[0].size()); j++){
                        a[i][j] = 1;
                    }
                }

                Givens *g ;
                g = new Givens(w, a);
                g->fatoracao();

                imprimematriz(g->h);
            }

            else if(item == 'b'){
                vector<vector<double>> w(20, vector<double>(17, 0));
                vector<vector<double>> a(20, vector<double>(1, 0));

                //faz as matrizes de entrada
                for(int i = 0; i < static_cast<int>(w.size()); i++){
                    for(int j = 0; j < static_cast<int>(w[0].size()); j++){
                        if(abs(i - j) <= 4) w[i][j] = (double)1/(i + j + 1);
                        else w[i][j] = 0;
                    }
                }
                
                for(int i = 0; i < static_cast<int>(a.size()); i++){
                    for(int j = 0; j < static_cast<int>(a[0].size()); j++){
                        a[i][j] = 1;
                    }
                }

                Givens *g ;
                g = new Givens(w, a);
                g->fatoracao();

                imprimematriz(g->h);
            }

            else if(item == 'c'){
                vector<vector<double>> w(64, vector<double>(64, 0));
                vector<vector<double>> a(64, vector<double>(3, 0));

                //faz as matrizes de entrada
                for(int i = 0; i < static_cast<int>(w.size()); i++){
                    for(int j = 0; j < static_cast<int>(w[0].size()); j++){
                        if(i == j){
                            w[i][j] = 2;
                        }
                        else{
                            if(abs(i - j) == 1) w[i][j] = 1;
                            else w[i][j] = 0;
                        }
                    }
                }
                for(int i = 0; i < static_cast<int>(a.size()); i++){
                    for(int j = 0; j < static_cast<int>(a[0].size()); j++){
                        if(j == 0) a[i][j] = 1;
                        else if(j == 1) a[i][j] = i;
                        else if(i == 0) a[i][j] = 1;
                        else a[i][j] = 2*i + 1;
                    }
                }

                Givens *g ;
                g = new Givens(w, a);
                g->fatoracao();
                imprimematriz(g->h);
            }
            else if(item == 'd'){
                vector<vector<double>> w(20, vector<double>(17, 0));
                vector<vector<double>> a(20, vector<double>(3, 0));


                //faz as matrizes de entrada
                for(int i = 0; i < static_cast<int>(w.size()); i++){
                    for(int j = 0; j < static_cast<int>(w[0].size()); j++){
                        if(abs(i - j) <= 4) w[i][j] = (double)1/(i + j + 1);
                        else w[i][j] = 0;
                    }
                }
                for(int i = 0; i < static_cast<int>(a.size()); i++){
                    for(int j = 0; j < static_cast<int>(a[0].size()); j++){
                        if(j == 0) a[i][j] = 1;
                        else if(j == 1) a[i][j] = i;
                        else if(i == 0) a[i][j] = 1;
                        else a[i][j] = 2*i + 1;
                    }
                }

                Givens *g ;
                g = new Givens(w, a);
                g->fatoracao();
                imprimematriz(g->h);
            }
        }

        else if(tarefa == 2){
            cout << "Digite n:";
            cin >> n;
            cout << "Digite m:";
            cin >> m;
            cout << "Digite p:";
            cin >> p;

            vector<vector<double>> w(n, vector<double>(p, 0));
            vector<vector<double>> a(n, vector<double>(m, 0));
            vector<vector<double>> ac(n, vector<double>(m, 0));
            vector<vector<double>> h(p, vector<double>(m, 0));
            vector<vector<double>> at(m, vector<double>(n, 0));
            vector<vector<double>> ht(m, vector<double>(p, 0));
            vector<vector<double>> mult(n, vector<double>(m, 0));

            //se precisar para digitar matrizes
            /* cout << "Digite a matriz A:" << endl;
            for (int i = 0; i < n;i++){
                for(int j = 0;j < m;j++){
                    cin  >> a[i][j];
                }
            } */

            //matriz do enunciado
            a[0] = {0.3, 0.6, 0};
            a[1] = {0.5, 0, 1};
            a[2] = {0.4, 0.8, 0};
            
            ac = a;

            //randomiza matriz w
            srand(time(0));
            for (int i = 0; i < (int)w.size();i++){
                for(int j = 0;j < (int)w[0].size();j++){
                    w[i][j] = (rand() % 1000) + 1;;
                }
            }

            double erro = 0;
            double erroant = 10;
            int cont = 0;
            

            while((cont <= 100) && (fabs(erro - erroant) > 0.00001)){
                cout << cont << endl;
                cont++;
                double sj = 0, sum = 0;
                erroant = erro;
                
                //normaliza w
                for (int i = 0; i < (int)w.size();i++){
                    for(int j = 0;j < (int)w[0].size();j++){
                        sum += pow(w[i][j], 2.0);
                    }
                }

                sj = sqrt(sum);
                
                for (int i = 0; i < (int)w.size();i++){
                    for(int j = 0;j < (int)w[0].size();j++){
                        if(sj != 0)
                            w[i][j] = (double)w[i][j] / sj;
                        else
                        {
                            w[i][j] = w[i][j];
                        }                
                    }
                }
                

                //descobre h de wh=a
                Givens *g ;
                g = new Givens(w, ac);
                g->fatoracao();
                h = g->h;

                //redefine h
                for (int i = 0; i < (int)h.size();i++){
                    for(int j = 0;j < (int)h[0].size();j++){
                        if(h[i][j] < 0) h[i][j] = 0;
                    }
                }
                
                
                //transposta de a
                
                at = transposta(ac);
            
                //transoposta de h         
                ht = transposta(h);
                

                //descobre wt de ht*wt=at
                
                g = new Givens(ht, at);
                g->fatoracao();
                

                // transposta de wt (w)
                w = transposta(g->h);
                
                
                //redefine w
                for (int i = 0; i < (int)w.size();i++){
                    for(int j = 0;j < (int)w[0].size();j++){
                        if(w[i][j] < 0) w[i][j] = 0;
                    }
                }
                

                erro = 0;
                double produto = 0;
                mult = multiplica(w, h);
                

                //calcula o erro
                for (int i = 0; i < (int)ac.size();i++){
                    for(int j = 0;j < (int)ac[0].size();j++){
                        produto = ac[i][j] - mult[i][j];
                        erro += pow(produto,2.0);
                    }
                }
                
            }
            imprimematriz( multiplica(w, h) );           
        }
    }

    if (modo == 2){
        int n_test;
        Treino *t ;
        cout << "Digite ndig_treino:";
        cin >> m;
        cout << "Digite p:";
        cin >> p;
        cout << "Digite n_teste:";
        cin >> n_test;

        //chama o modo treinamento
        t = new Treino(m, p, n_test);
        t->matrizA();


    }
}