#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int manualAutomatico = 0;
    int ciclo = 1;
    int numerosbingo = 0;

    while (ciclo > 0) {
        system("clear || cls");

        cout << "Escolha a opção:\n" << endl;
        cout << "1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n" << endl;
        cin >> manualAutomatico;

        system("clear || cls");

        if (manualAutomatico == 1){

            
            cout << "Escolha a quantidade de números para o sorteio (75, 90, 100): " << endl;
            cin >> numerosbingo;

            vector<int> meuVetor(numerosbingo);
            iota(meuVetor.begin(), meuVetor.end(), 1);

            for (int i = 0; i < ; i++) {
                cout << numerosbingo << endl;
                cout << meuVetor[i] << "";
                cout << numerosbingo << endl;
            }
            cout << endl;


        } else if (manualAutomatico == 2){
           
        } else if (manualAutomatico == 3){
            
        } else if (manualAutomatico == 4){
            ciclo = 0;
        } else {
            cout << "Escolha uma opção disponível: " << endl;
            ciclo++;
        }
    }

    return 0;
}

    
