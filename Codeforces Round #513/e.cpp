#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct item {
  item() {
    sum0 = sum1 = cnt0 = cnt1 = 0;
  }
  item(long long sum0, long long sum1, int cnt0, int cnt1) {
    this->sum0 = sum0;
    this->sum1 = sum1;
    this->cnt0 = cnt0;
    this->cnt1 = cnt1;
  }
  long long sum0, sum1;
  int cnt0, cnt1;
};

item inc(item a) {
  swap(a.cnt0, a.cnt1);
  swap(a.sum0, a.sum1);
  a.sum1 += a.cnt1;
  return a;
}

item add(item l, item r) {
  item ret;
  ret.sum0 = l.sum0 + r.sum0;
  ret.sum1 = l.sum1 + r.sum1;
  ret.cnt0 = l.cnt0 + r.cnt0;
  ret.cnt1 = l.cnt1 + r.cnt1;
  return ret;
}

item sub(item l, item r) {
  item ret;
  ret.sum0 = l.sum0 - r.sum0;
  ret.sum1 = l.sum1 - r.sum1;
  ret.cnt0 = l.cnt0 - r.cnt0;
  ret.cnt1 = l.cnt1 - r.cnt1;
  return ret;
}

vector<int> edge[N];
item a[N], b[N];

void dfs(int now, int bef) {
  a[now] = item(0, 0, 1, 0);
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    item c = a[it];
    c = inc(c);
    a[now] = add(a[now], c);
  }
}

long long ans;

void solve(int now, int bef) {
  long long cur = 0;
  cur += a[now].sum0 + a[now].sum1;
  if (bef != 0) {
    item c = inc(b[bef]);
    cur += c.sum0 + c.sum1;
  }
  //printf("from %d add %lld\n", now, cur);
  ans += cur;
  b[now] = add(a[now], inc(b[bef]));
  for (auto it : edge[now]) {
    if (it == bef) continue;
    b[now] = sub(b[now], inc(a[it]));
    solve(it, now);
    b[now] = add(b[now], inc(a[it]));
  }  
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  solve(1, 0);
  
  for (int i = 1; i <= n; i++) {
    //printf("%d: %lld %lld %d %d\n", i, a[i].sum0, a[i].sum1, a[i].cnt0, a[i].cnt1);
  }
  
  cout << ans / 2 << endl;
  return 0;
}
