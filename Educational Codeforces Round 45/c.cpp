#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

string s[N];
map<int, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int len = s[i].size();
    int now = 0, mini = 0;
    for (int j = len - 1; j >= 0; j--) {
      if (s[i][j] == '(') {
        now--;
      } else {
        now++;
      }
      mini = min(mini, now);
    }
    if (mini >= 0) {
      mp[now]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int len = s[i].size();
    int now = 0, mini = 0;
    for (int j = 0; j < len; j++) {
      if (s[i][j] == '(') {
        now++;
      } else {
        now--;
      }
      mini = min(mini, now);
    }
    if (mini >= 0) {
      ans += mp[now];
    }
  }
  cout << ans << endl;
  return 0;
}
