
#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

long long bit[N][N];

void add(int p, int q, long long v) {
  for (int i = p; i < N; i |= i + 1) {
    for (int j = q; j < N; j |= j + 1) {
      bit[i][j] += v;
    }
  }
}

long long find(int p, int q) {
  long long ret = 0;
  for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
    for (int j = q; j >= 0; j = (j & (j + 1)) - 1) {
      ret += bit[i][j];
    }
  }
  return ret;
}

long long at[N][N];

long long get_rand() {
  long long ret = 0;
  for (int i = 0; i < 4; i++) {
    ret = ret * (RAND_MAX + 1) + rand();
  }
  return ret;
}

int main() {
  srand(time(0));

  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  while (q--) {
    int t, a, b, c, d;
    scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
    if (t == 1) {
      long long v = get_rand();
      at[a][b] = v;
      add(a, b, v);
      add(a, d + 1, -v);
      add(c + 1, b, -v);
      add(c + 1, d + 1, v);
    } else if (t == 2) {
      long long v = at[a][b];
      add(a, b, -v);
      add(a, d + 1, v);
      add(c + 1, b, v);
      add(c + 1, d + 1, -v);
    } else {
      puts(find(a, b) == find(c, d)? "Yes" : "No");
    }
  }
  return 0;
}
