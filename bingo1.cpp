#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

using namespace std;


void showNumbersGrid(const vector<int>& numbers, int columns){
    int maxWidth = to_string(numbers.back()).length();

    for (int i = 0; i < numbers.size(); i++) {
        cout << setw(maxWidth) << numbers[i] << " ";

        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }
}

void printBlankLines(int numLines) {
    for (int i = 0; i < numLines; ++i) {
        std::cout << std::endl;
    }
}

int main(){
    int numbersRange;
    int manualAutomatico;
    int cardCount;
    int ciclo = 1;
    string padrão= " -";

    srand(time(0));


    for(int i = 0; i < ciclo; i++){
        system("clear || cls");

        cout << "\nEscolha a opção:\n\n1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n"<< endl;
        cin >> manualAutomatico;
        system("clear || cls");

        vector<int> myNumbers(100);
        iota(myNumbers.begin(), myNumbers.end(), 1);


        if (manualAutomatico == 1){
            
            showNumbersGrid(myNumbers, 20);
            int novoNumero;
            cout << "Digite o próximo número: ";
            cin >> novoNumero;

        }else if (manualAutomatico == 2){
            int novoNumero = rand() % numbersRange + 1;

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

    return 0;
}