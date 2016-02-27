#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int cnt[N];
pair<long long, int> p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    scanf("%d %d", &n, &m);
    long long all = 0;
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      all += a;
      cnt[a]++;
    }
    if(all < m) {
      puts("Impossible");
      continue;
    }
    int sz = 0;
    for(int i = 0; i < N; i++) {
      if(cnt[i]) {
        p[sz++] = {1LL * cnt[i] * i, i};
      }
    }
    sort(p, p + sz);
    reverse(p, p + sz);
    vector<int> ans;
    long long now = 0;
    for(int i = 0; i < sz && now < m; i++) {
      ans.push_back(p[i].second);
      now += p[i].first;
    }
    sort(ans.begin(), ans.end());
    for(auto it : ans) printf("%d ", it); printf("\n");
  }
  return 0;
}
