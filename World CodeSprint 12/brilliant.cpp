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

const int N = 2e5 + 5;

struct Fenwick {
  Fenwick() {}
  Fenwick(int n) : n(n) {
    num.assign(n, 0);
  }
  void add(int i, int val) {
    for (; i >= 0; i = (i & (i + 1)) - 1) num[i] += val;
  }
  int find(int i) {
    int ret = 0;
    for (; i < n; i |= i + 1) ret += num[i];
    return ret;
  }
  int n;
  vector<int> num;
};

vector<int> adj[N], edge[N];
int a[N], n;

// HLD PERSPERATION TINGX
int num_comp, comp[N], id[N], p[N], cnt[N];
vector<int> el[N];
bool on[N];
set<int> one[N];
Fenwick bit[N];

int get(int now) {
  return bit[comp[now]].find(id[now]);
}

int get_child(int now) {
  int ret = 0;
  for (auto it : edge[now]) ret += get(it);
  return ret;
}

// true, udah bisa lanjut
bool check(int now) {
  return get_child(now) > get(now);
}

void add(int now) {
  if (now == 0) return;
  if (on[now]) {
    if (check(now)) {
      on[now] = 0;
      one[comp[now]].erase(id[now]);
      bit[comp[now]].add(id[now], +1);
      bit[comp[now]].add(id[now] - 1, -1);
      return add(p[now]);
    } else {
      return;
    }
  }
  auto it = one[comp[now]].lower_bound(id[now]);
  if (it != one[comp[now]].begin()) {
    it--;
    bit[comp[now]].add(id[now], +1);
    bit[comp[now]].add(*it, -1);
    return add(el[comp[now]][*it]);
  } else {
    bit[comp[now]].add(id[now], +1);
    return add(p[el[comp[now]][0]]);
  }
}

void dfs(int now, int bef) {
  p[now] = bef;
  cnt[now]++;
  for (auto it : adj[now]) {
    if (it == bef) continue;
    edge[now].push_back(it);
    dfs(it, now);
    cnt[now] += cnt[it];
  }
}

void hld(int now) {
  comp[now] = num_comp;
  id[now] = el[num_comp].size();
  el[num_comp].push_back(now);
  int maxi = -1, at = -1;
  for (auto it : edge[now]) {
    if (cnt[it] > maxi) {
      maxi = cnt[it];
      at = it;
    }
  }
  if (at == -1) {
    num_comp++;
    return;
  }
  hld(at);
  for (auto it : edge[now]) if (it != at) hld(it);
}

void build_hld() {
  dfs(1, 0);
  hld(1);
  for (int i = 0; i < num_comp; i++) bit[i] = Fenwick(el[i].size());
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  build_hld();
  // a[i] - minus cnt - i
  vector<tuple<int, int, int>> ord;
  for (int i = 1; i <= n; i++) {
    ord.emplace_back(a[i], -cnt[i], i);
  }
  sort(ord.begin(), ord.end());
  reverse(ord.begin(), ord.end());
  for (auto it : ord) {
    int now;
    tie(ignore, ignore, now) = it;
    //printf("bazinga %d\n", now);
    bit[comp[now]].add(id[now], 1);
    bit[comp[now]].add(id[now] - 1, -1);
    add(p[now]);
    on[now] = 1;
    one[comp[now]].insert(id[now]);
    //for (int i = 1; i <= n; i++) printf("%d ", get(i)); printf("\n");
  }
  cout << n - get(1) << endl;
  return 0;
}
