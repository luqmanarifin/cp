#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < (1 << 17); i++) {
    for (int mask = i; mask < (1 << 17); mask = ((mask + 1) | i)) {
      ans++;
    }
  }
  cout << (ans)*18LL << endl;
  return 0;
}
