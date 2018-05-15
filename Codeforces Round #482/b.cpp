#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int LEN = 1e5 + 5;

string ans[] = {"Kuro", "Shiro", "Katie"};
int cnt[N];

int find(const string& s, int k) {
  memset(cnt, 0, sizeof(cnt));
  int n = s.size();
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  int best = 0;
  for (int i = 0; i < N; i++) {
    best = max(best, cnt[i]);
  }
  if (best == n && k == 1) return n - 1;
  best = min(n, best + k);
  return best;
}

char s[LEN];

int main() {
  int k;
  scanf("%d", &k);
  vector<pair<int, int>> all;
  for (int i = 0; i < 3; i++) {
    scanf("%s", s);
    string ss = (string) s;
    all.emplace_back(find(ss, k), i);
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  if (all[0].first == all[1].first) {
    puts("Draw");
  } else {
    cout << ans[all[0].second] << endl;
  }

  return 0;
}
