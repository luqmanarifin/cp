#include <bits/stdc++.h>

using namespace std;

int main() {
  int l = 0, r = 1e5;
  int cnt = 0;
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    cnt++;
    l = lf;
  }
  cout << cnt + 3 << endl;
  return 0;
}
