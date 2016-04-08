#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
int cnt[26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  vector<pair<int, int>> v;
  for(int i = 0; i < 26; i++) {
    if(cnt[i]) {
      v.emplace_back(cnt[i], i);
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int ans = 0;
  for(int i = 2; i < v.size(); i++) {
    ans += v[i].first;
  }
  cout << ans << endl;
  return 0;
}