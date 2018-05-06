
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int MAGIC = 320;

int a[N], p[N];
long long s[N], k;

long long now;
int l, r;

vector<long long> all;
int at[N], atp[N], atm[N], cnt[N];

void add(int i, int v) {
  cnt[at[i]] += v;
}

long long ans[N];

int main() {
  int n;
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + (p[i] == 1? a[i] : -a[i]);
  }
  for (int i = 0; i <= n; i++) {
    all.push_back(s[i]);
    all.push_back(s[i] + k);
    all.push_back(s[i] - k);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i <= n; i++) {
    at[i] = lower_bound(all.begin(), all.end(), s[i]) - all.begin();
    atp[i] = lower_bound(all.begin(), all.end(), s[i] + k) - all.begin();
    atm[i] = lower_bound(all.begin(), all.end(), s[i] - k) - all.begin();
  }

  // block - r - l - id
  vector<tuple<int, int, int, int>> que;
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    que.emplace_back(u / MAGIC, v, u, i);
  }
  sort(que.begin(), que.end());
  l = r = 1;
  now = (s[1] == k);
  add(1, 1);
  for (auto it : que) {
    int u, v, id;
    tie(ignore, v, u, id) = it;
    //printf("jawab %d: %d %d\n", id, u, v);

    while (r < v) {
      add(r + 1, 1);
      now += cnt[atm[r + 1]];
      if (s[l - 1] == s[r + 1] - k) now++;
      if (s[r + 1] == s[r + 1] - k) now--;
      r++;
    }
    while (u < l) {
      add(l - 1, 1);
      now += cnt[atp[l - 2]]; 
      l--;
    }
    while (v < r) {
      now -= cnt[atm[r]];
      if (s[l - 1] == s[r] - k) now--;
      if (s[r] == s[r] - k) now++;
      add(r, -1);
      r--;
    }
    while (l < u) {
      now -= cnt[atp[l - 1]];
      add(l, -1);
      l++;
    } 
    ans[id] = now;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
