#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int a[N];

vector<int> edge[26];
int to[26];
char ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int len = min(strlen(s[a[i]]), strlen(s[a[j]]));
      for (int k = 0; k < len; k++) {
        if (s[a[i]][k] != s[a[j]][k]) {
          edge[s[a[i]][k] - 'a'].push_back(s[a[j]][k] - 'a');
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (auto it : edge[i]) {
      to[it]++;
    }
  }
  vector<int> topo;
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (to[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int now = q.front();
    topo.push_back(now);
    q.pop();
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }
  if (topo.size() != 26) {
    puts("NE");
    return 0;
  }
  puts("DA");
  for (int i = 0; i < 26; i++) {
    ans[topo[i]] = i + 'a';
  }
  printf("%s\n", ans);
  return 0;
}
