#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int d[N], b[N];

int main() {
  fill(d, d + N, N);
  d[0] = 0;
  int best = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 1; i + j*(j + 1)/2 < N; j++) {
      int to = i + j*(j + 1)/2;
      if(d[i] + 1 < d[to]) {
        d[to] = d[i] + 1;
        b[to] = j;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int c = 0;
    while(n) {
      int kali = b[n] * (b[n] + 1) / 2;
      for(int i = 0; i < b[n]; i++) printf("%c", c + 'a');
      n -= kali;
      c++;
    }
    printf("\n");
  }
  return 0;
}