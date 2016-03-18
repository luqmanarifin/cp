#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> p;
char s[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
      p.push_back(i);
    }
  }
  int ans = 1e9;
  for(int i = 0; i + k < p.size(); i++) {
    int l = i, r = i + k;
    while(r - l > 1) {
      int mid = (l + r) >> 1;
      if(abs(p[mid] - p[i]) <= abs(p[mid] - p[i + k])) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ans = min(ans, max(abs(p[l] - p[i]), abs(p[l] - p[i + k])));
    ans = min(ans, max(abs(p[r] - p[i]), abs(p[r] - p[i + k])));
  }
  cout << ans << endl;
  return 0;
}
