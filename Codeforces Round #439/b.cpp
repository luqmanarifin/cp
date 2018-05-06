
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 1 << endl;
  } else {
    long long ans = 1;
    for (long long i = a + 1; i <= b; i++) {
      ans = (ans * i) % 10;
      if (ans == 0) break;
    }
    cout << ans << endl;
  }

  return 0;
}
