#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 2005;
const int COK = 999999999;

int a[N];
int p[N];
long long s[N];
map<int, int> cnt;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
    p[i] = a[i];
  }
  
  sort(p, p + n);
  int m = unique(p, p + n) - p;
  for(int i = 0; i < m; i++) {
    s[i] = 1LL* p[i] * p[i];
  }
  if(n % 2 == 0) {
    cout << inf << endl;
    return 0;
  }
  bool inc = 1, dec = 1;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] > a[i]) inc = 0;
    if(a[i - 1] < a[i]) dec = 0;
  }
  if(inc || dec) {
    cout << inf << endl;
    return 0;
  }
  bool dob = 0;
  for(int i = 0; i < m; i++) {
    if(p[i] == 0) {
      if(cnt[0] > 2) {
        dob = 1;
      }
    } else if(cnt[p[i]] > 1) {
      dob = 1;
    }
  }
  if(cnt[0] && dob) {
    cout << inf << endl;
    return 0;
  }
  for(int i = 0; i < m; i++) {
    if(p[i] == 0) continue;
    for(int j = i; j < m; j++) {
      if(p[j] == 0) continue;
      if(i == j) {
        if(cnt[a[i]] == 1) {
          continue;
        }
      }
      long long v = 1LL*p[i]*p[i] + 1LL*p[j]*p[j];
      if(binary_search(s, s + m, v)) {
        cout << inf << endl;
        return 0;
      }
    }
  }
  if(n <= 200) {
    for(int i = 0; i < m; i++) {
      if(p[i] && COK % p[i] == 0) {
        cout << inf << endl;
        return 0;
      }
    }
    int fpb = abs(p[0]);
    for(int i = 1; i < m; i++) {
      fpb = __gcd(fpb, abs(p[i]));
    }
    if(COK % fpb == 0) {
      cout << inf << endl;
      return 0;
    }
  }
  
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
