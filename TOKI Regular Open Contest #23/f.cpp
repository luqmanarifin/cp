#include <bits/stdc++.h>

using namespace std;

const int N = 14;

int a[N][N];
long long dua[N], tiga[N];

int ask(long long n) {
  printf("? %lld\n", n);
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

void answer(long long n, long long m) {
  printf("! %lld %lld\n", n, m);
  fflush(stdout);
}

int main() {
  dua[0] = tiga[0] = 1;
  for (int i = 1; i < N; i++) {
    dua[i] = dua[i - 1] * 2;
    tiga[i] = tiga[i - 1] * 3;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = ask(dua[i] * tiga[j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < i; k++) {
        for (int l = j + 1; l < N; l++) {
          if (a[i][j] == a[k][l] && a[i][j] == a[k][j] && a[i][j] == a[i][l]) {
            answer(dua[i] * tiga[j], dua[k] * tiga[l]);
            return 0;
          }
        }
      }
    }
  }
  assert(0);
  return 0;
}
