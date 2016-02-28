#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N];
int ans[N];
vector<int> from[N];
vector<pair<int, int>> q[N]; 
int p[N], n;

void add(int i) {
  for(; i <= n; i |= i + 1) {
    bit[i]++;
  }
}

int find(int i) {
  int ret = 0;
  for(; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    p[a] = i;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j += i) {
      from[max(p[i], p[j])].push_back(min(p[i], p[j]));
    }
  }
  for(int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    q[r].emplace_back(l, i);
  }
  for(int i = 1; i <= n; i++) {
    for(auto it : from[i]) {
      add(it);
    }
    for(auto it : q[i]) {
      ans[it.second] = find(i) - find(it.first - 1);
    }
  }
  for(int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
