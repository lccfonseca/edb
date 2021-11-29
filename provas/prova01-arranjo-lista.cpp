#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 25

struct TItem{
  int chave;
  // Lista de outros valores
};

struct TLista{
  TItem itens[N];
  int ia, fa, il, fl;
};

TLista ll;

void criar(){
  ll.ia = 0;
  ll.fa = N - 1;
  ll.il = ll.fl = ll.ia - 1;
  for (int i = ll.ia; i <= ll.fa; i++){
    ll.itens[i].chave = -1;
  }
}

void carregar(int tot){
  ll.il = ll.ia;
  for (int i = ll.il; i < tot; i++){
    ll.itens[i].chave = i + 1;
    ll.fl++;
  }
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

void inserir_k(int x, int k){
  if ((ll.ia == ll.il && ll.fa == ll.fl) || (k > ll.fl - ll.il + 2) || (k < 0) || (ll.il == -1 && k != 1))
    printf("A lista esta cheia, ou a posição informada eh incorreta!");
  else {
    if (ll.il == -1)
      ll.il = ll.fl = ll.ia;
    else {
      if (ll.fl != ll.fa){ // Deslocar para o final
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

void inserir_final(int x){
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

int busca_s(int x){
  for (int i = ll.il; i <= ll.fl; i++){
    if (ll.itens[i].chave == x)
      return i;
  }
  return -1;
}

int size_contagem(){
  int cont = 0;
  for (int i = ll.il; i <= ll.fl; i++){
    cont++;
  }
  return cont;
}

int size_calculo(){
  //Se o IL foi 0 vai quebrar!
  return ll.fl - ll.il + 1;
}

int impares(){
  int cont = 0;
  for (int i = ll.il; i <= ll.fl; i++){
    if ((ll.itens[i].chave % 2) != 0)
      cont++;
  }
  return cont;
}

int pares(int *v){
  int j = 0;
  for (int i = ll.il; i <= ll.fl; i++){
    if ((ll.itens[i].chave % 2) == 0){
      v[j] = ll.itens[i].chave;
      j++;
    }
  }
  return j;
}


void listar(){
  printf("----- Lista -----\n");
  for (int i = ll.il; i <= ll.fl; i++)
    printf("lista[%5d] = %5d\n", i + 1, ll.itens[i].chave);
  printf("-----------------\n");
}

void menu(){
  printf("IA = %3d; FA = %3d;\nIL = %3d; FL = %3d;\n", ll.ia, ll.fa, ll.il, ll.fl);
  printf ("========== MENU ==========\n");
  printf ("1 - Incluir inicio\n");
  printf ("2 - Incluir na posicao k\n");
  printf ("3 - Incluir final\n");
  printf ("4 - Listar\n");
  printf ("5 - Busca Sequencial\n");
  printf ("6 - Num de elementos (Contagem)\n");
  printf ("7 - Num de elementos (Calculo)\n");
  printf ("8 - Num de elementos impares\n");
  printf ("9 - Listar elementos pares\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main(){
  criar();
  carregar(13);
  int k = -1;
  int op = -1;
  int valor = -1;
  int res = -1;
  int vet[N];

  do {
    system("clear");
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_inicio(valor);
        break;
      case 2:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        printf("Infome a posicao a inserir: ");
        scanf("%d",&k);
        inserir_k(valor, k);
        break;
      case 3:
        printf("Infome o valor a inserir: ");
        scanf("%d",&valor);
        inserir_final(valor);
        break;
      case 4:
        listar();
        break;
      case 5:
        printf("Infome o valor buscado (sequencial): ");
        scanf("%d",&valor);
        res = busca_s(valor);
        printf("O valor buscado está na posição [%d] do arranjo e na posição [%d] da lista.", res, res + 1);
        break;
      case 6:
        res = size_contagem();
        printf("Tamanho da lista (Contagem): [%d]", res);
        break;
      case 7:
        res = size_calculo();
        printf("Tamanho da lista (Contagem): [%d]", res);
        break;
      case 8:
        res = impares();
        printf("O total de elementos impares eh: [%d]", res);
        break;
      case 9:
        res = pares(vet);
        printf("----- Lista -----\n");
        for (int i = 0; i < res; i++)
          printf("vet[%5d] = %5d\n", i + 1, vet[i]);
        printf("-----------------\n");
        printf("O total de elementos pares eh: [%d]", res);
        break;
    }

    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
