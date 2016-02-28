#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, bool> done;

deque<int> a, b;

pair<long long, long long> get() {
  long long f = 0;
  for(auto it : a) {
    f = f * 11 + it;
  }
  long long g = 0;
  for(auto it : b) {
    g = g * 11 + it;
  }
  return make_pair(f, g);
} 

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int num;
    scanf("%d", &num);
    b.push_back(num);
  }
  for(int i = 0; ; i++) {
    pair<long long, long long> id = get();
    if(done[id]) {
      puts("-1");
      return 0;
    }
    done[id] = 1;
    if(a.empty()) {
      printf("%d 2\n", i);
      return 0;
    }
    if(b.empty()) {
      printf("%d 1\n", i);
      return 0;
    }
    int aa = a.front();
    int bb = b.front();
    a.pop_front();
    b.pop_front();
    if(aa > bb) {
      a.push_back(bb);
      a.push_back(aa);
    } else {
      b.push_back(aa);
      b.push_back(bb);
    }
  }
  
  return 0;
}
