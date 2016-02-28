#include <bits/stdc++.h>

using namespace std;

char s[2000];
char good[26];

long long p[2000][3];
long long power[2000][3];
long long prime[] = {31, 13331, 71};
long long mod[] = {(long long)1e9 + 7, (long long)1e9 + 13, (long long)1e9 + 9};

int main() {
  int k;
  scanf("%s %s %d", s + 1, good, &k);
  int n = strlen(s + 1);
  
  for(int j = 0; j < 3; j++) {
    power[0][j] = 1;
  }
  for(int i = 1; i < 2000; i++) {
    for(int j = 0; j < 3; j++) {
      power[i][j] = power[i - 1][j] * prime[j] % mod[j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      p[i][j] = p[i - 1][j] * prime[j] + s[i] - 'a' + 1;
      p[i][j] %= mod[j];
    }
  }
  
  set<tuple<long long, long long, long long>> st;
  
  for(int i = 1; i <= n; i++) {
    int bad = 0;
    for(int j = i; j <= n; j++) {
      if(good[s[j] - 'a'] == '0') {
        bad++;
      }
      if(bad > k) {
        break;
      }
      long long val[3];
      for(int it = 0; it < 3; it++) {
        val[it] = p[j][it] - p[i - 1][it] * power[j - i + 1][it];
        val[it] %= mod[it]; if(val[it] < 0) val[it] += mod[it];
      }
      st.insert(make_tuple(val[0], val[1], val[2]));
    }
  }
  cout << st.size() << endl;
  return 0;
}
