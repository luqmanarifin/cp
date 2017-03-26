#include <bits/stdc++.h>

using namespace std;

#define int long long

const long long mod = 1e9 + 7;

map<int, int> ans;

int find(int n) {
  auto it = ans.find(n);
  if (it != ans.end()) return it->second;
  bool ada = 0;
  long long ret = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i != n) {
        ret += find(i) * find(n / i);
      } else {
        ret += find(i) * (find(i) + 1) / 2;
      }
      ret %= mod;
      ada = 1;
    } 
  }
  if (!ada) {
    ret = 1;
  }
  ret %= mod;
  return ans[n] = ret;
}

main() {
  int n;
  cin >> n;
  cout << find(n) << endl;
  return 0;
}
