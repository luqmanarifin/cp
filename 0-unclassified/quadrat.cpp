#include <bits/stdc++.h>

using namespace std;

const int pol = 1e9 + 5;

long long dua(long long a) {
  return a * a;
}

long long tiga(long long a) {
  return dua(a) * a;
}

long long empat(long long a) {
  return tiga(a) * a;
}

vector<int> sq;

int root(int a) {
  int temp = (int) sqrt(a);
  if((temp + 1) * (temp + 1) <= a) return temp + 1;
  return temp;
}

int main() {
  for(int i = 0; dua(i) < pol; i++) {
    sq.push_back(dua(i));
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(long long d = 0; ; d++) {
      long long ed = empat(d);
      if(ed > n) break;
      n -= ed;
      
      
      for(long long c = 0; ; c++) {
        long long tc = tiga(c);
        if(tc > n) break;
        n -= tc;
        ans += root(n) + 1;
        n += tc;
      }
      
      
      n += ed;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
