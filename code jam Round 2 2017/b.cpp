#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

// di mana - siapa
multiset<pair<int, int>> s;
vector<int> a[N];
int rides;
int n, m, c;
bool done[N][N], rode[N];

int get_ride() {
  for (int round = 0; ; round++) {
    if (s.empty()) return round;
    // tempat di mana, siapa
    memset(rode, 0, sizeof(rode));
    
    int now = 0;
    auto it = s.lower_bound(make_pair(now, N));
    while (it != s.end()) {
      while (it != s.end() && rode[it->second]) it++;
      if (it == s.end()) break;
      
      s.erase(it);
      rode[it->second] = 1;
      now++;
      it = s.lower_bound(make_pair(now, N));
    }
  }
  assert(0);
}

int get_promo() {
  memset(done, 0, sizeof(done));
  vector<int> up;
  for (int i = 1; i <= c; i++) {
    for (auto it : a[i]) {
      up.emplace_back(it);
    }
  }
  sort(up.begin(), up.end());
  int ret = 0;
  for (int i = 0; i < up.size(); i++) {
    if (done[i % rides][up[i]]) ret++;
    done[i % rides][up[i]] = 1;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    s.clear();
    for (int i = 0; i < N; i++) {
      a[i].clear();
    }
    
    scanf("%d %d %d", &n, &c, &m);
    for (int i = 0; i < m; i++) {
      int p, b;
      scanf("%d %d", &p, &b);
      s.insert(make_pair(p, b));
      a[b].push_back(p);
    }
    rides = get_ride();
    int promo = get_promo();
    printf("Case #%d: %d %d\n", tt, rides, promo);
  }
  return 0;
}
