#include <iostream>

using namespace std;

int main(){
	int a, b, *p;
	a = 2;
	p = &b;
	*p = 3;
	b = a + (*p);
	cout << "\nb = " << b;
}
