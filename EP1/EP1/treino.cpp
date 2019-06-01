#include "treino.h"

Treino::Treino(int ndig_treino, int p, int n_test) : 
    n(784), 
    mW(10), 
    mH(10), 
    p(p),
    a(784, vector<double>(ndig_treino, 0)),     
    cj(10, vector<double>(ndig_treino, 0)), 
    n_test(n_test),
    digprov(n_test),
    m(ndig_treino), 
    erro(n_test)
    {}

void Treino::matrizA(){
    for(int i = 0; i < 10; i++){
        string filename = "./dados_mnist/train_dig" + to_string(i) + ".txt";
        ifstream file(filename);

        if(!file.is_open()){
            cout << "Incapaz de abrir o arquivo";
            exit(1); // termina com erro 
        }
        
        //coloca o arquivo na matriz a
        for(int i = 0; i< 784;i++){
           for(int j = 0; j < this->m; j++) { 
               file >> this->a[i][j];
               this->a[i][j] = (double) this->a[i][j] / 255;
           }
           file.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        file.close();

        
        //desmancha A em WH
        vector<vector<double>> w(n, vector<double>(p, 0));
        vector<vector<double>> ac(n, vector<double>(this->m, 0));
        vector<vector<double>> h(p, vector<double>(m, 0));
        vector<vector<double>> at(m, vector<double>(n, 0));
        vector<vector<double>> ht(m, vector<double>(p, 0));
        vector<vector<double>> mult(n, vector<double>(m, 0));
        
        ac = a;

    
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
        mW[i] = w;
        imprimematriz(w);

        //parte do programa em que está com conflito
        /*string filename2 = "./dados_mnist/test_images.txt";
        ifstream file2(filename2);
        if(!file2.is_open()){
            cout << "Incapaz de abrir fdfsfo arquivo";
            exit(1); // termina com erro 
        }

        //coloca o arquivo de teste na matriz a
        for(int i = 0; i< 784;i++){
           for(int j = 0; j < n_test; j++) { 
               file >> this->a[i][j];
               this->a[i][j] = this->a[i][j] / 255.0;
           }
           file2.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        file2.close();

        

        
        Givens *g1 ;
        g1 = new Givens(mW[i], this->a);
        g1->fatoracao();
        mH[i] = g1->h;
        for(int j = 0; j < (int)mH[i][0].size(); j++){
            double soma = 0;
            for(int k = 0; k < 784; k++){
                soma += pow(mH[i][k][j], 2.0);
            }
            cj[i][j] = sqrt(soma);
        }
    }
   
    
    for(int j = 0; j < n_test; j++){
        for(int i = 1; i < 10; i++){
            if(cj[i - 1][j] > cj[i][j]) {
                this->digprov[j] = i; 
                erro[j] = cj[i][j];
            }
        }
    }        
    for(int i = 0; i < n_test; i++) {
        cout << this->digprov[i] << endl;
    }*/
} 
}