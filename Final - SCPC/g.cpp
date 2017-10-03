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

const int N = 1e5 + 5;

int a[N];
long long s[N];

long long bit[N];
vector<pair<int, int>> que[N];
vector<pair<int, long long>> gain[N];
long long ans[N];

long long sum(int l, int r) {
  return s[r] - s[l-1];
}

void upd(int i, long long v) {
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    bit[i] = max(bit[i], v);
  }
}

long long find(int i) {
  long long ret = 0;
  for (; i < N; i |= i + 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      que[i].clear();
      gain[i].clear();
    }
    memset(bit, 0, sizeof(bit));
    
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= q; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      que[r].emplace_back(l, i);
    }
    stack<pair<int, int>> s;
    set<pair<int, int>> seg;
    for (int i = 1; i <= n; i++) {
      while (!s.empty() && s.top().first < a[i]) s.pop();
      if (!s.empty()) {
        seg.insert({s.top().second, i});
      }
      s.emplace(a[i], i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; i--) {
      while (!s.empty() && s.top().first < a[i]) s.pop();
      if (!s.empty()) {
        seg.insert({i, s.top().second});
      }
      s.emplace(a[i], i);
    }
    for (auto it : seg) {
      int l = it.first;
      int r = it.second;
      if (r - l > k) continue;
      long long got = 0;
      if (a[l] < a[r]) {
        got = 1LL * a[r] * k + sum(l, r - 1) + 1LL * a[l] * (k - r + l);
      } else {
        got = 1LL * a[l] * k + sum(l + 1, r) + 1LL * a[r] * (k - r + l);
      }
      gain[r].emplace_back(l, got);
    }
    for (int i = 1; i <= n; i++) {
      for (auto it : gain[i]) upd(it.first, it.second);
      for (auto it : que[i]) ans[it.second] = find(it.first);
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  }

  return 0;
}
