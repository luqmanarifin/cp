#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> p[N];

bool intra(pair<int, int> big, pair<int, int> sm) {
  return big.first <= sm.first && sm.second <= big.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  int ptr = 0, seg = p[0].second - p[0].first;
  for(int i = 1; i < n; i++) {
    int cur = p[i].second - p[i].first;
    if(cur > seg) {
      seg = cur;
      ptr = i;
    }
  }
  for(int i = 0; i < n; i++) {
    if(!intra(p[ptr], p[i])) {
      puts("-1");
      return 0;
    }
  }
  cout << ptr + 1 << endl;
  return 0;
}
