#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
bool done[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  printf("1");
  
  int p = n;
  for (int t = 1; t <= n; t++) {
    done[a[t]] = 1;
    while (done[p] && p > 0) p--;
    int ada = t;
    int udah = n - p;
    int ans = ada - udah + 1;
    printf(" %d", ans);
  }
  printf("\n");
  return 0;
}
