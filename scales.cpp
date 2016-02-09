#include <bits/stdc++.h>

using namespace std;

vector<long long> num;
vector<vector<int>> pem;

bool ada(long long a) {
  return binary_search(num.begin(), num.end(), a);
}

bool intersect(vector<int>& a, vector<int>& b) {
  for(auto it : a) {
    int id = lower_bound(b.begin(), b.end(), it) - b.begin();
    if(id < b.size() && b[id] == it) {
      return 1;
    }
  }
  return 0;
}

int main() {
  long long base, m;
  scanf("%I64d %I64d", &base, &m);
  long long pol = 1e10;
  if(base <= 3) {
    puts("YES");
    return 0;
  }
  num.push_back(0);
  vector<int> anjing;
  pem.push_back(anjing);
  long long now = 1; int c = 0;
  while(now <= pol) {
    vector<long long> tmp;
    vector<vector<int>> tp;
    for(int i = 0; i < num.size(); i++) {
      if(!ada(num[i] + now) && num[i] + now <= pol) {
        tmp.push_back(num[i] + now);
        vector<int> t = pem[i];
        t.push_back(c);
        tp.push_back(t);
      }
    }
    for(auto it : tmp) {
      num.push_back(it);
    }
    for(auto it : tp) {
      pem.push_back(it);
    }
    now *= base;
    c++;
  }
  if(ada(m)) {
    puts("YES");
    return 0;
  }
  for(int i = 1; i < num.size(); i++) {
    int id = lower_bound(num.begin(), num.end(), num[i] + m) - num.begin();
    if(id < num.size() && num[id] == num[i] + m) {
      vector<int> a = pem[i];
      vector<int> b = pem[id];
      if(!intersect(a, b)) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
