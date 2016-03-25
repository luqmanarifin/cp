#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct cok {
  int first;
  int second;
  int id;
};

cok a[N];
vector<int> num[N << 2];
int ans[N];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if(l == r) {
    num[p][0] = a[l].second;
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
}

int find(int p, int l, int r, int u, int v) {
  if(u <= a[l].first && a[r].first <= v) return upper_bound(num[p].begin(), num[p].end(), v) - lower_bound(num[p].begin(), num[p].end(), u);
  if(v < a[l].first || a[r].first < u) return 0;
  int mid = (l + r) >> 1;
  return find(p + p, l, mid, u, v) + find(p + p + 1, mid + 1, r, u, v);
}

bool cmp(cok l, cok r) {
  if(l.first != r.first) return l.first < r.first;
  return l.second < r.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    a[i].id = i;
  }
  sort(a, a + n, cmp);
  build(1, 0, n - 1);
  for(int i = 0; i < n; i++) {
    ans[a[i].id] = find(1, 0, n - 1, a[i].first + 1, a[i].second - 1);
  }
  for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
