#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int pol = 1e7 + 5;

bitset<pol> is;
vector<int> prime;

vector<int> ada, adb;
vector<int> dela, delb;
vector<pair<int, int>> na[N], nb[N];
int a[N], b[N];

int id(int num) {
  return lower_bound(prime.begin(), prime.end(), num) - prime.begin();
}

int main() {
  for(int i = 2; i < pol; i++) {
    if(!is[i]) {
      prime.push_back(i);
      for(long long j = 1LL*i*i; j < pol; j += i) {
        is[j] = 1;
      }
    }
  }
  ada.resize(prime.size(), 0);
  adb.resize(prime.size(), 0);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    int num = a[i];
    for(int j = 0; prime[j]*prime[j] <= num; j++) {
      int p = 0;
      while(num % prime[j] == 0) {
        p++;
        num /= prime[j];
      }
      if(p) {
        ada[j] += p;
        na[i].emplace_back(j, p);
      }
    }
    if(num != 1) {
      ada[id(num)]++;
      na[i].emplace_back(id(num), 1);
    }
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", b + i);
    int num = b[i];
    for(int j = 0; prime[j]*prime[j] <= num; j++) {
      int p = 0;
      while(num % prime[j] == 0) {
        p++;
        num /= prime[j];
      }
      if(p) {
        adb[j] += p;
        nb[i].emplace_back(j, p);
      }
    }
    if(num != 1) {
      adb[id(num)]++;
      nb[i].emplace_back(id(num), 1);
    } 
  }
  
  dela.resize(prime.size(), 0);
  delb.resize(prime.size(), 0);
  
  for(int i = 0; i < prime.size(); i++) {
    dela[i] = min(ada[i], adb[i]);
    delb[i] = min(ada[i], adb[i]);
  }
  for(int i = 0; i < n; i++) {
    for(auto it : na[i]) {
      int id = it.first;
      int del = min(dela[id], it.second);
      dela[id] -= del;
      while(del--) a[i] /= prime[id];
    }
  }
  
  for(int i = 0; i < m; i++) {
    for(auto it : nb[i]) {
      int id = it.first;
      int del = min(delb[id], it.second);
      delb[id] -= del;
      while(del--) b[i] /= prime[id];
    }
  }
  printf("%d %d\n", n, m);
  for(int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  for(int i = 0; i < m; i++) printf("%d ", b[i]); printf("\n");
  
  return 0;
}