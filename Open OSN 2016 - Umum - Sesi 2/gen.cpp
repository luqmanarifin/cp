#include <bits/stdc++.h>

using namespace std;

bool s[2005][2005];

int get_rand(int pol) {
  int num = 0;
  long long now = 1;
  while (now < pol) {
    num++;
    now *= RAND_MAX;
  }
  long long ret = 1;
  for (int i = 0; i < num; i++) {
    ret *= rand();
  }
  return ret % pol;
}

int main() {
  printf("asu\n");
  int n = 200, m = 200, k = 200, q = 1000;
  printf("%d %d %d %d\n", n, m, k, q);
  srand(time(NULL));
  int t = 0;
  for (int i = 0; i < k; i++) {
    int u = get_rand(n) + 1;
    int v = get_rand(m) + 1;
    s[u][v] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j]) printf("X");
      else printf(".");
    }
    printf("\n");
  }
  while (q--) {
    int u = rand() % n;
    int v = rand() % m;
    printf("%d %d\n", u + 1, v + 1);
  }
  return 0;
}
