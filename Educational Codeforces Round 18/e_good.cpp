#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N], n;
vector<int> seg[N];
vector<pair<int, int>> segs[N]; 

vector<int> all, dp;

int get(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

void solve(int k) {
  //cout << k << endl;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long l = 1, r = 1e9;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if ((k + 1) * mid < a[i]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    ans += l;
  }
  cout << ans << endl;
}

vector<pair<int, int>> overlap(vector<pair<int, int>> l, vector<pair<int, int>> r) {
  int i = 0, j = 0;
  vector<pair<int, int>> ret;
  while (i < l.size() && j < r.size()) {
    if (l[i].second < r[j].first) {
      i++;
      continue;
    }
    if (r[j].second < l[i].first) {
      j++;
      continue;
    }
    int beg = max(l[i].first, r[j].first);
    int end = min(l[i].second, r[j].second);
    ret.emplace_back(beg, end);
    if (l[i].second < r[j].second) {
      i++;
    } else {
      j++;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        seg[i].push_back(a[i] / j);
        seg[i].push_back(a[i] / j - 1);
      } else {
        seg[i].push_back(a[i] / j);
      }
    }
    sort(seg[i].begin(), seg[i].end());
    seg[i].resize(distance(seg[i].begin(), unique(seg[i].begin(), seg[i].end())));
    segs[i].emplace_back(0, seg[i][0]);
    for (int j = 1; j < seg[i].size(); j++) {
      segs[i].emplace_back(seg[i][j], seg[i][j]);
    }
    //for (auto it : segs[i]) printf("%d %d  ", it.first, it.second); printf("\n");
  }
  //puts("");
  vector<pair<int, int>> now = segs[0];
  for (int i = 1; i < n; i++) {
    //for (auto it : now) printf("%d %d  ", it.first, it.second); printf("\n");
    now = overlap(now, segs[i]);
  }
  //for (auto it : now) printf("%d %d  ", it.first, it.second); printf("\n");
  solve(now.back().second);
  return 0;
}
