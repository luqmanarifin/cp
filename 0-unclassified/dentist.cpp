#include <bits/stdc++.h>

using namespace std;

const int N = 4005;

long long v[N], d[N], p[N];
int l[N], r[N];

void del(int at) {
  r[l[at]] = r[at];
  l[r[at]] = l[at];
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d %I64d %I64d", v + i, d + i, p + i);
    l[i] = i - 1;
    r[i] = i + 1;
  }
  r[0] = 1;
  vector<int> ans;
  for(int i = 1; i <= n; i = r[i]) {
    ans.push_back(i);
    for(int j = 0, at = r[i]; at <= n; at = r[at], j++) {
      p[at] -= max(v[i] - j, 0LL);
    }
    for(int at = r[i]; at <= n; at = r[at]) {
      if(p[at] < 0) {
        del(at);
        for(int k = r[at]; k <= n; k = r[k]) {
          p[k] -= d[at];
        }
      }
    }
  }
  printf("%d\n", ans.size());
  for(auto it : ans) {
    printf("%d ", it);
  }
  
  return 0;
}
