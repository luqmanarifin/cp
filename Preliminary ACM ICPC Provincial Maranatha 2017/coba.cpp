#include <bits/stdc++.h>

using namespace std;

bool is[4000];

int main() {
  int ans = 0;
  for (int i = 2; i < 4000; i++) {
    if (!is[i]) {
      ans++;
      for (int j = i * i; j < 4000; j += i) {
        is[j] = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
