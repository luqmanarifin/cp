#include <bits/stdc++.h>

using namespace std;

int find(long long a) {
  if(a <= 0) return 0;
  if(a <= 1) return 1;
  if(a <= 3) return 2;
  if(a <= 5) return 3;
  long long bef = 6;
  while(bef * 12 <= a) bef *= 12;
  int t = (a - bef) / bef;
  if(t <= 0) return 0;
  if(t <= 2) return 1;
  if(t <= 6) return 2;
  if(t <= 10) return 3;
  assert(0);
}

const int N = 1e5 + 5;

int nim[N];

int main() {
  /*
  for(int i = 1; i < N; i++) {
    set<int> s;
    for(int j = 2; j <= 6; j++) {
      s.insert(nim[i / j]);
    }
    for(int j = 0; j <= 10; j++) {
      if(!s.count(j)) {
        nim[i] = j;
        printf("%d: %d, harusnya %d\n", i, find(i), nim[i]);
        assert(nim[i] == find(i));
        break;
      }
    }
  }
  */
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      long long num;
      scanf("%lld", &num);
      ans ^= find(num);
    }
    puts(ans? "Henry" : "Derek");
  }
  
  return 0;
}