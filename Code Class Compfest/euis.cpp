#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

char s[N];

int main() {
  gets(s);
  int n = strlen(s);
  long long ans = 1;
  for(int i = 0; i < n; i++) {
    if(i + 1 < n && s[i] == 'e' && s[i + 1] == 'u') {
      ans *= 3;
      ans %= mod;
      i++;
    } else if(s[i] == 'e') {
      ans *= 2;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
