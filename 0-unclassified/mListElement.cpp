#include "ListElement.h"

using namespace std;

int main() {
  SingleLinkedList a;
  for(int i = 0; i < 10; i++) {
    a.AddFirst(i);
  }
  a.Print();
  printf("\n");
  return 0;
}