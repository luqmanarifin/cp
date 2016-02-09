#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

char s[105][10005];
vector<int> a[105][26];
char q[105];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      a[i][s[i][j] - 'a'].push_back(j);
    }
  }
  
  while(k--) {
    vector<int> num;
    int pol, at;
    scanf("%s %d %d", q, &pol, &at);
    at--;
    for(int i = 0; i < n; i++) {
      if(a[i][q[i] - 'a'].empty()) continue;
      int t = (lower_bound(a[i][q[i] - 'a'].begin(), a[i][q[i] - 'a'].end(), at) - a[i][q[i] - 'a'].begin()) % a[i][q[i] - 'a'].size();
      int dif = min(abs(at - a[i][q[i] - 'a'][t]), m - abs(at - a[i][q[i] - 'a'][t]));
      
      t = (t - 1 + a[i][q[i] - 'a'].size()) % a[i][q[i] - 'a'].size();
      dif = min(dif, min(abs(at - a[i][q[i] - 'a'][t]), m - abs(at - a[i][q[i] - 'a'][t])));
      num.push_back(dif);
    }
    sort(num.begin(), num.end());
    int now = 0;
    long long ans = 0;
    for(int i = 0; i < num.size(); i++) {
      if(now + num[i] <= pol) {
        ans++;
        now += num[i];
      } else {
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
