#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 7

struct TItem {
  int chave;
  // Lista de outros valores
};

struct TLista {
  TItem itens[N];
  int ia, fa, il, fl;
};

int e_vazia(TLista &ll){
  int pn = ll.ia - 1;
  return (ll.il == pn && ll.fl == pn);
}

void criar(TLista &ll) {
  ll.ia = 0;
  ll.fa = N - 1;
  ll.il = ll.fl = ll.ia - 1;
  for (int i = ll.ia; i <= ll.fa; i++) {
    ll.itens[i].chave = -1;
  }
}

void carregar(TLista &ll, int tot) {
  ll.il = ll.ia;
  for (int i = ll.il; i < tot; i++){
    ll.itens[i].chave = i + 1;
    ll.fl++;
  }
}

void inserir_inicio(TLista &ll, int x) {
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

void inserir_k(TLista &ll, int x, int k) {
  if ((ll.ia == ll.il && ll.fa == ll.fl) || (k > ll.fl - ll.il + 2) || (k < 0) || (ll.il == -1 && k != 1))
    printf("A lista esta cheia, ou a posição informada eh incorreta!");
  else {
    if (ll.il == -1)
      ll.il = ll.fl = ll.ia;
    else {
      if (ll.fl != ll.fa) { // Deslocar para o final
        printf("Deslocar final");
        for (int i = ll.fl; i >= ll.il; i--)
          ll.itens[i + 1] = ll.itens[i];
        ll.fl++;
      } else { // Deslocar para o inicio
        printf("Deslocar inicio");
        for (int i = ll.il; i <= ll.fl; i++)
          ll.itens[i - 1] = ll.itens[i];
        ll.il--;
      }
    }
    ll.itens[ll.il + k - 1].chave = x;
  }
}

void inserir_final(TLista &ll, int x) {
  if (ll.ia == ll.il && ll.fa == ll.fl)
    printf("A lista esta cheia!");
  else {
    if (ll.il == -1)
      ll.il = ll.fl = ll.ia;
    else {
      if (ll.fl < ll.fa)
        ll.fl++;
      else {
        for (int i = ll.il; i <= ll.fl; i++)
          ll.itens[i - 1] = ll.itens[i];
        ll.il--;
      }
    }
    ll.itens[ll.fl].chave = x;
  }
}

// Banir com decrementos/deslocamentos sucessivos para o inicio da lista. O(n²)
void banir_d(TLista &ll, int x) {
  int i, j;
  for (i = ll.il; i <= ll.fl; i++)
    if (ll.itens[i].chave == x) {
      for (j = i; j < ll.fl; j++)
        ll.itens[j].chave = ll.itens[j + 1].chave;
      ll.fl--; //Diminui o tamanho da lista, pois eliminou um item.
      i--; // Decrementa o i para reavaliá-lo, já que o proximo elemento trazido pode também ser igual.
    }
}

// Banir que usa uma lista auxiliar para copiar para LL apenas os elementos diferentes de X. O(n), mas aloca mais memória.
void banir_c(TLista &ll, int x) {
  TLista aux;
  aux = ll;
  criar(ll);
  for (int i = aux.il; i <= aux.fl; i++)
    if (aux.itens[i].chave != x)
      inserir_final(ll, aux.itens[i].chave);
}

void listar(TLista &ll) {
  if(!e_vazia(ll)) {
    int p = 1; // Posição na lista, desconsiderando as posições do arranjo.
    printf("----- Lista -----\n");
    for (int i = ll.il; i <= ll.fl; i++) {
      printf("lista[%5d] = %5d\n", p, ll.itens[i].chave);
      p++;
    }
    printf("-----------------\n");
  } else { printf("A lista está vazia!\n"); }
}

void menu(TLista &ll) {
  printf("IA = %3d; FA = %3d;\nIL = %3d; FL = %3d;\n", ll.ia, ll.fa, ll.il, ll.fl);
  printf ("========== MENU ==========\n");
  printf ("1 - Criar lista ou esvaziar a lista\n");
  printf ("2 - Incluir inicio\n");
  printf ("3 - Incluir na posicao k\n");
  printf ("4 - Incluir final\n");
  printf ("8 - Banir Valor\n");
  printf ("9 - Listar\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main() {
  TLista ll;
  criar(ll);
  carregar(ll, 3);
  int k = -1;
  int op = -1;
  int valor = -1;

  do {
    system("clear");
    menu(ll);
    scanf("%d",&op);

    switch (op) {
      case 1:
        criar(ll);
        break;
      case 2:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_inicio(ll, valor);
        break;
      case 3:
        listar(ll);
        printf("Infome a posicao a inserir: ");
        scanf("%d",&k);
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_k(ll, valor, k);
        break;
      case 4:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_final(ll, valor);
        break;
      case 8:
        printf("Infome o valor a banir: ");
        scanf("%d",&valor);
        banir_c(ll, valor);
        break;
      case 9:
        listar(ll);
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
