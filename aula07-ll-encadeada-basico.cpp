#include <stdio.h>
#include <stdlib.h>

struct Dado {
  int chave;
  // Lista de outros valores
};

struct Nodo {
  Dado dado;
  Nodo *prox;
};

typedef struct Nodo Lista;

void criar(Nodo **c) {
  *(c) = NULL;
}

int vazia(Nodo *c) {
  return (c == NULL);
}

Nodo* alocar(){
  //Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
  Nodo *novo = new Nodo;
  if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    printf("Insira o novo elemento: "); scanf("%d", &novo->dado.chave);
    return novo;
  }
}

int inserir_inicio(Nodo **c) {
  Nodo *novo = alocar();
  novo->prox = *(c);
  *(c) = novo;
}

void listar(Nodo *c) {
  int i = 0;
  Nodo *p = c;

  if (vazia(p)) {
    printf("A lista está vazia!\n");
    return;
  }

  printf("\n------ Lista ------\n");
  while (!vazia(p)){
    i++;
    printf("#lista[%4d] = %4d\n", i, p->dado.chave);
    p = p->prox;
  }
  printf("-------------------\n");
}

void menu() {
  //printf("IA = %3d; FA = %3d;\nIL = %3d; FL = %3d;\n", ll.ia, ll.fa, ll.il, ll.fl);
  printf ("========== MENU ==========\n");
  printf ("1 - Incluir inicio\n");
  printf ("\n");
  printf ("9 - Listar\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main() {

  Lista *pll;
  criar(&pll);


  int k = -1;
  int op = -1;

  do {
    system("clear");
    printf("Lista vazia? (%d)\n", vazia(pll));
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        inserir_inicio(&pll);
        break;
      case 9:
        listar(pll);
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
