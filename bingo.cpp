#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric> 
#include <ctime>
#include <cstdlib>

using namespace std;

void showPanel(const vector<int>& sortedNumbers) {
    cout << "Números sorteados: ";
    for (int i = 0; i < sortedNumbers.size(); i++) {
        cout << sortedNumbers[i] << " ";
    }
    cout << endl;

    if (!sortedNumbers.empty()) {
        cout << "Número sorteado: " << sortedNumbers.back() << endl;
        if (sortedNumbers.size() > 1) {
            cout << "Anterior: " << sortedNumbers[sortedNumbers.size() - 2] << endl;
        }
    }
}

void generateCard(int cardNumber, int numbersRange) {
    vector<int> card(numbersRange);
    iota(card.begin(), card.end(), 1);
    random_shuffle(card.begin(), card.end());

    ofstream file("card" + to_string(cardNumber) + ".txt");
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            file << (count < numbersRange ? to_string(card[count]) : "x") << " ";
            count++;
        }
        file << endl;
    }
    file.close();
}

int main() {
    int numbersRange;
    int manualAutomatico;
    int cardCount;

    cout << "Escolha a quantidade de números para o sorteio (75, 90, 100): ";
    cin >> numbersRange;

    srand(time(0)); // Seed the random number generator

    vector<int> sortedNumbers;

    while (true) {
        system("clear || cls");

        showPanel(sortedNumbers);

        cout << "\nEscolha a opção:\n"
             << "1 - Sorteio Manual\n"
             << "2 - Sorteio Automático\n"
             << "3 - Gerar Cartões\n"
             << "4 - Sair\n"
             << endl;
        cin >> manualAutomatico;

        if (manualAutomatico == 1) {
            int novoNumero;
            cout << "Digite o próximo número: ";
            cin >> novoNumero;
            sortedNumbers.push_back(novoNumero);
        } else if (manualAutomatico == 2) {
            int novoNumero = rand() % numbersRange + 1;
            sortedNumbers.push_back(novoNumero);
        } else if (manualAutomatico == 3) {
            cout << "Quantos cartões você quer gerar? ";
            cin >> cardCount;
            for (int i = 1; i <= cardCount; i++) {
                generateCard(i, numbersRange);
            }
        } else if (manualAutomatico == 4) {
            break;
        } else {
            cout << "Escolha uma opção válida." << endl;
        }
    }

    return 0;
}


    
