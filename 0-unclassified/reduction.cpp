#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAXP = 1e4;

bool is[N], done[MAXP];
int id[N], c[N][105], n, m;
vector<int> p;

int getmax(int* a, int len) {
  int sum = 0;
  for(int i = 0; i < len; i++) {
    sum += a[i];
  }
  return min(sum - a[len - 1], sum / 2);
}

int getmin(int at) {
  int head = 0;
  for(int i = 0; i < n - 1; i++) {
    head += c[at][i];
  }
  return head - getmax(c[at], n - 1);
}

int main() {
  int cur = 0;
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
      id[i] = cur++;
      p.push_back(i);
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    memset(c, 0, sizeof(c));
    memset(done, 0, sizeof(done));
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int num;
        scanf("%d", &num);
        for(int k = 0; k < p.size() && 1LL*p[k]*p[k] <= num; k++) {
          while(num % p[k] == 0) {
            done[k] = 1;
            c[k][i]++;
            num /= p[k];
          }
        }
        if(num > 1) {
          done[id[num]] = 1;
          c[id[num]][i]++;
        }
      }
    }
    int mn = 0, mx = 0;
    for(int i = 0; i < MAXP; i++) {
      if(done[i]) {
        sort(c[i], c[i] + n);
        mn += getmin(i);
        mx += getmax(c[i], n);
      }
    }
    printf("Case #%d: %d %d\n", tt, mn, mx);
  }
  
  return 0;
}
