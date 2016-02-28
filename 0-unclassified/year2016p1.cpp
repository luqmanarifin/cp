#include <bits/stdc++.h>

using namespace std;

vector<int> a[3];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    while(m--) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(auto it : a[i]) {
        for(auto jt : a[j]) {
          if(it == jt) {
            puts("YES");
            return 0;
          }
        }
      }
    }
  }
  puts("NO");
  return 0;
}
