#include <iostream>
#include <vector>
#include <string>
using namespace std;

string formatarNumeroEmVermelho(int numero) {
    return "\033[31m" + to_string(numero) + "\033[0m";
}

int main() {
    vector<int> meusNumeros = {1, 2, 3, 4, 5};
    vector<std::string> vetorColorido;
    int a = 5;
    int b = 1;
    for(int i = 1; i < 6 ; i++){
    int numeroDestacado = b++;
    
    for(int i = 0; i < 5; i++){
    // Criando o vetor colorido
        for (const auto& numero : meusNumeros) {
            std::string elemento = (numero == numeroDestacado) ? formatarNumeroEmVermelho(numero) : std::to_string(numero);
            vetorColorido.push_back(elemento);
        }
        
    
    // Imprimindo o vetor colorido
        std::cout << "Vetor colorido: ";
        for (const auto& elemento : vetorColorido) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
        cin.get();
    }
    ;
    

    return 0;
}
}


// entender isto pra conseguir mudar a cor dos numeros no outro