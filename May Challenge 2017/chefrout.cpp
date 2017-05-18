#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
vector<int> p[3];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 3; i++) p[i].clear();
    
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      int c;
      switch (s[i]) {
        case 'C': c = 0; break;
        case 'E': c = 1; break;
        case 'S': c = 2; break;
      }
      p[c].push_back(i);
    }
    bool done = 0;
    for (int i = 1; i < 3; i++) {
      for (int j = 0; j < i; j++) {
        if (p[i].empty() || p[j].empty()) continue;
        if (p[i][0] < p[j].back() && !done) {
          puts("no");
          done = 1;
        }
      }
    }
    if (!done) puts("yes");
  }

  return 0;
}
