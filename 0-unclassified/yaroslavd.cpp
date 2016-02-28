#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> num[N << 2];
vector<int> to[N];
int p[N];

void build(int p, int l, int r) {
  if(l == r) {
    num[p] = to[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p].resize(num[p + p].size() + num[p + p + 1].size());
  merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
}

int find(int p, int l, int r, int ll, int rr, int val) {
  if(r < ll || rr < l) return 0;
  if(ll <= l && r <= rr) return upper_bound(num[p].begin(), num[p].end(), val) - num[p].begin();
  int mid = (l + r) >> 1;
  return find(p + p, l, mid, ll, rr, val) + find(p + p + 1, mid + 1, r, ll, rr, val);
}

int main() {
  int n, m, a;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a);
    p[a] = i;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j += i) {
      to[min(p[i], p[j])].push_back(max(p[i], p[j]));
    }
  }
  for(int i = 1; i <= n; i++) {
    sort(to[i].begin(), to[i].end());
  }
  build(1, 1, n);
  //puts("kontil");
  while(m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", find(1, 1, n, l, r, r));
  }
  
  return 0;
}
