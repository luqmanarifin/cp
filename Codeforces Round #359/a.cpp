#include <bits/stdc++.h>

using namespace std;

int digit(int n) {
  n--;
  if(n == 0) return 1;
  int ret = 0;
  while(n) {
    ret++;
    n /= 7;
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(digit(n) + digit(m) > 7) {
    puts("0");
    return 0;
  }
  int ans = 0;
  int dig = digit(n) + digit(m);
  int dm = digit(m);
  int dn = digit(n);
  int lim = 1, base = 1;
  for(int i = 0; i < dig; i++) {
    lim *= 7;
    if(i < dm) {
      base *= 7;
    }
  }
  //printf("%d %d\n", lim, base);
  for(int i = 0; i < lim; i++) {
    int a = i / base;
    int b = i % base;
    if(a >= n || b >= m) continue;
    vector<int> num;
    int tmp = i;
    for(int j = 0; j < dig; j++) {
      num.push_back(tmp % 7);
      tmp /= 7;
    }
    sort(num.begin(), num.end());
    bool unique = 1;
    for(int j = 1; j < num.size(); j++) {
      if(num[j] == num[j - 1]) {
        unique = 0;
      }
    }
    if(unique) ans++;
  }
  cout << ans << endl;
  return 0;
}
