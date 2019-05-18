#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int best[N];
int cnt[N];

int get(int n) {
  return n * (n - 1) / 2;
}

int main() {
  for (int i = 0; i < N; i++) {
    best[i] = 2e9;
    for (int j = 0; j <= i; j++) {
      best[i] = min(best[i], get(j) + get(i - j));
    }
  }

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    cnt[s[i][0] - 'a']++;
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) ans += best[cnt[i]];
  cout << ans << endl;
  return 0;
}
