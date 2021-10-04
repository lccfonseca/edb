#include <stdio.h>
#include <stdlib.h>

#define N 5

struct TItem{
  int chave;
  // Lista de outros valores
};

TItem lista[N];

void criar(){
  for (int i = 0; i < N; i++){
    lista[i].chave = -1;
  }
}

void inserir(int x){
  int i = 0;
  while (lista[i].chave != -1 && i < N) i++;
  if (i < N) {
    lista[i].chave = x;
    //FL++;
  }
  else printf("A lista esta cheia!");
}

void listar(){
  printf("----- Lista -----\n");
  for (int i = 0; i < N && lista[i].chave != -1; i++)
    printf("lista[%5d] = %5d\n", i + 1, lista[i].chave);
  printf("-----------------\n");
}

void menu(){
  printf ("========== MENU ==========\n");
  printf ("1 - Incluir\n");
  printf ("2 - Listar\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

main(){
  criar();
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
