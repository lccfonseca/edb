#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

struct TItem{
  int chave;
  // Lista de outros valores
};

struct TLista{
  TItem itens[N];
  int ia = 0;
  int fa = N - 1;
  int il = -1;
  int fl = -1;
};

TLista ll;

void criar(){
  for (int i = ll.ia; i <= ll.fa; i++){
    ll.itens[i].chave = -1;
  }
}

void carregar(int tot){
  ll.il = 0;
  for (int i = ll.ia; i < tot; i++){
    ll.itens[i].chave = i + 1;
    ll.fl++;
  }
}

void inserir(int x){
  int i = 0;
  while (ll.itens[i].chave != -1 && i <= ll.fa) i++;
  if (i <= ll.fa) {
    ll.itens[i].chave = x;
    ll.fl++;
  }
  else printf("A lista esta cheia!");
}

void inserir_inicio(int x){
  if(ll.il == ll.ia && ll.fl == ll.fa) {
    printf("A lista esta cheia!");
  } else {
    if (ll.il == -1){
      ll.il = ll.fl = ll.ia;
    } else {
      if (ll.il > ll.ia) {
        ll.il--;
      } else {
        for (int i = ll.fl; i >= ll.il; i--)
          ll.itens[i + 1] = ll.itens[i];
        ll.fl++;
      }
    }
    ll.itens[ll.il].chave = x;
  }
}

void listar(){
  printf("----- Lista -----\n");
  for (int i = 0; i <= ll.fl; i++)
    printf("lista[%5d] = %5d\n", i + 1, ll.itens[i].chave);
  printf("-----------------\n");
}

void menu(){
  printf("IA = %3d; FA = %3d;\nIL = %3d; FL = %3d;\n", ll.ia, ll.fa, ll.il, ll.fl);
  printf ("========== MENU ==========\n");
  printf ("1 - Incluir\n");
  printf ("2 - Listar\n");
  printf ("3 - Incluir inicio\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main(){
  criar();
  carregar(3);
  int op = -1;
  int valor = -1;

  do {
    system("clear");
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir(valor);
        break;
      case 2:
        listar();
        break;
      case 3:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_inicio(valor);
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
