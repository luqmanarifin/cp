#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

#define int long long

long long bit[N];
int n, m, t[N], ada[N];
int ans[N];
vector<int> pos[N];

void add(int at, long long val) {
  for(; at <= m; at |= at + 1) {
    ada[at]++;
    bit[at] += val;
  }
}

void substr(int at, long long val) {
  for(; at <= m; at |= at + 1) {
    ada[at]--;
    bit[at] -= val;
  }
}

int count(int at) {
  int ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += ada[at];
  }
  return ret;
}

long long find(int at) {
  long long ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += bit[at];
  }
  return ret;
}

main() {
  scanf("%I64d %I64d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%I64d", t + i);
    add(i, t[i]);
    pos[t[i]].push_back(i);
  }
  
  vector<tuple<int, int, int>> q;
  for(int i = 0; i < n; i++) {
    int d, r;
    scanf("%I64d %I64d", &d, &r);
    q.emplace_back(d, r, i);
  }
  
  sort(q.begin(), q.end());
  int now = 0;
  for(auto it : q) {
    int d, res, id;
    tie(d, res, id) = it;
    
    // removing yg udah ga pantes
    while(now < d) {
      for(auto p : pos[now]) {
        substr(p, now);
      }
      now++;
    }
    
    int l = 0, r = m;
    while(l < r) {
      int mid = (l + r) >> 1;
      long long ada = find(mid) - 1LL * count(mid) * d;
      if(ada < res) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    ans[id] = l;
  }
  for(int i = 0; i < n; i++) {
    if(ans[i] == m) {
      ans[i] = -1;
    }
    printf("%I64d ", ans[i] + 1);
  }
  printf("\n");
  return 0;
}
