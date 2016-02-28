#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char a[N][15], s[N];
int cnt[26], alen[N];
long long score[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(cnt, 0, sizeof(cnt));
    memset(score, 0, sizeof(score));
    
    int n;
    scanf("%d %s", &n, s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
      cnt[s[i] - 'a']++;
    }
    for(int i = 0; i < n; i++) {
      scanf("%s", a[i]);
      alen[i] = strlen(a[i]);
      for(int j = 0; j < alen[i]; j++) {
        score[i] += cnt[a[i][j] - 'a'];
      }
    }
    tuple<long long, int, int> ans = make_tuple(-1e9, -1e9, -1e9);
    for(int i = 0; i < n; i++) {
      ans = max(ans, make_tuple(score[i], -alen[i], -i));
    }
    printf("%d\n", -get<2>(ans) + 1);
  }
  
  return 0;
}
