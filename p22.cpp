#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  multiset<int> s;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
    s.insert(num);
  }
  sum /= n;
  int ans = 0;
  while(*s.begin() != sum) {
    ans++;
    int sm = *s.begin();
    auto it = s.end(); it--;
    int bg = *it;
    s.erase(s.find(sm));
    s.erase(s.find(bg));
    int d = bg - sum;
    sm += d;
    bg -= d;
    s.insert(sm);
    s.insert(bg);
  }
  cout << ans << endl;
  return 0;
}
