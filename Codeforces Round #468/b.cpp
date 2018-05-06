
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];

vector<int> all[26];
int cnt[26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int k = 0; k < n; k++) {
    all[s[k]-'a'].push_back(k);
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int best = 0;
    for (int j = 1; j < n; j++) {
      memset(cnt, 0, sizeof(cnt));
      for (auto it : all[i]) {
        cnt[s[(it+j)%n] - 'a']++;
      }
      int cur = 0;
      for (int k = 0; k < 26; k++) if (cnt[k] == 1) cur++;
      best = max(best, cur);
    }
    ans += best;
  }
  printf("%.15f\n", (double) ans / n);
  return 0;
}
