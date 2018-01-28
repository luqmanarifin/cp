#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char s[N];
char print[N];
int cnt[256], n;

void dfs(int pos) {
  if (pos == n) {
    for (int i = 0; i < n; i++) printf("%c", print[i]);
    printf("\n");
    return;
  }
  for (int i = 0; i < 256; i++) {
    if (cnt[i]) {
      cnt[i]--;
      
      print[pos] = i;
      dfs(pos + 1);
      
      cnt[i]++;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    dfs(0);
    printf("\n");
  }

  return 0;
}
