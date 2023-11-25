#include <iostream>
#include <vector>
#include <string>
using namespace std;

double Det_Elim_Gauss(int n, double c[3][3]){
    for (int k = 0; k < n; k++){
        for (int i = k+1; i < n; i++){
            double m = -(c[i][k])/(c[k][k]);
            c[i][k] = 0;
            for (int j = k+1; j < n; j++){
                c[i][j] = c[i][j] + m * c[k][j];
            }
        }
    }
    double det = 1;
    for (int l = 0; l < n; l++){
        det = det * c[l][l];
    }
    return det;
}


double Cramer(int n, double c[3][3], double v[], int i) {
    double k[3][3];
    for (int p = 0; p < n; p++) {
        for (int h = 0; h < n; h++) {
            k[p][h] = c[p][h];
        }
    }
    for (int j = 0; j < n; j++){
        k[j][i]= v[j];
    }
    double det_A = Det_Elim_Gauss(n, c);
    //cout << "det A" << i + 1 << " = " << det_A << endl;
    double det_Ax = Det_Elim_Gauss(n, k);
    //cout << "det Ax" << i + 1 << " = " << det_Ax << endl;
    double dx = det_Ax / det_A;
    //cout << "valor" << i + 1 << " = " << dx << endl;
    return dx;
}


void imprimirMatriz(double matriz[][3], int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        cout <<"|";  // Nova linha após cada linha da matriz
        for (int j = 0; j < colunas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout <<"|"<< endl;  // Nova linha após cada linha da matriz
    }
}



void receber_entrada_C(int n, double coeficientes[][3]) {
    cout << "Digite os valores da matriz: " << endl;
    for (int i = 0; i < n; i++) {
        for (int f = 0; f < n; f++) {
            cout << "elemento da linha " << i + 1 << " e coluna " << f + 1 << ":" << endl;
            cin >> coeficientes[i][f];
        }
    }
}
void receber_entrada_V (int n, double termos_independentes[]){
    cout << "Digite os valores do vetor independente: " << endl;
    for (int w = 0; w < n; w++) {
        cout << "elemento da linha " << w+1 << endl; cin >> termos_independentes[w];
    }
}

int main() {
    //Entradas padrão
    int n = 3;
    double coeficientes[3][3] = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    double termos_independentes[3] = {8, -11, -3};
    double x[3];

    //usar essas funções no if do menu: se a opção escolhida for entradas do usuário
    receber_entrada_C(n, coeficientes);
    receber_entrada_V(n, termos_independentes);

    for (int i = 0; i < n; i++) {
        double a[3][3];
        for (int p = 0; p < n; p++) {
            for (int h = 0; h < n; h++) {
                a[p][h] = coeficientes[p][h];
            }
        }
        x[i] = Cramer(n, a,termos_independentes,i);
    }
    imprimirMatriz(coeficientes, 3, 3);

    // Exibindo a solução
    cout << "Solucao:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "d" << i + 1 << " = " << x[i] << endl;
    }
}

