#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
  int dado;
  Node *prox;
};

Node *topo;

void create(Node *topo){
    topo = NULL;
}

int is__empty() {
    return topo == NULL;
}

void push(int x) {
    Node *oldtopo = topo;
    topo = (Node*) malloc(sizeof(Node));
    topo->dado = x;
    topo->prox = oldtopo;
}

int pop(){
    int x = topo->dado;
    topo = topo->prox;
    return x;
}

int top(){
    return topo->dado;
}

void print_s(){
    cout << "--- Pilha ---" << endl;
    Node *oldtopo = topo;
    while (!is__empty()){
        cout << pop() << endl;
    }
    topo = oldtopo;
    cout << "--- ----- ---" << endl;
}

int main(){
    create(topo);

    push(3);
    push(4);
    push(6);
    push(7);
    push(1);

    print_s();

    pop();
    pop();

    print_s();

    cout << "Topo: " << top() << endl;

}
