#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

vector<int> p;
int is[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      p.push_back(i);
      for(long long j = 1LL * i * i; j < N; j += i) {
        if(!is[j]) {
          is[j] = i;
        }
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    while(is[n]) {
      ans++;
      n /= is[n];
    }
    if(n != 1) ans++;
    puts(ans == k? "Ya" : "Tidak");
  }
  
  return 0;
}
