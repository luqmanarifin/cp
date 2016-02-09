#include <bits/stdc++.h>

using namespace std;

long long a, d;
bool done[10];

long long digit(long long num) {
  long long ret = 0;
  while(num) {
    ret += num % 10;
    num /= 10;
  }
  if(ret < 10) return ret;
  return digit(ret);
}

long long get(long long n) {
  memset(done, 0, sizeof(done));
  long long now = digit(a);
  now--;
  long long ans = n;
  d = d % 9;
  
  vector<long long> num;
  long long size = 0, sum = 0;
  while(!done[now]) {
    num.push_back(now);
    done[now] = 1;
    sum += now;
    
    now = (now + d) % 9;
    size++;
  }
  long long kali = n / size;
  ans += kali * sum;
  for(long long i = 0; i < n % size; i++) {
    ans += num[i];
  }
  return ans;
}

int main() {
  long long t;
  scanf("%lld", &t);
  while(t--) {
    //puts("JANCOK");
    long long l, r;
    scanf("%lld %lld %lld %lld", &a, &d, &l, &r);
    printf("%lld\n", get(r) - get(l - 1));
  }
  return 0;
}
