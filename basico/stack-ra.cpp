#include <iostream>
#include <stdlib.h>

using namespace std;

int len = 2, topo = 0;
int *v;

int is__empty() {
  return topo == 0;
}

int size_v(){
  int len = sizeof(v) / sizeof(int);
  return len;
}

void resize_v(int x) {
  len = x;
  cout << "--- Ln = " << len << endl;
  v = (int*) realloc(v, len * sizeof(int));
}

void create(){
  v = (int*) malloc(len * sizeof(int));
}

void push(int x) {
  if (topo == len)
    resize_v(2 * len);
  v[topo++] = x;
}

int pop() {
  int x = v[--topo];
  if (topo > 0 && topo == len/4)
    resize_v(len / 2);
  return x;
}

int p_top(){
  return topo - 1;
}

int top(){
  return v[p_top()];
}

void print_v(){
  cout << "--- Pilha ---" << endl;
  for (int i = p_top(); i >= 0; i--){
    cout << "v[" << i << "] = " << v[i] << endl;
  }
  cout << "--- ----- ---" << endl;
  cout << "--- len = " << len << endl;
  cout << "--- ----- ---" << endl;
}

int main() {

  create();

  print_v();

  push(3);
  push(4);
  push(6);
  push(7);
  push(1);

  print_v();

  pop();
  pop();
  pop();
  pop();
  pop();

  print_v();

}
