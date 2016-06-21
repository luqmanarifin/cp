#include <bits/stdc++.h>

using namespace std;

const int N = 32000;

bool is[N];
vector<int> prime;

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      prime.push_back(i);
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      } 
    }
  }

  int n, k;
  scanf("%d %d", &n, &k);
  int fpb = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    fpb = __gcd(fpb, num);
  }
  int ans = 0;
  for(auto it : prime) {
    if(fpb % it == 0) {
      ans = max(ans, k / it * it);
      while(fpb % it == 0) fpb /= it;
    }
  }
  if(fpb > 1) {
    ans = max(ans, k / fpb * fpb);
  }
  cout << ans << endl;
  return 0;
}
