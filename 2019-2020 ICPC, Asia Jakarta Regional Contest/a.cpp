#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (i) printf(" ");
    printf("%d", n - v + 1);
  }
  printf("\n");
  return 0;
}
