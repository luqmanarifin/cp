/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it:
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
Surely, just as we were that day... like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy...
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light;
Even if you never change... even if you happen to change... you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people;
At that time, I hope we can bring along our irreplaceable families and meet here again...

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light...
We run through the passing seasons, seeing each of our many tomorrows;
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int par[N], a[N];
long long sum[N], cnt[N];
vector<int> edge[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  par[u] = v;
  sum[v] += sum[u];
  cnt[v] += cnt[u];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<pair<int, int>> all;
  for (int i = 1; i <= n; i++) {
    all.emplace_back(a[i], i);
    par[i] = -1;
    sum[i] = a[i];
    cnt[i] = 1;
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  long long ans = 0;
  for (auto i : all) {
    int now = i.second;
    par[now] = now;
    long long root_sum = sum[find(now)];
    long long root_cnt = cnt[find(now)];
    long long tot_sum = root_sum;
    long long tot_cnt = root_cnt;
    vector<pair<long long, long long>> wew;
    wew.emplace_back(root_sum, root_cnt);
    for (auto it : edge[now]) {
      if (par[it] == -1) continue;
      if (find(it) != find(now)) {
        long long ss = sum[find(it)];
        long long cc = cnt[find(it)];
        wew.emplace_back(ss, cc);
        tot_sum += ss;
        tot_cnt += cc;
      }
    }
    long long add = 0;
    for (auto it : wew) {
      long long ss = it.first;
      long long cc = it.second;
      add += (ss - i.first * cc) * (tot_cnt - cc);
    }
    add += (tot_sum-root_sum - i.first * (tot_cnt-root_cnt)) * root_cnt;
    ans += add;
    //printf("%lld\n", add);
    for (auto it : edge[now]) if (par[it] != -1) merge(now, it);
  }
  cout << ans << endl;
  return 0;
}
