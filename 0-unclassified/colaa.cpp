#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17);
const int mod = 1e9 + 7;

int ori[N], dua[N];
long long cnt[N];

int main() {
  dua[0] = 1;
  for(int i = 1; i < N; i++) dua[i] = dua[i - 1] * 2 % mod;
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ori[a]++;
  }
  long long ans = 0;
  cnt[0] = 1;
  for(int i = 1; i < N; i++) {
    int all = 0;
    long long del = cnt[0];
    for(int j = i; j > 0; j = (j - 1) & i) {
      all += ori[j];
      del += cnt[j];
    }
    cnt[i] = (dua[all] - del) % mod;
    if(cnt[i] < 0) cnt[i] += mod;
    
    long long add = 1LL * i * i * i % mod;
    add = add * cnt[i] % mod;
    ans += add;
  }
  cout << ans % mod << endl;
  return 0;
}
