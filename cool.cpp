#include <bits/stdc++.h>

using namespace std;

int cool(int num) {
  string s;
  for(int i = 0; i < 31; i++) {
    s.push_back((num & (1 << i))? '1' : '0');
  }
  int ret = 0;
  for(int i = 2; i < 31; i++) {
    if(s[i] == '1' && s[i - 1] == '0' && s[i - 2] == '1') {
      ret++;
    }
  }
  return ret;
}

vector<int> a[105];

int main() {
  for(int i = 1; i <= 100000; i++) {
    a[cool(i)].push_back(i);
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int r, k;
    scanf("%d %d", &r, &k);
    int ans = 0;
    for(int i = k; i <= 100; i++) {
      int id = upper_bound(a[i].begin(), a[i].end(), r) - a[i].begin();
      ans += id;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
