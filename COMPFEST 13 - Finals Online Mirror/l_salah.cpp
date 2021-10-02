#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.resize((n + 1) << 2, 0);
    push.resize((n + 1) << 2, -1);
  }
  void update(int l, int r, int val) {
    update(1, 0, n, l, r, val);
  }
  void update(int p, int l, int r, int ll, int rr, int val) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = max(push[p], val);
      lazy(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, val);
    update(p + p + 1, mid + 1, r, ll, rr, val);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, n, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  void lazy(int p, int l, int r) {
    if (push[p] != -1) {
      num[p] = max(num[p], push[p]);
      push[p + p] = max(push[p + p], push[p]);
      push[p + p + 1] = max(push[p + p + 1], push[p]);
      push[p] = -1;
    }
  }
  vector<int> num, push;
  int n;
};

int a[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    c[i] = i - a[i];
  }
  segtree seg(n);
  for (int i = 1; i <= n; i++) {
    if (c[i] >= 0) {
      int from = c[i] + n - i;
      int l = c[i];
      int r = c[i] + n - i;
      if (0 <= from && from <= n) {
        printf("%d: seg find %d %d\n", i, from, from);
        int val = seg.find(from, from);
        printf("%d: seg update %d %d: %d\n", i, l, r, val + 1);
        seg.update(l, r, val + 1);
      }
    } 
    printf("%d: ", i); for (int i = 0; i <= n; i++) printf("%d ", seg.find(i, i)); printf("\n");
  }
  // puts("ANS");
  cout << seg.find(0, n) << endl;
  for (int i = 0; i <= n; i++) printf("%d ", seg.find(i, i)); printf("\n");
  return 0;
}
