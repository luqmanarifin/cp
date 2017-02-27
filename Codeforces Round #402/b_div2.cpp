#include <bits/stdc++.h>

using namespace std;

int digit(int a) {
  if (a < 10) return 1;
  return 1 + digit(a / 10);
}

vector<int> trim(int a) {
  vector<int> ret;
  if (a >= 10) {
    ret = trim(a / 10);
  }
  ret.push_back(a % 10);
  return ret;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int num = 1;
  for (int i = 0; i < k; i++) num *= 10;
  
  int ans = 55;
  int dig = digit(n);
  vector<int> val = trim(n);
  //for (auto it : val) printf("%d\n", it);
  for (int mask = 0; mask < (1 << dig) - 1; mask++) {
    int now = 0;
    int first = -1, ada = 0;
    for (int i = 0; i < dig; i++) {
      if (mask & (1 << i)) continue;
      now = now * 10 + val[i];
      ada++;
      if (first == -1) first = val[i];
    }
    if (first == 0 && ada > 1) continue;
    if (now % num == 0) {
      ans = min(ans, __builtin_popcount(mask));
    }
  }
  cout << ans << endl;
  return 0;
}
