#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

/*ver como acessa posição na linha 21*/
vector<double> Substituicoes_Retroativas(int n, double **c, vector<double> v){
    vector<double> d(n);
    double **C=c;
    d[n - 1] = v[n - 1] / C[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--){
        double soma = 0;
        for(int j = i+1; j <= n; j++){
            soma = soma + C[i][j] * d[j];
        }
        d[i] = (v[i] - soma)/C[i][i];
    }
    return d;
}


/*analisar se eh k+1 ou so k*/
vector<double> Eliminacao_Gauss(int n, vector<vector<double>> **c, vector<double> v){
    vector<vector<double>> **C = c;
    for (int k = 0; k < n; k++){
        for (int i = k+1; i <= n; i++){
            double m = -(C[i][k])/(C[k][k]);
            C[i][k] = 0;
            for (int j = k+1; j <= n; j++){
                C[i][j] = C[i][j] + m * C[k][j];
            }
            v[i] = v[i] + m * v[k];
        }
    }
    return Substituicoes_Retroativas(n, *c, v);
}


int main() {
    // Exemplo de uso
    int n = 3;
    vector<vector<double>> coeficientes = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    vector<double> termos_independentes = {8, -11, -3};

    vector<double> solucao = Eliminacao_Gauss(n, *coeficientes, termos_independentes);

    // Exibindo a solução
    cout << "Solucao:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solucao[i] << endl;
    }
}
/*-------------------------------------------------------------------*/
/*ver como acessa posição na linha 21*/
vector<double> Substituicoes_Retroativas(int n, vector<std::vector<double>> c, vector<double> v){
    vector<double> d[n];
    d[n] = v[n] / (c[n][n]);
    for(int i = n-1; i >= 1; i--){
        double soma = 0;
        for(int j = i+1; j <= n; j++){
            soma = soma + c[i][j] * d[j];
        }
        d[i] = (v[i] - soma)/c[i][i];
    }
    return d;
}


/*analisar se eh k+1 ou so k*/
vector<double> Eliminacao_Gauss(int n, vector<vector<double>> c, vector<double> v){
    for (int k = 0; k < n; k++){
        for (int i = k+1; i <= n; i++){
            double m = -(c[i][k])/(c[k][k]);
            c[i][k] = 0;
            for (int j = k+1; j <= n; j++){
                c[i][j] = c[i][j] + m * c[k][j];
            }
            v[i] = v[i] + m * v[k];
        }
    }
    return Substituicoes_Retroativas(n, c, v);
}




