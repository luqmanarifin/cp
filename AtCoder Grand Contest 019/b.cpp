#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 1;
  for (int i = n - 1; i >= 0; i--) {
    ans += (n - i - 1) - cnt[s[i] - 'a'];
    cnt[s[i] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}
