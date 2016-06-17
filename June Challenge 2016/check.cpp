#include <bits/stdc++.h>

using namespace std;

const int N = 32000;

bool is[N];
vector<int> p, pi[N];
int a[N];

bool isChef(int n) {
  bool print = n == 409;
  
  int fact = 0;
  for(auto it : p) if(n % it == 0) {
    fact++;
    while(n % it == 0) n /= it;
  }
  if(n > 1) fact++;
  if(print) printf("fact %d\n", fact);
  return fact <= 1;
}

bool correct(int n) {
  return !!a[n];
}

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
      p.push_back(i);
    }
  }
  /*
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
      s.insert(a[it]);
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
    if(isChef(i) != correct(i)) {
      printf("%d nimnya %d\n", i, a[i]);
    }
    assert(isChef(i) == correct(i));
  }
  */
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    puts(isChef(n)? "Chef" : "Misha");
  }
  
  return 0;
}