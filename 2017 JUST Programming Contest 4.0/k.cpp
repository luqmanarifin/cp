#include <bits/stdc++.h>

using namespace std;

long long C[22][22];
int cnt[30];
char s[22];
int main() {
  for (int i = 0; i < 22; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
      cnt[s[i] - 'a']++;
    int ganjil = 0, tot = 0;
    for (int i = 0; i < 26; i++) {
      ganjil += cnt[i] & 1;
      cnt[i] /= 2;
      tot += cnt[i];
    }
    long long ans = 1;
    if (ganjil > 1)
      ans = 0;
    for (int i = 0; i < 26; i++) {
      ans *= C[tot][cnt[i]];
      tot -= cnt[i];
    }
    cout << ans << endl;
  }
  return 0;
}