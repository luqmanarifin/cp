#include <bits/stdc++.h>

using namespace std;

string str[55];

int main() {
  int n, p;
  cin >> n >> p;
  p >>= 1;
  for(int i = 0; i < n; i++) {
    cin >> str[i];
  }
  long long ans = 0, now = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(str[i] == "halfplus") {
      now++;
      ans += now * p;
      now *= 2;
    } else {
      ans += now * p;
      now *= 2;
    }
  }
  cout << ans << endl;
  return 0;
}
