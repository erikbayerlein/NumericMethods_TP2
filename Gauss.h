#ifndef GAUSS_H
#define GAUSS_H

#include <vector>
#include <list>

using namespace std;

void printMatrix(const vector<vector<double>>& A);

vector<vector<double>> Escalonar_Gauss(vector<vector<double>>& matriz, int n);

double determinantDiagonal(const vector<vector<double>>& A);

vector<double> solveSystemByCramerGauss(vector<vector<double>> A, vector<double> B, double a);

vector<vector<int>> lerMatriz(int n);

vector<int> lerVetor(int n);

void receber_entrada_C(int n, vector<vector<double>>& coeficientes);

void receber_entrada_V (int n, vector<double>& termos_independentes);


#endif //GAUSS_H
