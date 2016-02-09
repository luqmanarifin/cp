#include <bits/stdc++.h>

using namespace std;

int main() {
  int mh, mw, th, tw;
  scanf("%d %d %d %d", &mh, &mw, &th, &tw);
  int ans = 0;
  for(int i = 1; i <= 1000; i++) {
    int j = i + 1;
    if(th % j == 0 && th / j <= mh) {
      if(tw % i == 0 && tw / i >= mw) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
