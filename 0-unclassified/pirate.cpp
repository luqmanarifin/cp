#include <bits/stdc++.h>

using namespace std;

const int pol = 1000000;

int a[5005];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int d = 1; d <= pol; d++) {
    vector<bool> done;
    done.resize(d);
    int t = 0;
    for(int i = 0; i < n; i++) {
      if(done[a[i] % d]) { 
        t++;
      } else {
        done[a[i] % d] = 1;
      }
    }
    if(d == 8) {
      printf("AMPAS %d\n", t);
    }
    if(t <= k) {
      cout << d << endl;
      return 0;
    }
  }
  
  return 0;
}