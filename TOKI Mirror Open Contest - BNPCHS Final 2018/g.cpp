#include <bits/stdc++.h>

using namespace std;

double dist(int x, int y, int z) {
  return sqrt(x*x + y*y + z*z);
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  vector<double> d;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    d.push_back(dist(x, y, z));
  }
  sort(d.begin(), d.end());
  for (int i = 0; i + 1 < d.size(); i++) {
    d[i + 1] = max(d[i + 1], d[i] + r);
  }
  printf("%.15f\n", d.back());
  return 0;
}
