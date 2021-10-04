#include<stdio.h>

void troca(int *p, int *q){
	int temp;
	temp = *p; *p = *q; *q = temp;
}

void main(){
  int i, j;
  i = 2;
  j = 3;
  troca (&i, &j);
  printf("%d, %d", i, j);
}
