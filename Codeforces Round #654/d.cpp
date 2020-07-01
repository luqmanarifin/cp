#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int a[N][N];

void reset(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
}

int sq(int x) {
  return x * x;
}

int compute(int n) {
  int maxr = -1, minr = n + 1;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) sum += a[i][j];
    maxr = max(maxr, sum);
    minr = min(minr, sum);
  }
  int maxc = -1, minc = n + 1;
  for (int j = 0; j < n; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i][j];
    maxc = max(maxc, sum);
    minc = min(minc, sum);
  }
  return sq(maxr - minr) + sq(maxc - minc);
}

void solve(int n, int k) {
  for (int start = 0; start < n; start++) {
    int i = 0, j = start;
    for (int x = 0; x < n; x++) {
      int p = (i + x) % n;
      int q = (j + x) % n;
      if (k > 0) {
        a[p][q] = 1;
        k--;
      }    
    }
  }
  printf("%d\n", compute(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  reset(n);
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    solve(n, k);
  }

  return 0;
}
