
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
  int item;
  Node *next;
};

Node *first;
Node *last;
int N = 0;

void create(){
    first = last = NULL;
    N = 0;
}

int is__empty() {
    return first == NULL;
}

int is__null(Node *node) {
    return node == NULL;
}

void insert_eol(int x){
    Node *ol = last;
    last = (Node*) malloc(sizeof(Node));
    last->item = x;
    last->next = NULL;
    if (is__empty()) first = last;
    else ol->next = last;
    N++;
}

void insert_bol(int x){
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->item = x;
    novo->next = first;
    first = novo;
    N++;
}

void print_r(Node *p){
    if (!is__null(p)){
        cout << p->item << endl;
        print_r(p->next);
    }
}

void print_i(){
    Node *p = first;
    cout << "--- Lista ---" << endl;
    while (!is__null(p)) {
        cout << p->item << endl;
        p = p->next;
    }
    cout << "--- ----- ---" << endl;
}

void inverte(){
    Node *p = first;
    while (!is__null(p)) {
        insert_bol(p->item);
        p = p->next;
    }
}

int main() {
    create();

    insert_eol(3);
    insert_eol(32);
    insert_eol(7);
    insert_eol(4);

    print_r(first);

    //Letra A da primeira questão da lista de exercícios 02
    inverte();

    print_i();
}
