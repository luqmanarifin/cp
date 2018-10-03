#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;

long long sum(int n) {
  return n * (n + 1) / 2;
}

long long get(int n) {
  if (n <= 2) return 0;
  return sum(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<double, double>> p;
  double x = 0, y = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      p.emplace_back(x + j, y);
    }
    x += 0.5;
    y += 0.5 * sqrt(3);
  }
  int sz = p.size();
  long long ans = 0;
  for (int i = 0; i < p.size(); i++) {
    vector<double> num;
    for (int j = 0; j < p.size(); j++) {
      if (i != j) {
        num.push_back(atan2(p[j].second - p[i].second, p[j].first - p[i].first));
      }
    }
    sort(num.begin(), num.end());
    for (int j = 0; j < num.size(); j++) {
      int k = j;
      while (k + 1 < num.size() && abs(num[k + 1] - num[k]) < eps) k++;
      int len = k - j + 1;
      ans += len - 1;
      j = k;
    }
  }
  cout << ans / 2 << endl;
  return 0;
}
