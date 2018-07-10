#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int arr[N];

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if (l == r) {
      num[p][0] = arr[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
  }
  int find(int l, int r, int val) {
    return find(1, 1, n, l, r, val);
  }
  int find(int p, int l, int r, int ll, int rr, int val) {
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) {
      return upper_bound(num[p].begin(), num[p].end(), val) - lower_bound(num[p].begin(), num[p].end(), val);
    }
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr, val) + find(p + p + 1, mid + 1, r, ll, rr, val);
  }

  int n;
  vector<vector<int>> num;
};

int a[N];
int to[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int num = N;
  for (int i = n; i >= 1; i--) {
    if (a[i] == m) num = i;
    to[i] = num;
  }

  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == m) {

    } else if (a[i] > m) {
      now++;
    } else {
      now--;
    }
    arr[i] = now;
  }
  segtree seg(n);
  for (int i = 1; i <= n; i++) printf("%d ", arr[i]); printf("\n");

  now = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (to[i] <= n) {
      int add = seg.find(to[i], n, now) + seg.find(to[i], n, now + 1);
      ans += add;
      printf("%d: start from %d, now %d, nambah %d\n", i, to[i], now, add);
    }

    if (a[i] == m) {

    } else if (a[i] > m) {
      now++;
    } else {
      now--;
    }
  }
  cout << ans << endl;
  return 0;
}
