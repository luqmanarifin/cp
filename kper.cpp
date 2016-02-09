#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];
long long fib[100];

bool changed() {
  bool done[n];
  memset(done, 0, sizeof(done));
  vector<vector<int>> num;
  for(int i = 0; i < n; i++) {
    if(!done[i]) {
      vector<int> tmp = {a[i]};
      done[i] = 1;
      int now = a[i];
      while(!done[now]) {
        done[now] = 1;
        now = a[now];
        tmp.push_back(now);
      }
      num.push_back(tmp);
    }
  }
  vector<int> ret;
  for(auto it : num) {
    sort(it.begin(), it.end());
    reverse(it.begin(), it.end());
    for(auto i : it) {
      ret.push_back(i);
    }
  }
  for(int i = 0; i < n; i++) {
    if(ret[i] != a[i]) {
      return 1;
    }
  }
  return 0;
}

void brute(long long k) {
  for(int i = 0; i < n; i++) {
    a[i] = i;
  }
  int id = 0;
  do {
    if(!changed()) {
      ++id;
      if(id == k) {
        for(int i = 0; i < n; i++) {
          printf("%d ", a[i] + 1);
        }
        printf("\n");
        return;
      }
    }
    next_permutation(a, a + n);
  } while(1);
}

int main() {
  long long k;
  scanf("%d %I64d", &n, &k);
  if(n <= 4) {
    brute(k);
    return 0;
  }
  for(int i = n - 3; i < n; i++) {
    fib[i] = 1;
  }
  for(int i = n - 4; i >= 0; i--) {
    fib[i] = fib[i + 1] + fib[i + 2];
  }
  long long now = 0, bef = 0;
  for(int i = n - 1; i >= 0; i--) {
    bef = now;
    now += fib[i];
    if(k <= now) {
      int p = i;
      for(int i = 0; i < p; i++) {
        printf("%d ", i + 1);
      }
      if(p < n - 1) {
        printf("%d %d ", p + 2, p + 1);
        p += 2;
      } else if(p == n - 1) {
        printf("%d ", p + 1);
        p++;
      }
      k -= bef;
      while(p < n) {
        if(k > fib[p - 1]) {
          k -= fib[p - 1];
          printf("%d %d ", p + 2, p + 1);
          p += 2;
        } else {
          printf("%d ", p + 1);
          p++;
        }
      }
      return 0;
    }
  }
  
  return 0;
}
