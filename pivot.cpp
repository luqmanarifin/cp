#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
bool sip[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sip[i] = 1;
  }
  set<int> s;
  s.insert(a[0]);
  for(int i = 1; i < n; i++) {
    auto it = s.end();
    it--;
    if(*it > a[i]) {
      sip[i] = 0;
    }
    s.insert(a[i]);
  }
  s.clear();
  s.insert(a[n - 1]);
  for(int i = n - 2; i >= 0; i--) {
    auto it = s.begin();
    if(*it < a[i]) {
      sip[i] = 0;
    }
    s.insert(a[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) ans += sip[i];
  cout << ans << endl;
  return 0;
}
