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
 * 
 * 
 * Fluxo 1 >> 2 = Executar NewtonItemA
 *  -> a funcao precisa do d0 para executar = ver linha 99
 * 
 * Dados de saída: quadros resposta (com d e erro para cada a3 e a2 e l e método) e comparativo.
      Isso é pra tabela que esta imprimindo? Precisamos fazer a funcao do calculo do erro 
      relativo das respostas obtidas e adicionara coluna na tabela de saida (?)
 * 
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
        cout << "2: Testar resultado com entrada para a, matriz [C] e vetor {v} fornecidos pelo usuário\n\n";
        cout << "3: \n\n";
        cout << "4: Encerrar Programa\n\n";

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
            double a2 = 1, a3 = 1, d0 = 0.5, e = 0.001, lambda = 0.05;
            //SubMenu
            if (opcao1 == 1) {
                cout << "Metodo Newton padrao; Entrada padrao" << endl;
                
                //codigo do item A entrada padrao
                // newton_itemA( a3,  a2,  d0,  epsilon);
                newton_itemA(1, 1, 0.5, 0.001);
                this_thread::sleep_for(chrono::seconds(2));
                
            }
            else if (opcao1 == 2) {
                cout << "Metodo Newton FL; Entrada padrao" << endl;
                //Codigo do item B entrada padrao
                // newton_itemB( a3,  a2,  d0, lambda, epsilon);
                newton_itemB(1, 1, 0.5, 0.05, 0.001);
                this_thread::sleep_for(chrono::seconds(2));
            }
            
        } //entradas do usuario
        else if (opcao == 2) {
            cout << "N entradas diferentes para Lambda, a2 e a3 e uma precisao e especifica e\n\n";
            cout << "Selecione o Metodo:\n\n";
            cout << "1: Metodo Newton Padrao\n";
            cout << "2: Metodo Newton FL\n\n";

            int opcao1;
            cin >> opcao1;

            int N1;
            double e1, a21, a31, lambda1;
            //SubMenu
            if (opcao1 == 1) {
                cout << "Metodo Newton padrao selecionado. Informe o número (N) de opções para lambda. " << endl;
                cout << "N: "; cin >> N1;
                cout << "e: "; cin >> e1;

                for (int i = 0; i < N1; i++){
                    //a2
                    cout << "a2: " << endl; cin >> a21;
                    //a3
                    cout << "a3: " << endl; cin >> a31;
                    //**********************************************************************
                    //OBS.: o enunciado diz: "Desenvolva um sistema para calcular o valor de d 
                    // de uma oscilação de um determinado balanço." 
                    // Ele não dá o d0.
                    // Escolhemos arbitrariamente d0=0.5 => colocar em discussao
                    
                    //double newton_itemA(double a3, double a2, double d0, double epsilon);
                    newton_itemA(a31, a21, 0.5, e1);
                }
                this_thread::sleep_for(chrono::seconds(2));
                //cout << setw(3) << "k" << " | " << setw(12) << "d" << " | " << setw(12) << "f(d)"<< endl;
            } else if (opcao1 == 2) {
                cout << "Metodo Newton FL; Entrada N";
                //N
                cout << "N: ";
                cin >> N1;
                //e
                cout << "e: ";
                cin >> e1;

                // cout << setw(3) << "k" << " | " << setw(12) << "d" << " | " << setw(12) << "f(d)"<< endl;
                for (int i = 0; i < N1; i++) {
                //lambda
                cout << "lambda: "; cin >> lambda1;
                //a2
                cout << "a2: "; cin >> a21;
                //a3
                cout << "a3: "; cin >> a31;
                // **************  OBS.: O mesmo problema da linha 82 **********
                newton_itemB(a31, a21, 0.5, lambda1, e1);
                }
                this_thread::sleep_for(chrono::seconds(2));
                
            }
        } else if (opcao ==3){

            // c) Implementar método numérico para achar derivada de f(d) e refazer item a.
            newton_itemC(1, 1, 0.5, 0.05, 0.001, 0.0001);
            this_thread::sleep_for(chrono::seconds(2));


        }else if (opcao == 4) {
            cout << "Programa Finalizado" << endl;
            exit(0);
        }
        else {
            cout << "Escolha inválida. Tente novamente.\n";
        }

    }
} 
//Func p pegar as N entradas quando o metodo selecionado for o newton padrao
void EnterNewtonPadrao(int N, double e, double a2, double a3, double lambda){
    //N
    cout << "N: ";
    cin >> N;
    //e
    cout << "e: ";
    cin >> e;

    //N a2, a3 e lambda
    for (int i = 0; i < N; i++) {
        //lambda
        cout << "lambda: "; cin >> lambda;
        //a2
        cout << "a2: "; cin >> a2;
        //a3
        cout << "a3: "; cin >> a3;
        
        //Codigo do metodo selecionado para lambda, a2 e a3 da interação (Newton Padrao)(codigo do item A)
        }
};

//Func pra pegar as entradas quando o metodos selecionado for o newton FL
void EnterNewtonFL(int N, double e, double a2, double a3, double lambda){
    //N
    cout << "N: ";
    cin >> N;
    //e
    cout << "e: ";
    cin >> e;

    //N a2, a3 e lambda
    for (int i = 0; i < N; i++) {
        //lambda
        cout << "lambda: "; cin >> lambda;
        //a2
        cout << "a2: "; cin >> a2;
        //a3
        cout << "a3: "; cin >> a3;
        
        //Codigo do metodo selecionado para lambda, a2 e a3 da interação (FL)(Codigo do item B)
        }
};

// MUDAR MENU
int main(){
    menu();
    return 0;
}
