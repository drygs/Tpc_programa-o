#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

using namespace std;



void showNumbersGrid(const vector<int>& numbers, int columns){
    const int fixedWidth = 3;

    for (int i = 0; i < numbers.size(); i++){
        cout << setw(fixedWidth) << setfill(' ') << numbers[i] << " ";
       
        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }
}

int main(){
    int numbersRange;
    int manualAutomatico;
    int cardCount;
    int ciclo = 1;
    int bingoNumeros;
    int nSorteado;
    int nSelecionado;
    int cicloBingo = 1;


    srand(time(0));


    for(int i = 0; i < ciclo; i++){
        system("clear || cls");

        cout << "\nEscolha a opção:\n\n1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n"<< endl;
        cin >> manualAutomatico;
        system("clear || cls");

        cout << "Escolha a quantidade de números (75, 90, 100): " << endl;
        cin >> bingoNumeros;

        system("clear || cls");

    for(int j = 0; j < cicloBingo; j++){

        vector<int> meusNumeros(bingoNumeros);
        iota(meusNumeros.begin(), meusNumeros.end(), 1);

        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        showNumbersGrid(meusNumeros, 20);
        cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;



        if (manualAutomatico == 1){
            int sorteioAnterior;
            cout << "Sorteio anterior..: " << nSelecionado << endl;
            int nSorteado = rand() % bingoNumeros;
            int nSelecionado = meusNumeros[nSorteado];
            cout << "Sorteado..........: " << nSelecionado << endl;
            cicloBingo++;
            cout << "Pressione ENTER para sortear a proxima bola" << endl;
            cin.get();
            system("cls || clear");
        
        }else if (manualAutomatico == 2){
            

        }else if (manualAutomatico == 3){
            cout << "Quantos cartões você quer gerar? ";
            cin >> cardCount;

            for (int i = 1; i <= cardCount; i++) {

            }
        }else if (manualAutomatico == 4){
            break;
        }else{
            cout << "Escolha uma opção válida." << endl;
            ciclo++;
        }

    }
    
        
    }

    return 0;
}