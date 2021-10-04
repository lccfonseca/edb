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

//Para fins didaticos renomeio o Tipo Nodo para Lista,
//assim posso dar a impressão de que estou passando como
//parametro a Lista completa e não apenas um Nodo.
typedef struct Nodo Lista;

void criar(Lista *c) {
  c->prox = NULL;
}

int vazia(Lista *c) {
  return (c == NULL);
}

Nodo* alocar(int e_cabeca){
  Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
  novo->prox = NULL;
  if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    if (!e_cabeca) {
      printf("Insira o novo elemento: ");
      scanf("%d", &novo->dado.chave);
    }
    return novo;
  }
}

int inserir_inicio(Lista *c) {
  Nodo *novo = alocar(0);
  novo->prox = c->prox;
  c->prox = novo;
}

int inserir_fim(Lista *c) {
  Nodo *novo = alocar(0);
  //Verifica se a lista está vazia
  if (vazia(c->prox))
    //Caso a lista esteja vazia, apenas cria o primeiro elemento
    c->prox = novo;
  else {
    //Caso a lista não estejja vazia, cria-se um ponteiro auxiliar para fazer o deslocamento
    //entre os nodos, até o final da lista.
    Nodo *p = c;
    while (!vazia(p->prox))
      p = p->prox;
    //Após encontrar o final da lista faz com que ela aponte para o novo elemento.
    p->prox = novo;
  }
}

int inserir_meio(Lista *c, int k) {
  Nodo *novo = alocar(0);
  //Verifica se a lista está vazia e o k é igual a 1 ou a posição é menor que 1. Resultando em posições inválidas
  if ((vazia(c->prox) && k != 1) || (k < 1)) {
    free(novo);
    return 0;
  }
  else
    if (k == 1){
      //Inserir no início da lista
      novo->prox = c->prox;
      c->prox = novo;
      return 1;
    }
    else {
      Nodo *p = c;
      while (!vazia(p->prox) && (k > 1)) {
        p = p->prox;
        k--;
      }
      if (k > 1) {
        free(novo);
        return 0;
      } else {
        novo->prox = p->prox;
        p->prox = novo;
        return 1;
      }
    }
}

void destruir(Lista *c){
  while (!vazia(c->prox)){
    Nodo *p = c->prox;
    c->prox = c->prox->prox;
    free(p);
  }
  free(c);
}

void listar(Lista *c) {
  //A variável i serve apenas para apresentar a ordem dos elemento impressos
  int i = 0;
  //O ponteiro p serve para fazer o deslocamento entre os elementos.
  Nodo *p = c->prox;

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
  printf ("2 - Incluir fim\n");
  printf ("3 - Incluir meio\n");
  printf ("\n");
  printf ("8 - Destruir\n");
  printf ("9 - Listar\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main() {
  Lista *cabeca = alocar(1);
  criar(cabeca);

  int k = -1;
  int op = -1;

  do {
    system("clear");
    printf("Lista vazia? (%d)\n", vazia(cabeca->prox));
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        inserir_inicio(cabeca);
        break;
      case 2:
        inserir_fim(cabeca);
        break;
      case 3:
        listar(cabeca);
        printf("Informe a posição para inserir: "); scanf("%d", &k);
        inserir_meio(cabeca, k);
        break;
      case 8:
        destruir(cabeca);
        cabeca = alocar(1);
        break;
      case 9:
        listar(cabeca);
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
