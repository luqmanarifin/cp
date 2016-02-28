#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int t[N], p[N], s[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", p + i);
    t[p[i]] = i;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", s + i);
  }
  int ans = 0;
  vector<pair<int, int>> sw;
  while(1) {
    bool ada = 0;
    int mini = 1e9, at = -1;
    for(int i = n; i >= 1; i--) {
      if(t[s[i]] != i) {
        ada = 1;
        if(abs(t[s[i]] - i) < mini) {
          mini = abs(t[s[i]] - i);
          at = i;
        }
      }
    }
    if(!ada) break;
    ans += abs(t[s[at]] - at);
    sw.emplace_back(t[s[at]], at);
    int a = s[at], b = p[at];
    swap(p[at], p[t[s[at]]]);
    swap(t[a], t[b]);
  }
  printf("%d\n%d\n", ans, sw.size());
  for(auto it : sw) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
