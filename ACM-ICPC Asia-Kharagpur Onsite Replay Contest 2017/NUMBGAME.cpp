#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1005;

char s[N];
int pw[N], pre[N], suf[N];

int cnt[M];
vector<int> edge[M];
bool vis[M];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < M; i++) edge[i].clear();
    
    int mod;
    scanf("%s %d", s, &mod);
    int n = strlen(s);
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i-1] * 10 % mod;
    for (int i = 0; i < n; i++) {
      pre[i] = s[i] - '0';
      if (i) {
        pre[i] += pre[i - 1] * 10;
        pre[i] %= mod;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = (s[i] - '0') * pw[n - i - 1] % mod;
      if (i + 1 < n) {
        suf[i] += suf[i + 1];
        suf[i] %= mod;
      }
    }
    for (int i = 0; i < n; i++) {
      int now = (i? pre[i-1] : 0);
      if (i + 1 < n) {
        now = (now * pw[n - i - 1] + suf[i + 1]) % mod;  
      }
      cnt[now]++;
    }
    vector<int> num;
    for (int i = 0; i < mod; i++) if (cnt[i]) num.push_back(i);
    for (int i = 0; i < mod; i++) {
      int now = i * pw[n - 1] % mod;
      for (auto it : num) {
        int to = (now + it) % mod;
        edge[to].push_back(i);
      }
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto it : edge[now]) {
        if (!vis[it]) {
          vis[it] = 1;
          q.push(it);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < mod; i++) if (vis[i]) ans += cnt[i];
    printf("%d\n", ans);
  }

  return 0;
}
