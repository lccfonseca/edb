#include <iostream>

using namespace std;

int resultado;

//Declaração de função. As funções são sub-rotinas que retornam valor.
int soma(int a, int b){
    int c = a + b;
    return c;
}

void soma1(int a, int b, int &res){
    res = a + b;
}

//Neste caso não é uma função, pois não tem tipo de retorno e também não usa passagem por referencia.
void soma2(int a, int b){
    resultado = a + b;
}

void soma3(int a, int b, int *res){
    *res = a + b;
}


void troca(int &a, int &b){
    int c;
    c = a;
    a = b;
    b = c;
    cout << "Valor de A: " << a
         << "\nValor de B: " << b << endl;
}

void troca1(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
    cout << "Valor de A: " << *a
         << "\nValor de B: " << *b << endl;
}

int main(){

    int a, b, c = 0;

    a = 2;
    b = 3;

    //c = soma(a, b);
    //soma1(a, b, c);
    //soma2(a, b);
    soma3(a, b, &c);

    //troca(a, b);
    troca1(&a, &b); //Para uso da função troca1, é necessário passar os endereços de memória das variáveis utilizadas como parâmetros. Deve-se utilizar o operador &;

    cout << "Valor de A: " << a
         << "\nValor de B: " << b
         << "\nValor de C: " << c
         << "\nValor de Resultado: " << resultado << endl;
}
