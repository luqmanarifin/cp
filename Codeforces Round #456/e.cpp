#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int MAGIC = 15;
const long long inf = 2e18;
const int MASK = 5e6;

int a[N], n, now;
int prime[MASK];
long long d[MASK], good[50][50];
long long c[50][50];
int to[1 << 25];

bool is[105];
int in[105];
vector<int> p;
int num[105];

long long get(long long t) {
  long long ada = 0;
  for (int i = 0; i < now; i++) {
    long long add = t / prime[i];
    ada += d[i] * add;
  }
  return ada;
}

int main() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || i == j) c[i][j] = 1;
      else c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  memset(to, -1, sizeof(to));
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), in[a[i]] = 1;
  
  // sieve standard
  for (int i = 2; i <= 100; i++) {
    if (!is[i]) {
      num[i] = p.size();
      p.push_back(i);
      for (int j = i * i; j <= 100; j += i) is[j] = 1;
    }
  }
  
  // generate prime
  prime[now] = d[now] = 1;
  to[0] = now++;
  for (int mask = 1; mask < (1 << p.size()); mask++) {
    int g = __builtin_clz(mask) ^ 31;
    int bef = (mask ^ (1 << g));
    //printf("mask %d g %d bef %d\n", mask, g, bef);
    if (to[bef] == -1) continue;
    long long lim = inf / prime[to[bef]];
    if (lim < p[g]) continue;
    to[mask] = now++;
    prime[to[mask]] = prime[to[bef]] * p[g];
  }
  //cout << "now " << now << endl;
  //cout << "prime size " << prime.size() << endl; 
  //puts("fuck you prime done");
  
    
  // generate good
  good[0][0] = 1;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (i == 0 && j == 0) continue;
      long long all = 0;
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
          all += c[i][k] * c[j][l] * good[k][l];
        }
      }
      if (j) {
        good[i][j] = -all;
      } else {
        good[i][j] = 1 - all;
      }
      //printf("good %d %d: %d\n", i, j, good[i][j]);
    }
  }    
  
  // generate d
  for (int mask = 0; mask < (1 << p.size()); mask++) {
    if (to[mask] == -1) continue;
    int g = 0, b = 0;
    for (int i = 0; i < p.size(); i++) {
      if (mask & (1 << i)) {
        if (in[p[i]]) {
          g++;
        } else {
          b++;
        }
      }
    }
    d[to[mask]] = good[g][b];
  }
  
  //puts("fuck you d done");
  
  //cout << get(7) << endl;
  
  long long k;
  scanf("%I64d", &k);
  long long l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (get(mid) < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
