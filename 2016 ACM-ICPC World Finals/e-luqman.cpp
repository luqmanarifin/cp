#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;
const int N = 1e4;

long long add(long long a, long long b) {
  return min(inf, a + b);
}

long long mul(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (inf / b < a) return inf;
  return a * b;
}

long long find_ten(long long x, long long b) {
  long long now = 0, pw = 1;
  while (x) {
    long long c = x % 10;
    now = add(now, mul(c, pw));
    pw = mul(pw, b);
    x /= 10;
  }
  return now;
}

long long find_base(long long ten, long long x) {
  long long l = 11, r = 1e18;
  long long ori = x;
  while (l < r) {
    long long b = (l + r + 1) >> 1;
    long long now = find_ten(x, b);
    if (now > ten) {
      r = b - 1;
    } else {
      l = b;
    }
  }
  return l;
}

// -1 artinya jelek
long long find_x(long long ten, long long b) {
  long long ret = 0, pw = 1;
  while (ten) {
    long long now = ten % b;
    if (now >= 10) return -1;
    ret += now * pw;
    ten /= b;
    pw *= 10;
  }
  return ret;
}

int main() {
  //~ cout << find_x(32, 16) << endl;
  //~ cout << find_base(32, 20) << endl;
  //~ cout << find_ten(17, 1000000000000000000LL) << endl;
  //~ cout << find_base(1000000000000000000LL, 17) << endl;
  
  long long y, l;
  cin >> y >> l;
  long long ans = 10;
  for (long long b = ans + 1; b < 5 * N; b++) {
    long long x = find_x(y, b);
    if (x == -1) continue;
    if (x >= l) {
      ans = max(ans, b);
    }
  }
  
  for (long long x = l; x < N; x++) {
    long long b = find_base(y, x);
    if (find_x(y, b) == x) {
      ans = max(ans, b);
    }
  }
  cout << ans << endl;
  //~ cout << find_x(y, ans) << endl;
  return 0;
}
