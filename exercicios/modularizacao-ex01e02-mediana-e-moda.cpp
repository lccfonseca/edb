#include <iostream>

using namespace std;

int N;

void imprime(float *v){
    cout << "--- Vetor ---" << endl;
    for (int i = 0; i < N; i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }
}

void ordenar(float *v){
    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N ; j++){
            if (v[i] >= v[j]){
                int c = v[i];
                v[i] = v[j];
                v[j] = c;
            }
        }
    }
}

/*
 A mediana de um vetor de números é o elemento m do vetor, tal que metade dos números restantes no vetor
 é maior ou igual a m e metade é menor ou igual a m, se o número de elementos no vetor for ímpar. Se o
 número de elementos for par, a mediana será a média dos dois elementos, m1 e m2, tal que metade dos
 elementos restantes é maior ou igual a m1 e m2, e metade dos elementos é menor ou igual a m1 e m2.
 Escreva uma função em C que aceite um vetor de números e retorne a mediana dos números no vetor.
*/

void mediana(float *v, float *m){
    int meio = N / 2;
    cout << "Meio: " << meio << endl;

    if (N % 2 != 0){
        *m = v[meio];
    } else {
        meio--;
        *m = ((v[meio] + v[meio + 1]) / 2);
    }
}

/*
 A MODA de um vetor de números é o número m no vetor que é repetido com maior freqüência.
 Se mais de um número for repetido com freqüência máxima igual, não existirá uma moda. Escreva uma função
 em C que aceite um vetor de números e retorne a moda ou uma indicação de que a moda não existe.
*/

float moda(float *v){
    int maxCont = 1, cont[N];
    float moda;

    for (int i = 0; i < N; i++){
        cont[i] = 1;
        for (int j = i + 1; j < N; j++){
            if (v[i] == v[j]){
                cont[i]++;
                if(cont[i] > maxCont){
                    maxCont = cont[i];
                    moda = v[i];
                }
            }
        }
    }
    cout << "Maior contagem de moda: " << maxCont << endl;
    if (maxCont == 1)
        return -1;
    else return moda;
}

int main(){

    float v[10] = {7, 5, 8, 9, 3, 2, 1, 6, 4, 7};

    N = sizeof(v) / sizeof(v[0]);

    float m;

    imprime(v);
    ordenar(v);
    imprime(v);

    mediana(v, &m);

    cout << "Mediana: " << m << endl;

    cout << "Moda: " << moda(v) << endl;

}
