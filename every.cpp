#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N], a[N];
int cur[N][26];

int main() {
  scanf("%s", s);
  int n, len = strlen(s);
  for(int i = 0; i < 26; i++) {
    cur[len][i] = len;
  }
  for(int i = len - 1; i >= 0; i--) {
    for(int j = 0; j < 26; j++) {
      cur[i][j] = cur[i + 1][j];
    }
    cur[i][s[i]-'a'] = i;
  }
  scanf("%d", &n);
  int ans = 0;
  while(n--) {
    scanf("%s", a);
    int til = strlen(a);
    int now = -1;
    for(int i = 0; i < til; i++) {
      if(now == len) break;
      now = cur[now + 1][a[i]-'a'];
    }
    ans += (now < len);
  }
  cout << ans << endl;
  return 0;
}