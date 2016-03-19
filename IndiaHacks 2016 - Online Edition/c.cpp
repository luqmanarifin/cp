#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], n;

bool valid(int i) {
  if(i < 1 || n < i) return 1;
  bool wrong = 0;
  if(i % 2) {
    if(i + 1 <= n && a[i] >= a[i + 1]) wrong = 1;
    if(i - 1 >= 1 && a[i - 1] <= a[i]) wrong = 1;
  } else {
    if(i + 1 <= n && a[i] <= a[i + 1]) wrong = 1;
    if(i - 1 >= 1 && a[i - 1] >= a[i]) wrong = 1;
  }
  return !wrong;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  vector<int> p;
  for(int i = 1; i <= n; i++) {
    if(!valid(i)) {
      if(i + 1 <= n) p.push_back(i + 1);
      p.push_back(i);
      if(i - 1 >= 1) p.push_back(i - 1);
    }
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  if(p.size() > 10) {
    puts("0");
    return 0;
  }
  if(n == 150000 && a[1] == 79667) {
    //for(auto it : p) printf("%d ", it); printf("\n");
    //puts("hahaha jancuk");
  }
  
  set<pair<int, int>> s;
  for(auto it : p) {
    for(int i = 1; i <= n; i++) {
      swap(a[it], a[i]);
      bool good = 1;
      good &= valid(i);
      good &= valid(i + 1);
      good &= valid(i - 1);
      good &= valid(it);
      good &= valid(it + 1);
      good &= valid(it - 1);
      for(auto j : p) {
        good &= valid(j);
        good &= valid(j + 1);
        good &= valid(j - 1);
      }
      if(good) {
        s.insert(make_pair(min(it, i), max(it, i)));
        if(n == 150000 && a[1] == 79667) {
          //printf("%d %d\n", min(it, i), max(it, i));
        }
      }
      swap(a[it], a[i]);
    }
  }
  cout << s.size() << endl;
  return 0;
}
