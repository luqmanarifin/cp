#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
char t[N];
vector<int> at[26][26];

int main() {
  int n;
  scanf("%d %s %s", &n, s, t);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    at[s[i] - 'a'][t[i] - 'a'].push_back(i);
    ans += s[i] != t[i];
  }
  for(int i = 0; i < 26; i++) {
    for(int j = i + 1; j < 26; j++) {
      if(at[i][j].size() && at[j][i].size()) {
        cout << ans - 2 << endl;
        printf("%d %d\n", at[i][j][0] + 1, at[j][i][0] + 1);
        return 0;
      }
    }
  }
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      if(i == j) continue;
      for(int k = 0; k < 26; k++) {
        if(i == k) continue;
        if(at[i][j].size() && at[k][i].size()) {
          cout << ans - 1 << endl;
          printf("%d %d\n", at[i][j][0] + 1, at[k][i][0] + 1);
          return 0;
        }
      }
    }
  }
  cout << ans << endl;
  puts("-1 -1");
  return 0;
}
