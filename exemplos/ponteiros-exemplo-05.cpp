#include <iostream>

using namespace std;

int main (){
	int a;
	int *p;
	p = &a;
	*p = 2;
	cout << "\na=" << a;
}
