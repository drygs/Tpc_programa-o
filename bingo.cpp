#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
#include <fstream>

using namespace std;

// Function to format number in red
string numeroEmVermelho(int destaque) {
    return "\033[31m" + to_string(destaque) + "\033[0m";
}

// Function to generate bingo cards
void ncartoes(int numerosCartoes) {
    for (int i = 1; i <= numerosCartoes; i++) {
        // Logic to generate cards - adjust as necessary
        ofstream file("cartao" + to_string(i) + ".txt");
        if (file.is_open()) {
            // Write card data to the file
            file << "Conteúdo do cartão " << i << "\n";
            file.close();
            cout << "Cartão " << i << " gerado com sucesso.\n";
        } else {
            cerr << "Erro ao abrir o arquivo para o cartão " << i << ".\n";
        }
    }
}

// Function to display numbers grid
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
    int ciclo = 1;
    int bingoNumeros = 1;
    int cicloBingo = 1;
    int sorteioAnterior = 0;
    int anterior = 0;
    int numerosCartoes = 1;

    srand(time(0));

    for (int i = 0; i < ciclo; i++) {
        system("clear || cls");

        cout << "\nEscolha a opção:\n\n1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n" << endl;
        cin >> manualAutomatico;
        system("clear || cls");

        if (manualAutomatico == 1 || manualAutomatico == 2) {
            cout << "Escolha a quantidade de números (75, 90, 100): " << endl;
            cin >> bingoNumeros;
        } else {
            system("clear || cls");
        }

        system("clear || cls");

        vector<int> meusNumeros(bingoNumeros);
        iota(meusNumeros.begin(), meusNumeros.end(), 0);
        vector<string> vetorColorido;

        for (const auto& destaque : meusNumeros) {
            string tabela = (destaque == sorteioAnterior) ? numeroEmVermelho(destaque) : to_string(destaque);
            vetorColorido.push_back(tabela);
        }

        for (int j = 0; j < cicloBingo; j++) {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            showNumbersGrid(vetorColorido, 20);
            cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;

            if (manualAutomatico == 3 || manualAutomatico == 4) {
                system("cls || clear");
            }

            int nSorteado = rand() % bingoNumeros;
            int nSelecionado = meusNumeros[nSorteado];

            if (manualAutomatico == 1) {
                if (meusNumeros[nSorteado] != 0) {
                    anterior = sorteioAnterior;
                    cout << "Sorteio anterior..: " << anterior << endl;
                    cout << "Sorteado..........: " << vetorColorido[nSorteado] << endl;
                    sorteioAnterior = nSelecionado;
                    cicloBingo++;
                    cout << "Pressione ENTER para sortear a próxima bola" << endl;
                    vetorColorido[nSorteado] = numeroEmVermelho(nSorteado);
                    meusNumeros[nSorteado] = 0;
                    cin.ignore();
                    system("cls || clear");
                } else {
                    cicloBingo++;
                    system("cls || clear");
                }
            } else if (manualAutomatico == 2) {
                if (meusNumeros[nSorteado] != 0) {
                    anterior = sorteioAnterior;
                    cout << "Sorteio anterior..: " << anterior << endl;
                    cout << "Sorteado..........: " << vetorColorido[nSorteado] << endl;
                    sorteioAnterior = nSelecionado;
                    vetorColorido[nSorteado] = numeroEmVermelho(nSorteado);
                    meusNumeros[nSorteado] = 0;
                    sleep(2);
                    cicloBingo++;
                    system("cls || clear");
                } else {
                    cicloBingo++;
                    system("cls || clear");
                }
            } else if (manualAutomatico == 3) {
                cout << "Quantos cartoes pertende gerar? " << endl;
                cin >> numerosCartoes;
                ncartoes(numerosCartoes);
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
