#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

using namespace std;

// Função para formatar número em vermelho
string numeroEmVermelho(int destaque) {
    return "\033[31m" + to_string(destaque) + "\033[0m";
}

void showNumbersGrid(const vector<string>& coloredNumbers, int columns) {
    const int fixedWidth = 3;

    for (int i = 0; i < coloredNumbers.size(); i++) {
        cout << setw(fixedWidth) << setfill(' ') << coloredNumbers[i] << " ";

        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }
}

int main() {
    int manualAutomatico;
    int cardCount;
    int ciclo = 1;
    int bingoNumeros;
    int cicloBingo = 1;
    int sorteioAnterior;

    srand(time(0));

    for (int i = 0; i < ciclo; i++) {
        system("clear || cls");

        cout << "\nEscolha a opção:\n\n1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n"
             << endl;
        cin >> manualAutomatico;
        system("clear || cls");

        cout << "Escolha a quantidade de números (75, 90, 100): " << endl;
        cin >> bingoNumeros;

        system("clear || cls");

        vector<int> meusNumeros(bingoNumeros);
        iota(meusNumeros.begin(), meusNumeros.end(), 1);
        vector<string> vetorColorido;

        for (const auto& destaque : meusNumeros) {
            string tabela = (destaque == sorteioAnterior) ? numeroEmVermelho(destaque) : to_string(destaque);
            vetorColorido.push_back(tabela);
        }

         for (const auto& tabela : vetorColorido) {
         }

        for (int j = 0; j < cicloBingo; j++) {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            showNumbersGrid(vetorColorido, 20);
            cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
                 << endl;

            int nSorteado = rand() % bingoNumeros;
            int nSelecionado = meusNumeros[nSorteado];

            if (manualAutomatico == 1) {
                if (meusNumeros[nSorteado] != 0) {
                    nSelecionado = sorteioAnterior;
                    cout << "Sorteio anterior..: " << nSelecionado << endl;
                    cout << "Sorteado..........: " << nSelecionado << endl;
                    sorteioAnterior = nSelecionado;
                    meusNumeros[nSorteado] = 0;
                    cicloBingo++;
                    cout << "Pressione ENTER para sortear a próxima bola" << endl;
                    cin.get();
                    system("cls || clear");
                } else {
                    cicloBingo++;
                    system("cls || clear");
                }
            } else if (manualAutomatico == 2) {
                // Lógica para Sorteio Automático
            } else if (manualAutomatico == 3) {
                cout << "Quantos cartões você quer gerar? ";
                cin >> cardCount;
                for (int i = 1; i <= cardCount; i++) {
                    // Lógica para gerar cartões
                }
            } else if (manualAutomatico == 4) {
                break;
            } else {
                cout << "Escolha uma opção válida." << endl;
                ciclo++;
            }
        }
    }
    return 0;
}
