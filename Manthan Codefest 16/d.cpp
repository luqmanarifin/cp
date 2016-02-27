#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;

const int N = 1005;

vector<int> p;
int st[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
    p.push_back(a);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  int ans = 2;
  for(int i = 0; i < p.size(); i++) {
    for(int j = 0; j < p.size(); j++) {
      cnt[p[i]]--;
      if(cnt[p[j]] == 0) {
        cnt[p[i]]++;
        continue;
      }
      cnt[p[j]]--;
      int a = p[i], b = p[j], add = 2, sz = 0;
      while(cnt[a + b]) {
        cnt[a + b]--;
        st[sz++] = a + b;
        b = b + a;
        a = b - a;
        add++;
      }
      ans = max(ans, add);
      cnt[p[i]]++;
      cnt[p[j]]++;
      for(int i = 0; i < sz; i++) cnt[st[i]]++;
    }
  }
  cout << ans << endl;
  return 0;
}
