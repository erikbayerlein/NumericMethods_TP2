#include <iostream>
#include <iomanip> 
#include <cmath>
#include <thread>
#include <chrono>
#include "menu.h"

using namespace std;

/**Observações:
 * compilação:
 * g++ -o <nome_do_executavel> menu.cpp itensA_B_C.cpp
 * 
 * executar ./<nome_do_executavel>
*/

void menu() {
    while (true) {
        cout << "___  ___                  ______     _            _             _  \n";
        cout << "|  \\/  |                  | ___ \\   (_)          (_)           | | \n";
        cout << "| .  . | ___ _ __  _   _  | |_/ / __ _ _ __   ___ _ _ __   __ _| | \n";
        cout << "| |\\/| |/ _ \\ '_ \\| | | | |  __/ '__| | '_ \\ / __| | '_ \\ / _` | | \n";
        cout << "| |  | |  __/ | | | |_| | | |  | |  | | | | | (__| | |_) | (_| | | \n";
        cout << "\\_|  |_|\\___|_| |_|\\__,_| \\_|  |_|  |_|_| |_|\\___|_| .__/ \\__,_|_| \n";
        cout << "                                                   | |             \n";
        cout << "                                                   |_|             \n";
        cout << "Selecione a opcao desejada:\n\n";
        cout << "1: Testar resultado com entrada padrao: a = 1, a matriz [C] e o vetor {v}\n\n";
        cout << "2: Testar resultado com entrada para a, matriz [C] e vetor {v} fornecidos pelo usuario\n\n";
        cout << "3: Encerrar Programa\n\n";

        int opcao;
        cin >> opcao;

        //entrada padrão
        if (opcao == 1) {
            cout << "Entrada padrao: a = 1, a matriz [C] e o vetor {v}\n";
            cout << "Selecione o Metodo:\n\n";
            cout << "1: Metodo Gauss-Normal\n";
            cout << "2: Metodo Gauss-Jordan\n\n";

            //gauss normal
            int opcao1;
            cin >> opcao1;

            //definindo entradas padrao
            vector<vector<double>> C = {{10, 1, 1}, {1, 10, 1}, {1, 1, 10}};
            vector<double> V = {12, 12, 12};
            double a = 1;

            //SubMenu
            if (opcao1 == 1) {
                cout << "Metodo de Gauss-Normal; Entrada padrao" << endl;
                
                int n=3;
                vector<double> solution = solveSystemByCramerGauss(C,V,a);
                cout << "\nSolucao do sistema:" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << "d[" << i + 1 << "] = " << solution[i] << endl;
                }
                this_thread::sleep_for(chrono::seconds(2));
                
            }
            else if (opcao1 == 2) {
                cout << "Metodo de Gauss-Jordan; Entrada padrao" << endl;

                int n = 3;
                vector<double> solution = solveSystemByCramerGaussJordan(C,V,a);
                cout << "\nSolucao do sistema:" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << "d[" << i + 1 << "] = " << solution[i] << endl;
                }
                this_thread::sleep_for(chrono::seconds(2));
            }
            
        } //entradas do usuario
        else if (opcao == 2) {
            cout << "Entrada para a, matriz [C] e vetor {v}\n\n";
            cout << "Selecione o Metodo:\n\n";
            cout << "1: Metodo Gauss-Normal\n";
            cout << "2: Metodo Gauss-Jordan\n\n";

            int opcao1;
            cin >> opcao1;

            
            vector<vector<double>> C, vector<double> V, double a,int n;
            //SubMenu
            if (opcao1 == 1) {
                cout << "Metodo Gauss-Normal selecionado. Informe o numero (n) de colunas e linhas da matriz e o parametro a " << endl;
                cout << "n: "; cin >> n;
                cout << "a: "; cin >> a;
        
                receber_entrada_C(n, C);
                receber_entrada_V (n, V);

                vector<double> solution = solveSystemByCramerGauss(C,V,a);
                cout << "\nSolucao do sistema:" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << "d[" << i + 1 << "] = " << solution[i] << endl;
                }
                this_thread::sleep_for(chrono::seconds(2));

            } else if (opcao1 == 2) {
                cout << "Metodo Gauss-Jordan selecionado. Informe o numero (n) de colunas e linhas da matriz e o parametro a " << endl;
                cout << "n: "; cin >> n;
                cout << "a: "; cin >> a;

                receber_entrada_C(n, C);
                receber_entrada_V(n, V);

                vector<double> solution = solveSystemByCramerGaussJordan(C,V,a);
                cout << "\nSolucao do sistema:" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << "d[" << i + 1 << "] = " << solution[i] << endl;
                }
                this_thread::sleep_for(chrono::seconds(2));

                vector<double> solution = solveSystemByCramerGaussJordan(C,V,a);
            }

        }else if (opcao == 3) {
            cout << "Programa Finalizado" << endl;
            exit(0);
        }
        else {
            cout << "Escolha inválida. Tente novamente.\n";
        }

    }
} 

// MUDAR MENU
int main(){
    menu();
    return 0;
}
