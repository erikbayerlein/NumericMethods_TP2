#include <iostream>
#include <vector>

using namespace std;

// Função p imprimir a matriz com o vetor b
void printMatrixWithB(const vector<vector<double>>& A, const vector<double>& B) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << "| " << B[i] << endl;
    }
    cout << endl;
}

// Função para imprimir a matriz
void printMatrix1(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


// Gauss-Jordan, recebe a matriz e o n, nao normaliza e RETORNA A MATRIZ escalonada
vector<vector<double>> gaussJordanAndGetDiagonalizedMatrix(vector<vector<double>> A, int n) {
    //colunas
    for (int k = 0; k < n; ++k) {
        //linhas
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                // Pivoteamento 
                double factor = A[i][k] / A[k][k];
                for (int j = k; j < n; ++j) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }
    }
    return A;
}

// Recebe a matriz e calcula o determinante multiplicando os elementos da diagonal
// matriz tem que ser triangular ou diagonal
double determinantDiagonal1(const vector<vector<double>>& A) {
    int n = A.size();
    double det = 1.0;
    for (int i = 0; i < n; ++i) {
        det *= A[i][i];
    }
    return det;
}


// Função para resolver o sistema linear pela regra de Cramer
vector<double> solveSystemByCramerGaussJordan(vector<vector<double>> A, vector<double> B, double a) {
    int n = A.size();
    vector<double> solution;

    //Gauss-Jordan para diagonalizar A após substituir cada coluna i por b
    for (int i = 0; i < n; ++i) {
        cout << "Matriz após substituir coluna " << i + 1 << " por B:" << endl;
        vector<vector<double>> modifiedMatrix = A;
        for (int j = 0; j < n; ++j) {
            modifiedMatrix[j][i] = B[j];
        }

        // Aplica o método de Gauss-Jordan e imprime a matriz diagonalizada
        printMatrix1(modifiedMatrix);
        vector<vector<double>> diagonalizedMatrix = gaussJordanAndGetDiagonalizedMatrix(modifiedMatrix, n);
        // Calcula o determinante da matriz diagonal após a diagonalização e adiciona ao vetor solução
        double detAi = determinantDiagonal1(diagonalizedMatrix);
        solution.push_back(detAi);
    }
    //Diagonaliza A 
    vector<vector<double>> ADiagonalized = gaussJordanAndGetDiagonalizedMatrix(A, n);
    // Calcula o determinante de A original 
    double detA = determinantDiagonal1(ADiagonalized);

    if (detA != 0.0) {
        // Divide cada determinante calculado pelo determinante original para obter a solução
        for (int i = 0; i < n; ++i) {
            solution[i] /= detA;
            solution[i] *= a;
        }
    } else {
        cout << "O sistema é indeterminado ou impossível de ser resolvido pela regra de Cramer." << endl;
    }

    return solution;
}



/*int main() {

    int n = 4;
    vector<vector<double>> matrix = {
        {2, 1, -1, 2},
        {-3, -1, 2, 5},
        {-2, 1, 2, 8},
        {2, 5, 7, 10},
    };
    vector<double> b = {8, -11, -3, 4};
    
    cout << "Matriz original:" << endl;
    printMatrix(matrix);

    vector<double> solution = solveSystemByCramerGaussJordan(matrix, b, 1);

    cout << "\nSolução do sistema:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "d[" << i + 1 << "] = " << solution[i] << endl;
    }

    return 0;
}*/

void receber_entrada_C1(int n, vector<vector<double>>& coeficientes) {
    cout << "Digite os valores da matriz: " << endl;
    for (int i = 0; i < n; i++) {
        for (int f = 0; f < n; f++) {
            cout << "elemento da linha " << i + 1 << " e coluna " << f + 1 << ":" << endl;
            cin >> coeficientes[i][f];
        }
    }
}
void receber_entrada_V1(int n, vector<double>& termos_independentes){
    cout << "Digite os valores do vetor independente: " << endl;
    for (int w = 0; w < n; w++) {
        cout << "elemento da linha " << w+1 << endl; cin >> termos_independentes[w];
    }
}