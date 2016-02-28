#include <bits/stdc++.h>

using namespace std;

const int N = 6e6 + 6;

bool done[N];
vector<int> p, q;

int main() {
  int a = 2, b = 3, n, m;
  scanf("%d %d", &n, &m);
  int now = 2;
  for(int i = 0; i < n; i++) {
    while(now % 6 == 0) now += 2;
    p.push_back(now);
    now += 2;
  }
  now = 3;
  for(int i = 0; i < m; i++) {
    while(now % 6 == 0) now += 3;
    q.push_back(now);
    now += 3;
  }
  int ans = 0;
  for(int i = 6; ; i += 6) {
    bool masih = 0;
    if(p.size() && i < p.back()) masih = 1;
    if(q.size() && i < q.back()) masih = 1;
    if(!masih) break;
    ans = max(ans, i);
    if(p.size() && q.size()) {
      int p_lost = max((p.size() >= 2? p[p.size() - 2] : 0), q.back());
      int q_lost = max((q.size() >= 2? q[q.size() - 2] : 0), p.back());
      if(p_lost < q_lost) {
        p.pop_back();
      } else {
        q.pop_back();
      }
    } else if(p.size()) {
      p.pop_back();
    } else if(q.size()) {
      q.pop_back();
    } else {
      break;
    }
  }
  if(p.size()) ans = max(ans, p.back());
  if(q.size()) ans = max(ans, q.back());
  cout << ans << endl;
  return 0;
}
