#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const int BIT = 17;

int num[N * 20];

void reset(int p, int i, int at) {
  num[p] = inf;
  if (i == -1) return;
  if (at & (1 << i)) {
    reset(p + p + 1, i - 1, at);
  } else {
    reset(p + p, i - 1, at);
  }
}

void update(int p, int i, int at, int val) {
  if (i == -1) {
    num[p] = min(num[p], val);
    return;
  }
  if (at & (1 << i)) {
    update(p + p + 1, i - 1, at, val);
  } else {
    update(p + p, i - 1, at, val);
  }
  num[p] = min(num[p + p], num[p + p + 1]);
}

int find(int p, int i, int at, int lim) {
  if (i == -1) return num[p];
  if (at & (1 << i)) {
    if (num[p + p] > lim) {
      return find(p + p + 1, i - 1, at, lim);
    } else {
      return find(p + p, i - 1, at, lim);
    }
  } else {
    if (num[p + p + 1] > lim) {
      return find(p + p, i - 1, at, lim);
    } else {
      return find(p + p + 1, i - 1, at, lim);
    }
  }
  assert(0);
}

// bates, id
vector<pair<int, int>> que[N];
int ans[N];
int t[N], xi[N], ki[N], si[N];
int lowest[N];

int main() {
  fill(lowest, lowest + N, inf);

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", t + i);
    if (t[i] == 1) {
      scanf("%d", xi + i);
      lowest[xi[i]] = min(lowest[xi[i]], i);
    } else {
      scanf("%d %d %d", xi + i, ki + i, si + i);
      que[ki[i]].emplace_back(si[i] - xi[i], i);
    }
  }
  for (int i = 0; i < (1 << 17); i++) reset(1, BIT - 1, i);
  for (int k = 1; k < N; k++) {
    sort(que[k].begin(), que[k].end());
    int now = 0;
    for (auto it : que[k]) {
      while (now <= it.first) {
        //printf("update %d lowest %d\n", now, lowest[now]);
        update(1, BIT - 1, now, lowest[now]);
        now += k;
      }
      int id = it.second;
      int x = xi[id];
      int k = ki[id];
      int s = si[id];
      ans[id] = find(1, BIT - 1, x, id);
    }
    for (int i = 0; i < N; i += k) {
      reset(1, BIT - 1, i);
    }
  }
  for (int i = 0; i < q; i++) {
    if (t[i] == 2) {
      if (xi[i] % ki[i]) {
        ans[i] = -1;
      } else if (ans[i] < i) {
        ans[i] = xi[ans[i]];
      } else {
        ans[i] = -1;
      }
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}
