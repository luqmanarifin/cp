#include <bits/stdc++.h>

using namespace std;

const int N = 50000;

int fact;
bool is[N];
vector<int> p;

long long get(int prime) {
  long long now = prime;
  long long ada = 0;
  while (now <= fact) {
    ada += fact / now;
    now *= prime;
  }
  return ada;
}

int main() {
  //puts("cok");
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  //puts("lala");
  
  int n;
  while (scanf("%d %d", &fact, &n) == 2) {
    //puts("cok");
    bool ok = 1;
    int ori = n;
    for (auto it : p) {
      if (!ok) break;
      if (1LL * it * it > n) break;
      if (n % it) continue;
      //printf("prime %d\n", it);
      int ada = 0;
      while (n % it == 0) {
        n /= it;
        ada++;
      }
      if (get(it) < ada) {
        ok = 0;
        break;
      }
    }
    //printf("done %d %d\n", ori, fact);
    if (ok && n > 1 && get(n) == 0) {
      ok = 0;
    }
    if (ok) {
      printf("%d divides %d!\n", ori, fact);
    } else {
      printf("%d does not divide %d!\n", ori, fact);
    }
  }

  return 0;
}
