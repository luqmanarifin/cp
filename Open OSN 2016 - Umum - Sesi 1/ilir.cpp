#include <bits/stdc++.h>

using namespace std;

bool a[40][40];
int n, m;

long long v[40][40];
vector<long long> all;
char junk[22];

void dfs(int i, int j, long long now) {
  if(i < 1 || n < i || j < 1 || m < j || a[i][j]) return;
  if(i == n && j == m) {
    all.push_back(now + v[i][j]);
    return;
  }
  a[i][j] = 1;
  dfs(i + 1, j, now + v[i][j]);
  dfs(i - 1, j, now + v[i][j]);
  dfs(i, j + 1, now + v[i][j]);
  dfs(i, j - 1, now + v[i][j]);
  a[i][j] = 0;
}

int main() {
  scanf("%s %d %d", junk, &n, &m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%lld", &v[i][j]);
    }
  }
  dfs(1, 1, 0);
  sort(all.begin(), all.end());
  int k;
  scanf("%d", &k);
  while(k--) {
    long long p, q;
    scanf("%lld %lld", &p, &q);
    printf("%d\n", upper_bound(all.begin(), all.end(), q) - lower_bound(all.begin(), all.end(), p));
  }
  return 0;
}