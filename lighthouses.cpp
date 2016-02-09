#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 10;
const string str[] = {"NE", "SE", "SW", "NW"};

pair<int, int> a[N];
int k[N], z[N];
vector<int> num[N << 2];
tuple<int, int, int> c[N];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if(l == r) {
    num[p][0] = a[l].second;
    return;
  }
  build(p + p, l, (l + r) / 2);
  build(p + p + 1, (l + r) / 2 + 1, r);
  merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
}

int find(int p, int l, int r, int ll, int rr, int d, int u) {
  if(a[r].first < ll || rr < a[l].first) return 0;
  if(ll <= a[l].first && a[r].first <= rr) return upper_bound(num[p].begin(), num[p].end(), u) - lower_bound(num[p].begin(), num[p].end(), d);
  return find(p+p, l, (l+r)/2, ll, rr, d, u) + find(p+p+1, (l+r)/2+1, r, ll, rr, d, u);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int p, q;
      scanf("%d %d", &p, &q);
      c[i] = make_tuple(p, q, i);
    }
    sort(c, c + n);
    for(int i = 0; i < n; i++) {
      tie(a[i].first, a[i].second, z[i]) = c[i];
    }
    build(1, 0, n - 1);
    int mx = 0, at = -1, d = -1, cur;
    for(int i = 0; i < n; i++) {
      cur = find(1, 0, n - 1, a[i].first, inf, a[i].second, inf);
      if(cur > mx) {
        mx = cur, at = i, d = 0;
      }
      cur = find(1, 0, n - 1, a[i].first, inf, -inf, a[i].second);
      if(cur > mx) {
        mx = cur, at = i, d = 1;
      }
      cur = find(1, 0, n - 1, -inf, a[i].first, -inf, a[i].second);
      if(cur > mx) {
        mx = cur, at = i, d = 2; 
      }
      cur = find(1, 0, n - 1, -inf, a[i].first, a[i].second, inf);
      if(cur > mx) {
        mx = cur, at = i, d = 3;
      }
    }
    if(mx == n) {
      puts("1");
      printf("%d %s\n", z[at] + 1, str[d].c_str());
      continue;
    }
    vector<pair<int, int>> temp;
    int x = a[at].first, y = a[at].second;
    for(int i = 0; i < n; i++) {
      int px = a[i].first;
      int py = a[i].second;
      if(d == 0) {
        if(!(x <= px && y <= py)) k[temp.size()] = i, temp.push_back(a[i]);
      } else if(d == 1) {
        if(!(x <= px && py <= y)) k[temp.size()] = i, temp.push_back(a[i]);
      } else if(d == 2) {
        if(!(px <= x && py <= y)) k[temp.size()] = i, temp.push_back(a[i]);
      } else {
        if(!(px <= x && y <= py)) k[temp.size()] = i, temp.push_back(a[i]);
      }
    }
    int m = temp.size();
    //assert(m + mx == n);
    for(int i = 0; i < m; i++) a[i] = temp[i];
    build(1, 0, m - 1);
    int mx2 = 0, at2 = -1, d2 = -1;
    for(int i = 0; i < m; i++) {
      cur = find(1, 0, m - 1, a[i].first, inf, a[i].second, inf);
      if(cur > mx2) {
        mx2 = cur, at2 = i, d2 = 0;
      }
      cur = find(1, 0, m - 1, a[i].first, inf, -inf, a[i].second);
      if(cur > mx2) {
        mx2 = cur, at2 = i, d2 = 1;
      }
      cur = find(1, 0, m - 1, -inf, a[i].first, -inf, a[i].second);
      if(cur > mx2) {
        mx2 = cur, at2 = i, d2 = 2; 
      }
      cur = find(1, 0, m - 1, -inf, a[i].first, a[i].second, inf);
      if(cur > mx2) {
        mx2 = cur, at2 = i, d2 = 3;
      }
    }
    //assert(mx2 == m);
    puts("2");
    printf("%d %s\n", z[at] + 1, str[d].c_str());
    printf("%d %s\n", z[k[at2]] + 1, str[d2].c_str());
  }
  
  return 0;
}
