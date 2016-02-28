#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N], a[N];

int main() {
  for(int i = 0; i < N; i++) {
    p[i] = i;
  }
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int at = (n + i) / 2;
    a[p[at]] = i;
    swap(p[at], p[i]);
  }
  
  for(int i = 1; i <= n; i++) {
    if(i > 1) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
