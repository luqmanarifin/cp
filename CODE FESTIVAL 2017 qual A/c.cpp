#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cnt[26];
char s[N][N];
bool done[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      cnt[s[i][j] - 'a']++;
    }
  }
  vector<int> need;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (done[i][j]) continue;
      done[i][j] = 1;
      done[n - i - 1][j] = 1;
      done[i][m - j - 1] = 1;
      done[n - i - 1][m - j - 1] = 1;
      
      set<pair<int, int>> s;
      
      s.insert({i, j});
      s.insert({n - i - 1, j});
      s.insert({i, m - j - 1});
      s.insert({n - 1 - i, m - 1 - j});
      need.push_back(s.size());
      
      //for (auto it : s) printf("%d %d\n", it.first, it.second); printf("\n");
    }
  }
  priority_queue<int> pq;
  for (int i = 0; i < 26; i++) {
    pq.push(cnt[i]);
  }
  sort(need.begin(), need.end());
  reverse(need.begin(), need.end());
  //for (auto it : need) printf("%d ", it); printf("\n");
  for (auto it : need) {
    int now = pq.top();
    pq.pop();
    if (it > now) {
      puts("No");
      return 0;
    }
    pq.push(now - it);
  }
  puts("Yes");
  return 0;
}
