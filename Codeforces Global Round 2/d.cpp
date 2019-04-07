#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

map<long long, int> cntdif;

map<long long, long long> ans;
long long l[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  set<long long> num;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    num.insert(a[i]);
  }
  sort(a, a + n);

  vector<long long> dif; 
  dif.push_back(0);
  cntdif[0] = 0;
  for (int i = 1; i < n; i++) {
    long long d = a[i] - a[i-1];
    if (!cntdif.count(d)) {
      dif.push_back(d);
      cntdif[d] = 0;
    }
    cntdif[d]++;
  }
  sort(dif.begin(), dif.end());

  set<long long> queries;

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%lld %lld", l + i, r + i);
    queries.insert(r[i] - l[i]);
  }

  long long add = n;
  long long now = n;
  auto it = queries.begin();
  for (int i = 0; i < dif.size(); i++) {
    now -= cntdif[dif[i]];
    add -= cntdif[dif[i]];

    // printf("%lld: %lld %lld\n", dif[i], now, add);

    while (it != queries.end()) {
      if (i + 1 < dif.size() && *it >= dif[i + 1]) break;
      ans[*it] = now + add * (*it - dif[i]);
      it++;
    }
    if (i + 1 < dif.size()) {
      now += (dif[i + 1] - dif[i]) * add;
    }
  }
  for (int i = 0; i < q; i++) printf("%lld ", ans[r[i] - l[i]]);
  return 0;
}
