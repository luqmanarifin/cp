#include <bits/stdc++.h>

using namespace std;

char s[20][20];
int n, m;
int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ans = 0;
  int til = max(n, m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < n; k++) {
        for(int l = 0; l < m; l++) {
          set<pair<int, int>> s;
          for(int a = 0; a < til; a++) {
            bool good = 1;
            for(int t = 0; t < 4; t++) {
              s.insert(make_pair(i+a*da[t], j+a*db[t]));
              if(!valid(i+a*da[t], j+a*db[t]) || s[i+a*da[t]][j+a*db[t]] == 'B') {
                good = 0;
                break;
              }
            }
            if(!good) break;
            for(int b = 0; b < til; b++) {
              bool nice = 1;
              for(int t = 0; t < 4; t++) {
                if(!valid(k+b*da[t], l+b*db[t]) || s[k+b*da[t]][l+b*db[t]] == 'B' || s.count(make_pair(k+b*da[t], l+b*db[t]))) {
                  nice = 0;
                  break;
                }
              }
              if(nice) {
                ans += (4 * a + 1)*(4 * b + 1);
              } else {
                break;
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
