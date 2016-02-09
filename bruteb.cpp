#include <bits/stdc++.h>

using namespace std;

int main() {
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  long long r, b;
  long long ans = 0;
  for(long long i = 0; i <= c / wr; i++) {
    long long cur = i * hr + (c - i * wr) / wb * hb;
    if(cur > ans) {
      ans = cur;
      r = i;
      b = (c - i * wr) / wb;
    }
  }
  cout << ans << endl;
  printf("r = %I64d\nb = %I64d\n", r, b);
  return 0;
}
