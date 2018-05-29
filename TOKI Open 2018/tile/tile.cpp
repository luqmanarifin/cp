#include "tile.h"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 3e5 + 5;

int to[N][20];
int m;
vector<int> a;

void init(int N, int K, int Q, int M, std::vector<int> A) {
  m = A.size();
  a = A;
  
  for (int i = 0; i < M; i++) {
    int p = lower_bound(A.begin(), A.end(), A[i] + K) - A.begin();
    to[i][0] = p;
    //printf("%d maju %d mundur %d\n", i, to[i][0], b[i]);
  }
  for (int j = 0; j < 20; j++) to[M][j] = M;
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < M; i++) {
      to[i][j] = to[to[i][j-1]][j-1];
    }
  }
}

int getNumberOfSpecialTiles(int L, int R) {
  int sta = lower_bound(a.begin(), a.end(), L) - a.begin();
  int til = upper_bound(a.begin(), a.end(), R) - a.begin();
  int l = 0, r = a.size();
  while (l < r) {
    int mid = (l + r) >> 1;
    int now = sta;
    for (int i = (__builtin_clz(mid) ^ 31); i >= 0; i--) {
      if (mid & (1 << i)) {
        now = to[now][i];
      }
      if (now >= til) break;
    }
    if (now < til) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
