#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("%c", 'a' + (i % 3));
  }
  printf("\n");
  return 0;
}
