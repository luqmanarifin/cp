#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 5;

vector<long long> p;

int main() {
  long long now = 1;
  while(1) {
    p.push_back(now);
    now = now * 2 + 1;
    if(now > N) break;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    int at = lower_bound(p.begin(), p.end(), n) - p.begin();
    printf("%d\n", at + 1);
  }
  return 0;
}
