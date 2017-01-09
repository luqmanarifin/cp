#include <bits/stdc++.h>

using namespace std;

int main() {
  int now = 0;
  vector<int> dua, satu;
  int n;
  scanf("%d", &n);
  int maks = 0;
  for (int i = 0; i < n; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    if (d == 1) {
      satu.push_back(now);
    } else {
      dua.push_back(now);
    }
    now += c;
    maks = min(maks, now);
  }
  if (dua.empty()) {
    puts("Infinity");
    return 0;
  }
  sort(dua.begin(), dua.end());
  sort(satu.begin(), satu.end());
  if (satu.size()) {
    if (dua.back() >= satu[0]) {
      puts("Impossible");
      return 0;
    }
  }
  printf("%d\n", 1899 - dua.back() + now);
  return 0;
}
