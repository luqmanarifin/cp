#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 1e9;

// [hadiah] cost
int a[N], ori[N];
int p, q;
int dp[N], b[N];
int cnt;

vector<pair<int, int>> edges; 

void draw(int id) {
  if(q == 2) {
    int n = id;
    int root = ++cnt;
    for(int i = 0; i < n; i++) {
      int now = ++cnt;
      edges.emplace_back(root, now);
    }
  } else {
    int n = id / N;
    int m = id % N;
    int ra = cnt + 1;
    int rb = cnt + q - 1;
    for(int i = ra; i < rb; i++) {
      edges.emplace_back(i, i + 1);
    }
    cnt = rb;
    for(int i = 0; i < n; i++) {
      int now = ++cnt;
      edges.emplace_back(now, ra);
    }
    for(int i = 0; i < m; i++) {
      int now = ++cnt;
      edges.emplace_back(now, rb);
    }
  }
}

int c(int n, int k) {
  int ret = 1;
  k = min(k, n - k);
  for(int i = 0; i < k; i++) {
    ret = ret * (n - i) / (i + 1);
  }
  return ret;
}

int main() {
  fill(a, a + N, inf);
  fill(dp, dp + N, inf);
  scanf("%d %d", &p, &q);
  if(q == 2) {
    for(int i = 3; i + 1 < N; i++) {
      int got = c(i, 3);
      int cost = i + 1;
      if(got > N) break;
      if(cost < a[got]) {
        a[got] = cost;
        ori[got] = i;
      }
    }
  } else {
    for(int i = 1; i < N; i++) {
      for(int j = 1; j < N; j++) {
        if(i + j < 3) continue;
        long long got = 1LL * i * j * (i + j - 2) / 2;
        int cost = i + j + q - 1;
        if(got > N) break;
        if(cost < a[got]) {
          a[got] = cost;
          ori[got] = i * N + j;
        }
      }
    }
  }
  //puts("precompute");
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 1; i + j < N; j++) {
      int ncos = dp[i] + a[j];
      if(ncos < dp[i + j]) {
        dp[i + j] = ncos;
        b[i + j] = j;
      }
    }
  }
  assert(dp[p] <= 100);
  int got = p;
  while(got) {
    //printf("%d\n", got);
    draw(ori[b[got]]);
    got -= b[got];
  }
  assert(cnt == dp[p] && edges.size() <= 100);
  printf("%d %d\n", dp[p], edges.size());
  for(auto it : edges) printf("%d %d\n", it.first, it.second);
  return 0;
}