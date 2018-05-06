
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

multiset<int> s[N << 2];
multiset<int>::iterator pt[N << 2];
int a[N];
vector<int> st;

void build(int p, int l, int r) {
  for (int i = l; i <= r; i++) s[p].insert(-a[i]);
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
}

void change(int p, int l, int r, int at, int bef, int val) {
  //printf("niki %d %d %d: %d %d %d\n", p, l, r, at, bef, val);
  s[p].erase(s[p].find(-bef));
  s[p].insert(-val);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (at <= mid) {
    change(p + p, l, mid, at, bef, val);
  } else {
    change(p + p + 1, mid + 1, r, at, bef, val);
  }
}

void query(int p, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    st.push_back(p);
    return;
  }
  if (r < ll || rr < l) return;
  int mid = (l + r) >> 1;
  query(p + p, l, mid, ll, rr);
  query(p + p + 1, mid + 1, r, ll, rr);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      change(1, 1, n, l, a[l], r);
      a[l] = r;
    } else {
      st.clear();
      query(1, 1, n, l, r);
      priority_queue<pair<int, int>> pq;    // value - p nya dimana
      for (auto it : st) {
        pt[it] = s[it].begin();
        pq.emplace(-(*pt[it]), it);
      }
      bool found = 0;
      vector<int> v;
      for (int i = 0; i < 2 && !pq.empty(); i++) {
        v.push_back(pq.top().first);
        int it = pq.top().second;
        pq.pop();
        pt[it]++;
        if (pt[it] != s[it].end()) {
          pq.emplace(-(*pt[it]), it);
        }
      }
      while (!pq.empty() && !found) {
        v.push_back(pq.top().first);
        
        int sz = v.size();
        if (v[sz-3] < v[sz-2] + v[sz-1]) {
          found = 1;
          printf("%lld\n", (long long) v[sz-2] + v[sz-1] + v[sz-3]);
          break;
        }
        
        int it = pq.top().second;
        pq.pop();
        pt[it]++;
        if (pt[it] != s[it].end()) {
          pq.emplace(-(*pt[it]), it);
        }
      }
      if (!found) puts("0");
    }
  }

  return 0;
}
