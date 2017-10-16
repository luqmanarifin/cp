#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int a[N][N];
char s[N];
bool vis[N][N];

int main() {
  for (int i = 0; i < 100; i++) {
    scanf("%s", s);
    set<int> a;
    for (int j = 0; j < 3; j++) a.insert(s[i]);
    assert(a.size() == 3);
    for (int j = 0; j < 3; j++) {
      if (vis[s[j]-'A'][s[(j+1)%3]-'A']) assert(0);
    }
    for (int j = 0; j < 3; j++) {
      vis[s[j]-'A'][s[(j+1)%3]-'A'] = 1;
      vis[s[(j+1)%3]-'A'][s[j]-'A'] = 1;
    }
  }
  return 0;
}
