#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N], tmp[N];

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

main() {
  int n, k;
  scanf("%lld %lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  vector<int> num;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j]) j++;
    num.push_back(j - i + 1);
    i = j;
  }
  long long ori = 0;
  for (auto it : num) ori += sum(it);
  long long ans = ori;
  if (k >= 1) {
    long long cur = 0;
    for (int i = 1; i < num.size(); i++) {
      long long mx = max(num[i], num[i - 1]);
      long long mn = min(num[i], num[i - 1]);
      cur = max(cur, mx + 1 - mn);
    }
    for (int i = 1; i < num.size(); i++) {
      if (num[i] == 1) {
        cur = max(cur, -1 - sum(num[i-1]) - sum(num[i+1]) + sum(num[i-1] + 1 + num[i+1]));
      }
    }
    ans = max(ans, ori + cur);
  }
  if (k >= 2) {
    long long cur = 0;
    for (int i = 1; i + 1 < num.size(); i++) {
      cur = max(cur, 2 * num[i] + 3 - num[i - 1] - num[i + 1]);
    }
    for (int i = 1; i < num.size(); i++) {
      long long mx = max(num[i], num[i - 1]);
      long long mn = min(num[i], num[i - 1]);
      if (mn >= 2) {
        cur = max(cur, 2 * mx + 3 - mn - (mn - 1));
      }
    }
    for (int i = (int) num.size() - 2; i >= 0; i--) {
      long long mx = max(num[i], num[i + 1]);
      long long mn = min(num[i], num[i + 1]);
      tmp[i] = max(tmp[i + 1], mx + 1 - mn);
    }
    long long now = 0;
    for (int i = 1; i < num.size(); i++) {
      long long mx = max(num[i], num[i - 1]);
      long long mn = min(num[i], num[i - 1]);
      now = max(now, mx + 1 - mn);
      cur = max(cur, now + tmp[i + 1]);
    }
    
    ans = max(ans, ori + cur);
  }
  cout << ans << endl;
  return 0;
}
