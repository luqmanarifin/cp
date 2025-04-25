#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int ans[N], n;

int ask(vector<int> a) {
  printf("? 1 %d", a.size());
  for (auto it : a) printf(" %d", it);
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

void swap(int u) {
  printf("? 2 %d\n", u);
  fflush(stdout);
}

void answer() {
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
  printf("\n");
  fflush(stdout);
}

bool inside(int l, int r) {
  int len = r - l + 1;
  vector<int> nodes;
  for (int i = l; i <= r; i++) {
    nodes.push_back(i);
  }
  int awal = ask(nodes);
  swap(1);
  int akhir = ask(nodes);
  if (abs(awal - akhir) == 2 * len) {
    return 0;
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
    }
    int ask_1 = ask({1}), root;
    if (ask_1 % 2 != 0) {
      root = 1;
    } else {
      int l = 2, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (inside(l, mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      root = l;
    }
    ans[root] = ask({root});
    if (root != 1) {
      int v = ask({1});
      ans[1] = v - ans[root];
    }
    for (int i = 2; i <= n; i++) {
      if (i == root) continue;
      int v = ask({i});
      if (root == 1) {
        ans[i] = v - ans[1];
      } else {
        ans[i] = v - ans[root] - ans[1];
      }
    }
    answer();
  }

  return 0;
}
