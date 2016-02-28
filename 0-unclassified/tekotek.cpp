#include <bits/stdc++.h>

using namespace std;

char s[20];

int main() {
  int n;
  scanf("%s %d", s, &n);
  printf("Anak ayam turunlah %d\n", n);
  for(int i = n - 1; i >= 1; i--) {
    printf("Mati satu tinggallah %d\n", i);
    printf("Anak ayam turunlah %d\n", i);
  }
  printf("Mati satu tinggallah induknya\n");
  return 0;
}
