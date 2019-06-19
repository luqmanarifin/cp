#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long sum[N];
long long cnt[N];

void add(long long* bit, int i, int val) {
  for (; i < N; i |= i + 1) {
    bit[i] += val;
  }
}

long long find(long long* bit, int i) {
  long long ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int a[N], to[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > num;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    num.emplace_back(a[i], i);
  }
  sort(num.begin(), num.end());
  for (int i = 0; i < num.size(); i++) {
    to[num[i].second] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = n;
    long long lim = m - a[i];
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (find(sum, mid) <= lim) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    int tampung = find(cnt, l);
    printf("%d ", i - 1 - tampung);
    add(sum, to[i], a[i]);
    add(cnt, to[i], 1);
  }

  return 0;
}
