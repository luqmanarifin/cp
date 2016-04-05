#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(j > 0) printf(" ");
      printf("%d", i * n + j + 1);
    }
    printf("\n");
  }
  return 0;
}
