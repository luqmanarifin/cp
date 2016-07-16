#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

long long b[N], a[N];
bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(b, 0, sizeof(b));
    memset(a, 0, sizeof(a));
    memset(done, 0, sizeof(done));
    
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%lld", b + i);
      sum += b[i];
    }
    for(int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      sum += a[i];
    }
    if(sum % n) {
      puts("-1");
      continue;
    }
    long long goal = sum / n;
    for(int i = 1; i <= n; i++) {
      bool ada = 0;
      for(int mask = (1 << 3) - 1; mask >= 0; mask--) {
        int sum = 0;
        bool valid = 1;
        for(int j = 0; j < 3; j++) {
          if(mask & (1 << j)) {
            if(done[i + 1 - j]) {
              valid = 0;
            }
            sum += b[i + 1 - j];
          }
        }
        if(valid && a[i] + sum == goal) {
          ada = 1;
          for(int j = 0; j < 3; j++) {
            if(mask & (1 << j)) {
              done[i + 1 - j] = 1;
            }
          }
          break;
        }
      }
      if(!ada) {
        puts("-1");
        goto LANJUT;
      }
    }
    for(int i = 1; i <= n; i++) {
      if(!done[i]) {
        puts("-1");
        goto LANJUT;
      }
    }
    cout << goal << endl;
    LANJUT:;
  }

  return 0;
}
