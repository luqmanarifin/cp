#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int D = 26;

char s[N];
vector<int> cnt[D];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < D; i++) cnt[i].clear();

    scanf("%s", s);
    int n = strlen(s);
    int a = s[0]-'a';
    int b = s[n-1]-'a';
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a'].push_back(i);
    }
    vector<int> ans;
    for (int i = a; ; i = (a < b? i+1 : i-1)) {
      for (auto it : cnt[i]) {
        ans.push_back(it);
      }
      if (i == b) break;
    }
    printf("%d %d\n", abs(a - b), ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i] + 1, i + 1 == ans.size()? '\n' : ' ');
  }
  return 0;
}
