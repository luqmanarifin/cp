#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAGIC = 320;

int a[N];
int cnt[N];
int ans[N];
int now;

void insert(int v) {
  if (v < N) {
    if (cnt[v] == v) now--;
    cnt[v]++;
    if (cnt[v] == v) now++;
  }
}

void erase(int v) {
  if (v < N) {
    if (cnt[v] == v) now--;
    cnt[v]--;
    if (cnt[v] == v) now++;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  // block, r, l, id
  vector<tuple<int, int, int, int>> q;
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    q.emplace_back(l / MAGIC, r, l, i);
  }
  sort(q.begin(), q.end());

  int pl = 1, pr = 1;
  insert(a[1]);
  for (auto it : q) {
    int l, r, id;
    tie(ignore, r, l, id) = it;
    while (pr < r) {
      insert(a[++pr]);
    }
    while (pl < l) {
      erase(a[pl++]);
    }
    while (l < pl) {
      insert(a[--pl]);
    }
    while (r < pr) {
      erase(a[pr--]);
    }
    ans[id] = now;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
