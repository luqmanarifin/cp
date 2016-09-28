#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> p;
int r[N], c1[N], c2[N];
set<pair<int, int>> s[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d %d", r + i, c1 + i, c2 + i);
    c2[i]++;
    p.push_back(r[i]);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  for (int t = 0; t < k; t++) {
    int i = lower_bound(p.begin(), p.end(), r[t]) - p.begin();
    int b = c1[t];
    int e = c2[t];
    vector<pair<int, int>> rem;
    auto it = s[i].lower_bound({b, -1});
    if (it != s[i].begin()) it--;
    while (it != s[i].end()) {
      if (it->second < b) {
        it++;
        continue;
      }
      if (e < it->first) break;
      b = min(b, it->first);
      e = max(e, it->second);
      rem.push_back(*it);
      it++;
    }
    for (auto it : rem) s[i].erase(it);
    s[i].insert({b, e});
  }
  long long ans = 1LL * (n - p.size()) * m;
  for (int i = 0; i < p.size(); i++) {
    long long cur = m;
    for (auto it : s[i]) {
      cur -= it.second - it.first;
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}