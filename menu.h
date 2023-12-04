#ifndef MENU_H
#define MENU_H
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

void printMatrixWithB(const vector<vector<double>>& A, const vector<double>& B);

void printMatrix1(const vector<vector<double>>& A);

vector<vector<double>> gaussJordanAndGetDiagonalizedMatrix(vector<vector<double>> A, int n);

double determinantDiagonal1(const vector<vector<double>>& A);

vector<double> solveSystemByCramerGaussJordan(vector<vector<double>> A, vector<double> B, double a);

void receber_entrada_C1(int n, vector<vector<double>>& coeficientes);

void receber_entrada_V1(int n, vector<double>& termos_independentes);


#endif //MENU_H
