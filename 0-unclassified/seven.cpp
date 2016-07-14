#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    if(i > 1) printf(" ");
    if(i % 3 == 0) printf("Comp");
    if(i % 5 == 0) printf("Fest");
    if(i % 7 == 0) printf("Seven");
    if(i % 3 && i % 5 && i % 7) printf("%d", i);
  }
  printf("\n");
  return 0;
}
