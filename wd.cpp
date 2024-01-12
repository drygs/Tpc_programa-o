#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

void showNumbersGrid(const vector<int>& numbers, int columns) {
    int maxWidth = to_string(numbers.back()).length(); // Largura máxima baseada no maior número

    for (int i = 0; i < numbers.size(); i++) {
        cout << setw(maxWidth) << numbers[i] << " ";
        
        // Adiciona uma quebra de linha após cada "columns" números
        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }
}

int main() {
    vector<int> myNumbers(100);

    iota(myNumbers.begin(), myNumbers.end(), 1);  // Começa de 1

    // Chama a função para mostrar os números no formato de grade
    showNumbersGrid(myNumbers, 20);

    return 0;
}

