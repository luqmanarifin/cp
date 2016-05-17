#include <bits/stdc++.h>

using namespace std;

char s[10];

vector<int> a[40][40];
int n, t, type;

bool same(vector<int>& c, vector<int>& d) {
  if(c.size() != d.size()) return 0;
  for(int i = 0; i < c.size(); i++) {
    if(c[i] != d[i]) return 0;
  }
  return 1;
}

void solve(int l, int r) {
  for(int k = 0; k < n; k++) {
    for(int at = l; at <= r; at++) {
      vector<int> bunyi, num;
      if(r - l + 1 != n) {
        for(int i = l; i <= r; i++) {
          num.push_back(i);
        }
        for(int i = r; i >= l; i--) {
          num.push_back(i);
        }
        for(int i = l; i <= r; i++) {
          num.push_back(i);
        }
        for(int i = r; i >= l; i--) {
          num.push_back(i);
        }
      } else {
        for(int i = l; i <= r; i++) {
          num.push_back(i);
        }
        for(int i = r; i >= l; i--) {
          num.push_back(i);
        }
      }
      for(int i = 0; i < num.size(); i++) {
        if(num[i] == at && i + k < num.size()) {
          bunyi.push_back(num[i + k]);
        }
      }
      a[k][at] = bunyi;
    }
  }
  
  vector<int> bunyi;
  int pencet = 0;
  int lim = n + r - l;
  
  int til = (r - l + 1 == n? 1 : 2);
  for(int tt = 0; tt < til; tt++) {
    for(int i = l; i <= r; i++) {
      pencet++;
      printf("%d\n", i + 1);
      fflush(stdout);
      scanf("%s", s);
      if(s[0] == 'B') {
        bunyi.push_back(i);
      }
      if(pencet == lim && bunyi.empty() && r - l + 1 != n) {
        solve(n / 2, n - 1);
        return;
      }
    }
    
    for(int i = r; i >= l; i--) {
      pencet++;
      printf("%d\n", i + 1);
      fflush(stdout);
      scanf("%s", s);
      if(s[0] == 'B') {
        bunyi.push_back(i);
      }
      if(pencet == lim && bunyi.empty() && r - l + 1 != n) {
        solve(n / 2, n - 1);
        return;
      }
    }
  }
  
  for(int k = 0; k < n; k++) {
    for(int at = l; at <= r; at++) {
      if(same(bunyi, a[k][at])) {
        while(bunyi.size() < n) {
          printf("%d\n", at + 1);
          fflush(stdout);
          scanf("%s", s);
          if(s[0] == 'B') {
            bunyi.push_back(0);
          }
        }
        return;
      }
    }
  }
}

int main() {
  scanf("%s %d %d %d", s, &n, &t, &type);
  if(type == 0) {
    solve(0, n - 1);
  } else {
    solve(0, n / 2 - 1);
  }
  return 0;
}