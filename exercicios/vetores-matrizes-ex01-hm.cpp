#include <iostream>

using namespace std;

void hm(int *t, int *h, int *m){
    *h = *t / 60;
    *m = *t % 60;
}

void min_max(int *v, int *mn, int *mx){
    *mn = v[0];
    *mx = v[0];

    for (int i = 1; i < 10; i++){
        if (v[i] < *mn)
            *mn = *(v + i); // v+i
        else if (v[i] > *mx)
            *mx = v[i];
    }
}

int main(){
    int t = 127, h = 0, m = 0;

    hm(&t, &h, &m);

    cout << "Horas: " << h << endl;
    cout << "Minutos: " << m << endl;


    int v[10] = {9, 7, 4, 5, 2, 1, 6, 3, 8, 10};

    int *vt;
    vt = (int*) malloc(10 * sizeof(int));

    int mn, mx;

    min_max(v, &mn, & mx);

    cout << "Minimo: " << mn << endl;
    cout << "Maximo: " << mx << endl;

    //No meu computador a diferença em bytes foi de 4 unidades, ou seja, um inteiro ocupa 4 bytes;
    cout << "Endereco inicial: " << &vt[0] << endl;
    cout << "Endereco inicial: " << &*(vt + 4) << endl;
    cout << "Tamanho de um inteiro: " << sizeof(int) << endl;
}
