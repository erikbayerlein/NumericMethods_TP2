#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Função para imprimir a matriz
void printMatrix(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


vector<vector<double>> Escalonar_Gauss(vector<vector<double>>& matriz, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            double m = -(matriz[i][k]) / (matriz[k][k]);
            matriz[i][k] = 0;
            for (int j = k + 1; j < n; j++) {
                matriz[i][j] = matriz[i][j] + m * matriz[k][j];
            }
        }
    }

    // A matriz escalonada (triangular superior) é retornada
    return matriz;
}

//multiplica a diagonal e retorna a determinante
double determinantDiagonal(const vector<vector<double>>& A) {
    int n = A.size();
    double det = 1.0;
    for (int i = 0; i < n; ++i) {
        det *= A[i][i];
    }
    return det;
}

// Função para resolver o sistema linear pela regra de Cramer
vector<double> solveSystemByCramerGauss(vector<vector<double>> A, vector<double> B, double a) {
    int n = A.size();
    vector<double> solution;

    //Gauss para transformar a mtriz A em triangular superior após substituir cada coluna i por b
    for (int i = 0; i < n; ++i) {
        cout << "Matriz após substituir coluna " << i + 1 << " por B:" << endl;
        vector<vector<double>> modifiedMatrix = A;
        for (int j = 0; j < n; ++j) {
            modifiedMatrix[j][i] = B[j];
        }

        // Aplica o método de Gauss e imprime a matriz triangular superior
        printMatrix(modifiedMatrix);
        vector<vector<double>> matrizTriangularSuperior = Escalonar_Gauss(modifiedMatrix, n);
        // Calcula o determinante da matriz triangular superior após a diagonalização e adiciona ao vetor solução
        double detAi = determinantDiagonal(matrizTriangularSuperior);
        solution.push_back(detAi);
    }
    
    //Escalona A
    vector<vector<double>> ATriangularSuperior = Escalonar_Gauss(A, n);
    // Calcula o determinante de A original 
    double detA = determinantDiagonal(ATriangularSuperior);

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


//receber a matriz C do usuário
vector<vector<int>> lerMatriz(int n) {
   vector<vector<int>> matriz(n, vector<int>(n));

   for(int i = 0; i < n; ++i) {
       for(int j = 0; j < n; ++j) {
           cout << "Digite o elemento na linha " << i+1 << ", coluna " << j+1 << ": ";
           cin >> matriz[i][j];
       }
   }
   return matriz;
}


//receber o vetor B do usuário
vector<int> lerVetor(int n) {
   vector<int> vetor(n);

   for(int i = 0; i < n; ++i) {
       cout << "Digite o elemento na posição " << i+1 << ": ";
       cin >> vetor[i];
   }

   return vetor;
}


int main() {
    //Entradas padrão
    //int n = 3;
    //double coeficientes[3][3] = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    //double termos_independentes[3] = {8, -11, -3};
    //double x[3];

    //usar essas funções no if do menu: se a opção escolhida for entradas do usuário
    //receber_entrada_C(n, coeficientes);
    //receber_entrada_V(n, termos_independentes);

    //for (int i = 0; i < n; i++) {
    //    double a[3][3];
    //    for (int p = 0; p < n; p++) {
    //        for (int h = 0; h < n; h++) {
    //            a[p][h] = coeficientes[p][h];
    //        }
    //    }
    //    x[i] = Cramer(n, a,termos_independentes,i);
    //}
    //imprimirMatriz(coeficientes, 3, 3);

    // Exibindo a solução
    //cout << "Solucao:" << endl;
    //for (int i = 0; i < n; i++) {
    //    cout << "d" << i + 1 << " = " << x[i] << endl;
    //}

    int n = 3;
    vector<vector<double>> matrix = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };
    vector<double> b = {8, -11, -3};
    
    cout << "Matriz original:" << endl;
    printMatrix(matrix);

    vector<double> solution = solveSystemByCramerGauss(matrix, b, 2);

    cout << "\nSolução do sistema:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "d[" << i + 1 << "] = " << solution[i] << endl;
    }

    return 0;
}

