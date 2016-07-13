#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 2e9;

map<int, vector<int>> p;
int a[N];
set<pair<int, int>> s;
long long now;

void remove(int v) {
  auto it = s.lower_bound(make_pair(v, inf));
  if(it != s.begin()) {
    it--;
    int l = it->first;
    int r = it->second;
    if(l <= v && v <= r) {
      s.erase(it);
      int cnt = r - l + 1;
      now -= cnt * (cnt + 1) / 2;
      if(l <= v - 1) {
        s.insert(make_pair(l, v - 1));
        cnt = v - l;
        now += cnt * (cnt + 1) / 2;
      }
      if(v + 1 <= r) {
        s.insert(make_pair(v + 1, r));
        cnt = r - v;
        now += cnt * (cnt + 1) / 2;
      }
    }
  }
}

void insert(int l, int r) {
  s.insert(make_pair(l, r));
  int cnt = r - l + 1;
  now += cnt * (cnt + 1) / 2;
}

void clear() {
  s.clear();
  now = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    p.clear();

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
      p[a[i]].push_back(i);
    }
    long long ans = 0;
    for(int i = 0; i + 1 < n; i++) {
      set<int> done;
      clear();

      insert(i, n - 1);
      for(int j = i; j + 1 < n; j++) {
        remove(j);
        if(!done.count(a[j])) {
          done.insert(a[j]);
          for(auto it : p[a[j]]) remove(it);
        }
        ans += now;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
