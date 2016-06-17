#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

bool is[N];
int a[N];
vector<int> pi[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for(int i = 1; i < N; i++) {
    pi[i].push_back(1);
  }
  for(int i = 2; i < N; i++) {
    if(is[i]) continue;
    int now = i;
    while(now < N) {
      for(int j = now; j < N; j++) {
        pi[j].push_back(now);
      }
      now *= i;
    }
  }
  for(int i = 1; i < N; i++) {
    set<int> s;
    for(auto it : pi[i]) {
      s.insert(a[i - it]);
    }
    bool done = 0;
    for(int j = 0; j < N; j++) {
      if(!s.count(j)) {
        a[i] = j;
        done = 1;
        break;
      }
    }
    assert(done);
  }
  for(int i = 1; i < N; i++) {
    if(!a[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}