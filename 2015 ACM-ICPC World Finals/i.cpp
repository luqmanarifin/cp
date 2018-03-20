#include <bits/stdc++.h>

using namespace std;

const int eps = 1e-7;
const int N = 4e5;

vector<double> p;
int sum[N];

int id(double x) {
  return lower_bound(p.begin(), p.end(), x - eps) - p.begin();  
}

int main() {
  int n, w, u, v, t1, t2;
  scanf("%d %d %d %d %d %d", &n, &w, &u, &v, &t1, &t2);
  vector<pair<double, double>> bad;
  p.push_back(t1);
  p.push_back(t2);
  for (int i = 0; i < n; i++) {
    char c; int k;
    scanf(" %c %d", &c, &k);
    while (k--) {
      int len, pos;
      scanf("%d %d", &len, &pos);
      if (c == 'E') pos = -pos;
      double start_lane = (double) pos / u;
      double end_lane = (double) (pos + len) / u;
      start_lane -= (double) (i + 1) * w / v;
      end_lane -= (double) i * w / v;
      p.push_back(start_lane);
      p.push_back(end_lane);
      bad.emplace_back(start_lane, end_lane);
      //printf("dilarang %.3f %.3f\n", start_lane, end_lane);
    }
  }
  sort(p.begin(), p.end());
  for (auto it : bad) {
    int s = id(it.first);
    int t = id(it.second);
    sum[s]++;
    sum[t]--;
  }
  for (int i = 1; i < p.size(); i++) sum[i] += sum[i-1];
  int l = id(t1);
  int r = id(t2);
  double ans = 0;
  for (int i = l; i < r; i++) {
    if (sum[i]) continue;
    int j = i + 1;
    while (j < r && sum[j] == 0) j++;
    ans = max(ans, p[j] - p[i]);
    i = j - 1;
  }
  printf("%.15f\n", ans);
  return 0;
}
