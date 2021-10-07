#include <iostream>

using namespace std;

int main(){
  int x, y;
  int *p=&x; //inicializa p com o endereço de x

  *p = 14;   //equivale a x = 14
  y  = *p;   //equivale a y = x

  cout << "\ny = " << y;
}
