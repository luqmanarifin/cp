#include <bits/stdc++.h>

using namespace std;

const long long prime = (1 << 7) - 1;
const long long mod = 15616516515631LL;
const int N = 6e5 + 5;

set<long long> ada;
long long power[N];
char s[N];

void norm(long long &a) {
  a %= mod;
  if(a < 0) a += mod;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  power[0] = 1;
  for(int i = 1; i < N; i++) {
    power[i] = power[i - 1] * prime;
    norm(power[i]);
  }
  while(n--) {
    scanf("%s", s);
    int len = strlen(s);
    long long key = 0;
    for(int i = 0; i < len; i++) {
      key = key * prime + s[i] - 'a' + 1;
      norm(key);
    }
    for(int i = 0; i < len; i++) {
      long long will = key - (s[i] - 'a' + 1) * power[len - i - 1];
      norm(will);
      for(int j = 0; j < 3; j++) {
        if(j + 'a' != s[i]) {
          long long temp = will + (j + 1) * power[len - i - 1];
          norm(temp);
          ada.insert(temp);
        }
      }
    }
  }
  while(m--) {
    scanf("%s", s);
    long long key = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
      key = key * prime + s[i] - 'a' + 1;
      norm(key);
    }
    if(ada.count(key)) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  
  return 0;
}