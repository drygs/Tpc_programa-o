#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int manualAutomatico = 0;
int ciclo = 1;

int main(){

    for(int i = 0; i < ciclo; i++){
        
        system("clear || cls");

        cout << "Escolha a opção:\n" << endl;
        cout << "1 - Sorteio Manual\n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n" << endl;
        cin >> manualAutomatico;

        if(manualAutomatico == 1){

            vector<int> meuVetor(100);

            iota(meuVetor.begin(), meuVetor.end(), 1);
            
            cout << "Primeiros 10 elementos do vetor:" << endl;
            for (int i = 0; i < 10; i++) {
                cout << meuVetor[i] << " ";
        }



        }
        else if(manualAutomatico == 2){

        }
        else if(manualAutomatico == 3){


        }
        else if(manualAutomatico == 4){


        }else{

            cout << "Escolha uma opcão disponivel: " << endl;
            ciclo ++;

        }
    }

}
    
