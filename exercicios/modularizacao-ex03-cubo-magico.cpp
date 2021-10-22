
#include <iostream>

using namespace std;

#define N 3

void imprime(float *v, char *titulo){
    cout << "--- Vetor " << titulo << " ---" << endl;
    for (int i = 0; i < N; i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }
}

/*
 Uma matriz quadrada inteira é chamada de "quadrado mágico" se a soma dos elementos de cada linha,
 a soma dos elementos de cada coluna e a soma dos elementos das diagonais principal e secundária
 são todos iguais.
 Escrever uma função que verifica se uma matriz de n linhas e colunas representa um quadrado mágico.
*/

bool eh_cubo (float v[N][N]){

    float soma_linhas[N] = {0, 0, 0};
    float soma_colunas[N] = {0, 0, 0};
    float soma_dp = 0, soma_ds = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            soma_linhas[i] = soma_linhas[i] + v[i][j];
            soma_colunas[j] = soma_colunas[j] + v[i][j];
            //Soma elementos da DP
            if (i == j) soma_dp = soma_dp + v[i][j];
            //Soma elementos da DS
            if ((i + j) == (N - 1)) soma_ds = soma_ds + v[i][j];
        }
    }

    //Impressão das somas
    imprime(soma_linhas, "Linhas");
    imprime(soma_colunas, "Colunas");
    cout << "Soma DP: " << soma_dp << endl;
    cout << "Soma DS: " << soma_ds << endl;

    //Verificação se as somas são iguais
    if (soma_dp != soma_ds){
        return false;
    }
    for (int i = 0; i < N; i++){
        if ((soma_dp != soma_linhas[i]) || (soma_dp != soma_colunas[i])){
            return false;
        }
    }

    return true;
}

int main(){

    float m[N][N] = {{8, 0, 7},
                     {4, 5, 6},
                     {3, 10, 2}};

    bool res = eh_cubo(m);

    cout << "Eh cubo mágico? " << res << endl;

}
