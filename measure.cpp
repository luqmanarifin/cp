#include <bits/stdc++.h>

using namespace std;

const double eps = 1. / 120;

double angle(int h, int m) {
  return  h * 30 + m * 1. / 2;
}

vector<pair<double, int>> num;

int main() {
  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 60; j++) {
      double a = angle(i, j);
      double b = j * 6;
      double dif = abs(a - b);
      dif = min(dif, 360 - dif);
      num.emplace_back(dif, i * 60 + j);
    }
  }
  sort(num.begin(), num.end());
  
  int t;
  scanf("%d", &t);
  while(t--) {
    double a;
    scanf("%lf", &a);
    int at = lower_bound(num.begin(), num.end(), make_pair(a, -1)) - num.begin();
    vector<int> ans;
    for(int i = max(0, at - 5); i < num.size() && num[i].first < a + eps; i++) {
      if(abs(num[i].first - a) < eps) {
        ans.push_back(num[i].second);
      }
    }
    sort(ans.begin(), ans.end());
    for(auto it : ans) {
      int h = it / 60;
      int m = it % 60;
      printf("%d%d:%d%d\n", h/10, h%10, m/10, m%10);
    }
  }
  
  return 0;
}
