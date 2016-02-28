#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if((s[i] - '0') % 4 == 0) {
      ans++;
    }
    if(i) {
      int t = (s[i - 1] - '0') * 10 + s[i] - '0';
      if(t % 4 == 0) {
        ans += i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}