#ifndef GAUSSJORDAN_H
#define GAUSSJORDAN_H

#include <vector>

using namespace std;

void printMatrixWithB(const vector<vector<double>>& A, const vector<double>& B);

void printMatrix(const vector<vector<double>>& A);

vector<vector<double>> gaussJordanAndGetDiagonalizedMatrix(vector<vector<double>> A, int n);

double determinantDiagonal(const vector<vector<double>>& A);

vector<double> solveSystemByCramerGaussJordan(vector<vector<double>> A, vector<double> B, double a);

void receber_entrada_C(int n, vector<vector<double>> coeficientes);

void receber_entrada_V (int n, vector<double> termos_independentes);

#endif //GAUSSJORDAN_H
