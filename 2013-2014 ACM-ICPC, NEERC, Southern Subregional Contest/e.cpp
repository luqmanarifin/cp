#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int sum[N];
void upds(int x, int v) {
  for (; x < N; x += x&-x)
    sum[x] += v;
}

int gets(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret += sum[x];
  return ret;
}

int mi[N];

void updm(int x, int v) {
  for(; x < N; x += x&-x)
    mi[x] = min(mi[x], v);
}

int getm(int x) {
  int ret = N;
  for (; x; x -= x&-x)
    ret = min(ret, mi[x]);
  return ret;
}

int inv[N], a[N], p[N];
long long add[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", p+i);
  }
  long long ans = 0;
  for (int i = n; i > 0; --i) {
    inv[i] = gets(a[i]-1);
    upds(a[i], +1);
    ans += inv[i];
  }
  fill(mi, mi+N, N);
  vector<pair<int, int> > vp;
  vector<pair<int, int> > va;
  for (int i = 1; i <= n; i++)
    va.emplace_back(-a[i], i);
  for (int i = 1; i <= m; i++)
    vp.emplace_back(-a[p[i]], i);
  sort(va.begin(), va.end());
  sort(vp.begin(), vp.end());
  for (int i = 0, j = 0; i < va.size(); i++) {
    while (j < vp.size() && vp[j].first <= va[i].first) {
      updm(p[vp[j].second], vp[j].second), j++;
    }
    int id = getm(va[i].second);
    if (id < N) {
      add[id] -= inv[va[i].second];
    }
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= m; i++) {
    ans += add[i];
    printf("%I64d\n", ans);
  }
  return 0;
}
