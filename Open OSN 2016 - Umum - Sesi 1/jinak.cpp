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

int all;

void solve(int l, int end) {
  int r = (l + end - 1) / 2;
  for(int k = 0; k < n; k++) {
    for(int at = l; at <= r; at++) {
      
      // simulasi
      vector<int> bunyi, num;
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
      all++;
      //assert(all <= 6 * n);
      printf("%d\n", i + 1);
      fflush(stdout);
      scanf("%s", s);
      if(s[0] == 'B') {
        bunyi.push_back(i);
      }
      if (bunyi.size() == n) return;
      if(pencet == lim && bunyi.empty() && r - l + 1 != n) {
        solve(r + 1, end);
        return;
      }
    }
    
    for(int i = r; i >= l; i--) {
      pencet++;
      all++;
      //assert(all <= 6 * n);
      printf("%d\n", i + 1);
      fflush(stdout);
      scanf("%s", s);
      if(s[0] == 'B') {
        bunyi.push_back(i);
      }
      if (bunyi.size() == n) return;
      if(pencet == lim && bunyi.empty() && r - l + 1 != n) {
        solve(r + 1, end);
        return;
      }
    }
  }
  
  for(int k = 0; k < n; k++) {
    for(int at = l; at <= r; at++) {
      if(same(bunyi, a[k][at])) {
        while(bunyi.size() < n) {
          all++;
          //assert(all <= 6 * n);
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

bool cmp(vector<int>& l, vector<int>& r) {
  if (l.size() < r.size()) return 0;
  if (l.size() > r.size()) return 1;
  for (int i = 0; i < l.size(); i++) {
    if (l[i] < r[i]) return 0;
    if (l[i] > r[i]) return 1;
  }
  return 0;
}

int main() {
  /*
  for (int n = 7; n <= 36; n++) {
    int l = 0;
    int r = n / 2 - 1;
    int mid = (l + r) / 2;
    vector<vector<int>> all;
    for(int k = 0; k < n; k++) {
      for(int at = l; at <= r; at++) {
        vector<int> bunyi, num;
        for(int i = l; i <= r; i++) {
          num.push_back(i);
        }
        for (int i = l; i <= mid; i++) num.push_back(i);
        for (int i = r; i > mid; i--) num.push_back(i);
        
        for (int i = mid+1; i <= r; i++) num.push_back(i);
        for (int i = mid; i >= l; i--) num.push_back(i);
        
        for(int i = l; i <= mid; i++) num.push_back(i);
        
        for(int i = 0; i < num.size(); i++) {
          if(num[i] == at && i + k < num.size()) {
            bunyi.push_back(num[i + k]);
          }
        }
        a[k][at] = bunyi;
        all.push_back(bunyi);
        //printf("%d %d: ", k, at);
        //for (auto it : bunyi) printf("%d ", it); printf("\n");
      }
    }
    sort(all.begin(), all.end(), cmp);
    for (int i = 1; i < all.size(); i++) if (same(all[i], all[i-1])) {
      puts("ada");
    }
  }
  */
  
  scanf("%s %d %d %d", s, &n, &t, &type);
  solve(0, n - 1);
  return 0;
}