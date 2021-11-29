#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

struct TItem{
  int chave;
  // Lista de outros valores
};

TItem lista[N];
int IL, FL;

void criar(){
  IL = FL = -1;
  for (int i = 0; i < N; i++){
    lista[i].chave = -1;
  }
}

void carregar(){
  for (int i = 0; i < 3; i++){
    lista[i].chave = i+1;
  }
  IL = 0;
  FL = 2;
}

void inserir(int x){
  int i = IL;
  while (lista[i].chave != -1 && i <= FL) i++;
  if (i < N) {
    lista[i].chave = x;
    FL++;
  }
  else printf("O arranjo esta cheia!");
}

void inserir_inicio(int x){
  if(IL + FL < N - 1) {
    for (int i = FL; i >= IL; i--)
      lista[i + 1] = lista[i];
    lista[IL].chave = x;
    FL++;
  }
  else printf("O arrnajo esta cheio!");
}

void listar(){
  printf("----- Lista -----\n");
  for (int i = IL; i <= FL && lista[i].chave != -1; i++)
    printf("lista[%5d] = %5d\n", i + 1, lista[i].chave);
  printf("-----------------\n");
}

void menu(){
  printf ("========== MENU ==========\n");
  printf ("1 - Incluir\n");
  printf ("2 - Listar\n");
  printf ("3 - Incluir inicio\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main(){
  criar();
  carregar();
  int op = -1;
  int valor = -1;

  do {
    system("clear");
    menu();
    scanf("%d",&op);

    if (op == 1) {
      printf("Infome o valor a inserir: ");
      scanf("%d",&valor);
      inserir(valor);
    }
    if (op == 2) listar();
    if (op == 3) {
      printf("Infome o valor a inserir: ");
      scanf("%d",&valor);
      inserir_inicio(valor);
    }


    // Alternativa de implementação com comando Case
    //switch (opcao){
    //  case 'S': //Entre aspas simples porque é um caracter
    //    system ("cls");
    //    main ();
    //  case 'N': //Entre aspas simples porque é um caracter
    //    return EXIT_SUCCESS;
    //  default:
    //    cout <<"\aOpcao invalida!\n\n";
    //    reiniciar ();
    //}

    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
