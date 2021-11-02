#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N], at[N];
int pos[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", at, s);
    for (int i = 0; i < 26; i++) {
      pos[at[i] - 'a'] = i;
    }
    int n = strlen(s), ans = 0;
    for (int i = 1; i < n; i++) {
      ans += abs(pos[s[i]-'a'] - pos[s[i-1]-'a']);
    }
    printf("%d\n", ans);
  }

  return 0;
}
