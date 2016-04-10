#include <bits/stdc++.h>

using namespace std;

bool done[10];
int cnt;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    cerr << "working on " << tt << endl;
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", tt);
    cnt = 0;
    memset(done, 0, sizeof(done));
    if(n == 0) {
      puts("INSOMNIA");
      continue;
    }
    long long ans = 0;
    for(int i = n; cnt < 10; i += n) {
      ans++;
      int num = i;
      while(num) {
        int c = num % 10;
        if(!done[c]) {
          done[c] = 1;
          cnt++;
        }
        num /= 10;
      }
    }
    printf("%I64d\n", ans * n);
  }
  return 0;
}