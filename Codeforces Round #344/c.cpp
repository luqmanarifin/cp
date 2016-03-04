#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], t[N], r[N], to[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d %d", t + i, r + i);
  }
  to[m - 1] = m - 1;
  for(int i = m - 2; i >= 0; i--) {
    if(r[i] > r[to[i + 1]]) {
      to[i] = i;
    } else {
      to[i] = to[i + 1];
    }
  }
  vector<int> p;
  for(int i = 0; i < m; i = to[i] + 1) {
    p.push_back(to[i]);
  }
  multiset<int> s;
  for(int i = 0; i < r[p[0]]; i++) {
    s.insert(a[i]);
  }
  //printf("jing "); for(auto it : p) printf("%d ", it); printf("\n");
  int now = r[p[0]] - 1;
  for(int i = 1; i < p.size(); i++) {
    while(r[p[i]] - 1 < now) {
      if(t[p[i - 1]] == 1) {
        auto it = s.end();
        it--;
        a[now--] = *it;
        s.erase(it);
      } else {
        auto it = s.begin();
        a[now--] = *it;
        s.erase(it);
      }
    }
  }
  while(now >= 0) {
    if(t[p.back()] == 1) {
      auto it = s.end();
      it--;
      a[now--] = *it;
      s.erase(it);
    } else {
      auto it = s.begin();
      a[now--] = *it;
      s.erase(it);
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
