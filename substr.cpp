#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<long long, int> m[26];
char s[N];
int x[26];

int main() {
  for(int i = 0; i < 26; i++) {
    scanf("%d", &x[i]);
  }
  scanf("%s", s);
  int n = strlen(s);
  long long now = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    int at = s[i] - 'a';
    ans += m[at][now];
    now += x[at];
    m[at][now]++;
  }
  cout << ans << endl;
  return 0;
}