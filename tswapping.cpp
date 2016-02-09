#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000002013LL;

int from[1005], to[1005], p[1005];
long long give[2005];
long long take[2005];

vector<int> pos;
int n, m;

int id(int num) {
  return lower_bound(pos.begin(), pos.end(), num) - pos.begin();
}

long long get(int i) {
  return (1LL * (2 * n - i + 1) * i / 2) % mod;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    pos.clear();
    memset(give, 0, sizeof(give));
    memset(take, 0, sizeof(take));
    
    scanf("%d %d", &n, &m);
    long long asli = 0;
    for(int i = 0; i < m; i++) {
      scanf("%d %d %d", from + i, to + i, p + i);
      pos.push_back(from[i]);
      pos.push_back(to[i]);
      asli += get(to[i] - from[i]) * p[i];
      asli %= mod;
    }
    sort(pos.begin(), pos.end());
    pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
    
    for(int i = 0; i < m; i++) {
      give[id(from[i])] += p[i];
      take[id(to[i])] += p[i];
    }
    priority_queue<pair<long long, long long>> pq;
    long long cur = 0;
    for(int i = 0; i < pos.size(); i++) {
      pq.emplace(i, give[i]);
      while(take[i] && !pq.empty()) {
        long long del = min(take[i], pq.top().second);
        int now = pq.top().first;
        take[i] -= del;
        cur += get(pos[i] - pos[now]) * del;
        //printf("debug %d %d %I64d\n", pos[now], pos[i], del);
        cur %= mod;
        int sisa = pq.top().second - del;
        pq.pop();
        if(sisa) {
          pq.emplace(now, sisa);
        }
      }
    }
    //printf("asli : %I64d cur : %I64d\n", asli, cur);
    long long ans = asli - cur;
    ans %= mod; if(ans < 0) ans += mod;
    printf("Case #%d: %I64d\n", tt, ans);
  }
  
  return 0;
}
