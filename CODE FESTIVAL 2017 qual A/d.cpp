#include <bits/stdc++.h>

using namespace std;

const int N = 505;

string str = "RYGB";

int s[N][N];
int n, m, d;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  
  scanf("%d %d %d", &n, &m, &d);
  if (d % 2) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        set<int> ada;
        if (i >= d) ada.insert(s[i - d][j]);
        if (j >= d) ada.insert(s[i][j - d]);
        for (int k = 0; k < 4; k++) {
          if (!ada.count(k)) {
            s[i][j] = k;
            break;
          }
        }
      }
    }    
  } else {
    d /= 2;
    memset(s, -1, sizeof(s));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        set<int> ada;
        for (int k = -d; k <= d; k += d) {
          for (int l = -d; l <= d; l += d) {
            if (abs(k) + abs(l) != d) continue;
            if (valid(i + k, j + l) && s[i + k][j + l] != -1) {
              ada.insert(s[i + k][j + l]);
            }
          }
        }
        for (int k = -d; k <= d; k += d) {
          for (int l = -d; l <= d; l += d) {
            if (abs(k) + abs(l) != d) continue;
            if (valid(i + k, j + l) && s[i + k][j + l] == -1) {
              for (int v = 0; v < 4; v++) {
                if (!ada.count(v)) {
                  s[i + k][j + l] = v;
                  ada.insert(v);
                  break;
                }
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", str[s[i][j]]);
    }
    printf("\n");
  }

  return 0;
}
