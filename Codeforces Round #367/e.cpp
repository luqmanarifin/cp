#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int l[N][N], r[N][N], u[N][N], z[N][N];
int v[N][N];

void swap_left(int f, int g) {
  int fi = f / N;
  int fj = f % N;
  int gi = g / N;
  int gj = g % N;
  swap(l[fi][fj], l[gi][gj]);
  int ai = l[fi][fj] / N;
  int aj = l[fi][fj] % N;
  int bi = l[gi][gj] / N;
  int bj = l[gi][gj] % N;
  swap(r[ai][aj], r[bi][bj]);
}

void swap_right(int f, int g) {
  int fi = f / N;
  int fj = f % N;
  int gi = g / N;
  int gj = g % N;
  swap(r[fi][fj], r[gi][gj]);
  int ai = r[fi][fj] / N;
  int aj = r[fi][fj] % N;
  int bi = r[gi][gj] / N;
  int bj = r[gi][gj] % N;
  swap(l[ai][aj], l[bi][bj]);
}

void swap_up(int f, int g) {
  int fi = f / N;
  int fj = f % N;
  int gi = g / N;
  int gj = g % N;
  swap(u[fi][fj], u[gi][gj]);
  int ai = u[fi][fj] / N;
  int aj = u[fi][fj] % N;
  int bi = u[gi][gj] / N;
  int bj = u[gi][gj] % N;
  swap(z[ai][aj], z[bi][bj]);
}

void swap_down(int f, int g) {
  int fi = f / N;
  int fj = f % N;
  int gi = g / N;
  int gj = g % N;
  swap(z[fi][fj], z[gi][gj]);
  int ai = z[fi][fj] / N;
  int aj = z[fi][fj] % N;
  int bi = z[gi][gj] / N;
  int bj = z[gi][gj] % N;
  swap(u[ai][aj], u[bi][bj]);
}  

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j) {
        int c = i * N + j - 1;
        l[i][j] = c;
      }
      if (j + 1 < N) {
        int c = i * N + j + 1;
        r[i][j] = c;
      }
      if (i) {
        int c = (i - 1) * N + j;
        u[i][j] = c;
      }
      if (i + 1 < N) {
        int c = (i + 1) * N + j;
        z[i][j] = c;
      }
    }
  }
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  while (q--) {
    int a, b, c, d, h, w;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
    int f = 0, g = 0;
    for (int i = 0; i < a; i++) f = z[f / N][f % N];
    for (int i = 0; i < b; i++) f = r[f / N][f % N];
    for (int i = 0; i < c; i++) g = z[g / N][g % N];
    for (int i = 0; i < d; i++) g = r[g / N][g % N];
    
    for (int i = 0; i < h; i++) {
      swap_left(f, g);
      if (i + 1 < h) {
        f = z[f / N][f % N];
        g = z[g / N][g % N];
      }
    }
    for (int i = 0; i < w; i++) {
      swap_down(f, g);
      if (i + 1 < w) {
        f = r[f / N][f % N];
        g = r[g / N][g % N];
      }
    }
    for (int i = 0; i < h; i++) {
      swap_right(f, g);
      if (i + 1 < h) {
        f = u[f / N][f % N];
        g = u[g / N][g % N];
      }
    }
    for (int i = 0; i < w; i++) {
      swap_up(f, g);
      if (i + 1 < w) {
        f = l[f / N][f % N];
        g = l[g / N][g % N];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int now = r[i][0];
    while (now % N <= m) {
      int a = now / N;
      int b = now % N;
      printf("%d ", v[a][b]);
      now = r[a][b];
    }
    printf("\n");
  }
  return 0;
}
