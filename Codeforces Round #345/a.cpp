#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
map<int, int> ca, cb;
map<pair<int, int>, int> c;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    ca[a[i]]++;
    cb[b[i]]++;
    c[make_pair(a[i], b[i])]++;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long add = (ca[a[i]] - 1) + (cb[b[i]] - 1) - (c[make_pair(a[i], b[i])] - 1);
    ans += add;
    //cout << "tit " << ans << ' ' << add << endl;
  }
  cout << ans / 2 << endl;
  return 0;
}
