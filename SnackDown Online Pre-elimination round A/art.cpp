#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    bool done = 0;
    for(int i = 0; i + 2 < n; i++) {
      if(a[i] == a[i + 1] && a[i] == a[i + 2]) {
        done = 1;
        break;
      }
    }
    puts(done? "Yes" : "No");
  }
  return 0;
}