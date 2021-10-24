#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int VAL = 512;
const int NUM = 500;

struct Bit {
  Bit(int n = 0) : n(n) {
    num.resize(n + 1);
  }
  void update(int i, int v) {
    for (; i <= n; i |= i + 1) {
      num[i] |= v;
    }
  }
  int find(int i) {
    int ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret |= num[i];
    }
    return ret;
  }
  vector<int> num;
  int n;
};

int a[N];
Bit bit[VAL];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < VAL; i++) {
    bit[i] = Bit(NUM);
  }
  bit[0].update(0, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < VAL; j++) {
      int prev_val = (a[i] ^ j);
      int has = bit[prev_val].find(a[i] - 1);
      if (has) {
        bit[j].update(a[i], 1);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < VAL; i++) {
    if (bit[i].find(NUM)) {
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d%c", ans[i], i + 1 == ans.size()? '\n' : ' ');
  }

  return 0;
}
