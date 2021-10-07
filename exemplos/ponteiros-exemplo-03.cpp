#include <iostream>

using namespace std;

int main(){

  int x=4, y=7;

  int *px, *py;

  cout << "\n&x = " << &x << "\t	x = " << x;
  cout << "\n&y = " << &y << "\t	y = " << y;

  px = &x;
  py = &y;

  cout << "\n\npx = " << px << "\t	*px = " << *px;
  cout << "\npy = " << py << "\t	*py = " << *py;
}
