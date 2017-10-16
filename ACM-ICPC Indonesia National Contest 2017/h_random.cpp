#include <bits/stdc++.h>

using namespace std;

const int N = 30;

bool vis[N][N];

int main() {
  vector<int> a, b, c;
  int n = 25;
  for (int i = 0; i < n; i++) {
    a.push_back(i);
    b.push_back(i);
    c.push_back(i);
    vis[i][i] = 1;
  }
  srand(time(0));
  int t = 0;
  vector<tuple<int, int, int>> s;
  while (t < 100) {
    random_shuffle(a.begin(), a.end());
    bool found = 0;
    for (auto i : a) {
      random_shuffle(b.begin(), b.end());
      for (auto j : b) {
        if (vis[i][j]) continue;
        random_shuffle(c.begin(), c.end());
        for (auto k : c) {
          if (vis[i][k] || vis[j][k]) continue;
          vis[i][j] = vis[j][i] = 1;
          vis[i][k] = vis[k][i] = 1;
          vis[k][j] = vis[j][k] = 1;
          s.emplace_back(i, j, k);
          found = 1;
          goto COK;
        }
      }
    }
    if (!found) {
      cerr << s.size() << " cycle found" << endl; 
      cerr << "NOT FOUND" << endl;
      return 0;
    }
    COK:;
  }
  for (auto it : s) {
    int i, j, k;
    tie(i, j, k) = it;
    printf("%c%c%c\n", i + 'A', j + 'A', k + 'A');
    fprintf(stderr, "%c%c%c\n", i + 'A', j + 'A', k + 'A');
  }
  return 0;
}
