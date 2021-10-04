#include<stdio.h>
#include<string.h>

struct matriz{
  int mat[3][3];
  int somaMatriz;
};

matriz retornaMatriz(){
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matriz m;

  //m.mat = A;

  memcpy(&m.mat, &A, sizeof A);

  return m;
}

int main(){

  matriz m = retornaMatriz();

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      printf("MAT[%d][%d] = %3d\n", i, j, m.mat[i][j]);
}
