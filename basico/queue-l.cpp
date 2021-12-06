
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
  int item;
  Node *next;
};

Node *head;
int N = 0;

void create(){
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    N = 0;
}

int is__empty() {
    return head->next == NULL;
}

int is__null(Node *node) {
    return node == NULL;
}

void enqueue(int x){
    // Alocação do novo elemento
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->item = x;
    novo->next = NULL;

    // Como nesta implementação não temos um ponteiro para o ultimo elemento, devemos procurar ele a cada inserção;
    // A variável p, é uma vairável temporária para auxiliar na navegação da lista
    Node *p = head;
    while (!is__null(p->next)) p = p->next;

    // Efetivamente preenche o ultimo elemento
    p->next = novo;
    N++;
}

int dequeue(){
    int x = head->next->item;
    head->next = head->next->next;
    N--;
    return x;
}

void print_r(Node *p){
    if (!is__null(p)){
        cout << p->item << endl;
        print_r(p->next);
    }
}

void print_i(){
    Node *p = head->next;
    cout << "--- Lista ---" << endl;
    while (!is__null(p)) {
        cout << p->item << endl;
        p = p->next;
    }
    cout << "--- ----- ---" << endl;
}

int main() {
    create();

    enqueue(3);
    enqueue(32);
    enqueue(7);
    enqueue(4);

    print_r(head->next);

    //Letra A da primeira questão da lista de exercícios 02
    enqueue(dequeue());

    print_i();
}
