#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> in[N], out[N];
vector<int> in2[N], out2[N];
int bit[N];

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int find(int l, int r) {
  return find(r) - find(l - 1);
}

void add(int i, int v) {
  for (; i < N; i |= i + 1) {
    bit[i] += v;
  }
}

int ans[N];
vector<tuple<int, int, int>> query[N];   // l, r, id
vector<tuple<int, int, int>> query2[N];   // l, r, id

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a == c) {
      in2[min(b, d)].push_back(a);
      out2[max(b, d)].push_back(a);
      query[a].emplace_back(min(b, d), max(b, d), i);
    } else {
      in[min(a, c)].push_back(b);
      out[max(a, c)].push_back(b);
      query2[b].emplace_back(min(a, c), max(a, c), i);
    }
  }
  long long all = 0;
  for (int i = 0; i < N; i++) {
    set<int> border;
    for (auto it : in[i]) border.insert(it);
    for (auto it : out[i]) border.insert(it);
    for (auto it : in[i]) {
      add(it, 1);
    }
    for (auto it : query[i]) {
      int l, r, id;
      tie(l, r, id) = it;
      int cur = (find(l, l) && !border.count(l));
      cur += (find(r, r) && !border.count(r));
      if (l + 1 < r) {
        cur += find(l + 1, r - 1);
      }
      ans[id] = cur;
      all += cur;
    }
    for (auto it : out[i]) {
      add(it, -1);
    }
  }
  
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < N; i++) {
    set<int> border;
    for (auto it : in2[i]) border.insert(it);
    for (auto it : out2[i]) border.insert(it);
    for (auto it : in2[i]) {
      add(it, 1);
    }
    for (auto it : query2[i]) {
      int l, r, id;
      tie(l, r, id) = it;
      int cur = (find(l, l) && !border.count(l));
      cur += (find(r, r) && !border.count(r));
      if (l + 1 < r) {
        cur += find(l + 1, r - 1);
      }
      ans[id] = cur;
    }
    for (auto it : out2[i]) {
      add(it, -1);
    }
  }
  
  printf("%lld\n", all);
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
