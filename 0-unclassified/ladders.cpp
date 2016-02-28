#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7;

vector<int> num[N << 2];
pair<int, int> a[N];
vector<int> pos;

int id(int v) {
  return lower_bound(pos.begin(), pos.end(), v) - pos.begin();
}

void build(int p, int l, int r) {
  num[p].assign(r - l + 1, 0);
  if(l == r) {
    num[p][0] = a[l].second;
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
}

bool ada(int p, int l, int r, int ll, int rr, int val) {
  if(r < ll || rr < l) return 0;
  if(ll <= l && r <= rr) return (upper_bound(num[p].begin(), num[p].end(), val) - num[p].begin()) < num[p].size();
  int mid = (l + r) >> 1;
  return ada(p + p, l, mid, ll, rr, val) || ada(p + p + 1, mid + 1, r, ll, rr, val);
}

bool cmp(pair<int, int> l, pair<int, int> r) {
  if(l.second != r.second) return l.second < r.second;
  return l.first < r.first;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    pos.clear();
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &a[i].first, &a[i].second);
      pos.push_back(a[i].first);
    }
    sort(a, a + n);
    sort(pos.begin(), pos.end());
    build(1, 0, n - 1);
    
    sort(a, a + n, cmp);
    long long ans = 0;
    for(int i = 0; i < n; ) {
      int j = i + 1;
      while(j < n && a[j].second == a[j - 1].second) j++;
      int k = i;
      while(k < j) {
        int l = k + 1;
        while(l < j && !ada(1, 0, n - 1, id(a[l-1].first), id(a[l].first), a[l].second)) l++;
        for(int it = k; it < l; it++) {
          for(int jt = it + 1; jt < l; jt++) {
            long long now = a[jt].first - a[it].first;
            ans = (ans + now * now) % mod;
          }
        }
        k = l;
      }
      i = j;
    }
    printf("Case #%d: %I64d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
