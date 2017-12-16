/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int bit[N];

void add(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int find(int l, int r) {
  return find(r) - find(l - 1);
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    s.insert(v);
    add(v, 1);
  }
  int til = 1e6, ans = 0;
  for (int i = 1; i + m - 1 <= til; i++) {
    int ada = find(i, i + m - 1);
    if (ada >= k) {
      int del = ada - k + 1;
      while (del--) {
        auto it = s.lower_bound(i + m);
        it--;
        add(*it, -1);
        s.erase(it);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
