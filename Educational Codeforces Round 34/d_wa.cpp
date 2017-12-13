#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct bit {
  bit() {
    a.assign(N, 0);
  }
  void add(int i, long long v) {
    for (; i < N; i |= i + 1) {
      a[i] += v;
    }
  }
  long long find(int i) {
    long long ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += a[i];
    }
    return ret;
  }
  vector<long long> a;
};

int a[N];
vector<int> all;

int id(int v) {
  return lower_bound(all.begin(), all.end(), v) - all.begin();
}

int rev(int i) {
  return all.size() - 1 - i;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    for (int j = -1; j <= 1; j++) {
      all.push_back(a[i] + j);
    }
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < n; i++) a[i] = id(a[i]);
  bit sum_low;
  bit sum_upp;
  bit cnt_low;
  bit cnt_upp;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt_low.find(a[i] - 2) * all[a[i]] - sum_low.find(a[i] - 2);
    ans += cnt_upp.find(rev(a[i]) - 2) * all[a[i]] - sum_upp.find(rev(a[i]) - 2);
    
    sum_low.add(a[i], all[a[i]]);
    cnt_low.add(a[i], 1);
    sum_upp.add(rev(a[i]), all[a[i]]);
    cnt_upp.add(rev(a[i]), 1);
  }
  cout << ans << endl;
  return 0;
}