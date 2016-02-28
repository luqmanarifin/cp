#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> p;
int x[N], y[N];
vector<int> ada[N];

int id(int a) {
  return lower_bound(p.begin(), p.end(), a) - p.begin();
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    p.push_back(x[i]);
    p.push_back(y[i]);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  for(int i = 0; i < n; i++) {
    ada[id(x[i])].push_back(id(y[i]));
  }
  int ans = 0;
  multiset<int> e;
  for(int i = 0; i < p.size(); i++) {
    while(!e.empty() && *(e.begin()) == i) {
      auto it = e.begin();
      e.erase(it);
    }
    for(auto it : ada[i]) {
      if(e.size() < k) {
        e.insert(it);
        ans++;
      } else {
        e.insert(it);
        auto qon = e.end();
        qon--;
        e.erase(qon);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
