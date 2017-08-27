#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string all;
int s[N];

int get(int l, int r) {
  if (l > r) return 0;
  return s[r] - (l? s[l - 1] : 0) + r - l;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    getline(cin, all);
    string buf;
    stringstream ss(all);
    vector<int> a;
    int tot = 0;
    while (ss >> buf) {
      a.push_back(buf.size());
      tot += buf.size();
    }
    memset(s, 0, sizeof(s));
    int n = a.size();
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
      s[i] = s[i - 1] + a[i];
    }    
    
    //printf("tot %d n %d\n", tot, n);
    bool done = 0;
    for (int line = 2; line <= tot + n; line++) {
      int cnt = tot + n - line;
      //printf("line %d char %d\n", line, cnt);
      if (cnt % line) continue;
      int goal = cnt / line;
      bool ok = 1;
      int p = 0;
      while (p < n) {
        int l = p, r = n - 1;
        while (l < r) {
          int mid = (l + r) >> 1;
          int cur = get(p, mid);
          if (cur < goal) {
            l = mid + 1;
          } else if (cur > goal) {
            r = mid - 1;
          } else {
            l = r = mid;
            break;
          }
        }
        if (l == r && get(p, l) == goal) {
          p = l + 1;
        } else {
          ok = 0;
          break;
        }
      }
      if (ok) {
        done = 1;
        puts("YES");
        break;
      }
    }
    if (!done) {
      puts("NO");
    }
  }

  return 0;
}
