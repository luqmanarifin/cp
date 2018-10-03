#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int t[N];
double p[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<double, int>> num;
  for (int i = 0; i < n; i++) {
    scanf("%d %lf", t + i, p + i);
    num.emplace_back(t[i] * p[i], i);
  }
  sort(num.begin(), num.end());
  double sum = 0, now = 0;
  for (int i = 0; i < n; i++) {
    sum += now + num[i].first;
    now += num[i].first;
  }
  printf("%.15f\n", sum / n);
  return 0;
}
