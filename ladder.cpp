#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> seg;
int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int bef = -1;
  for(int i = 0; i < n; i++) {
    int j = i;
    while(a[j + 1] == a[j]) {
      j++;
    }
    if(bef > a[j] && a[j] < a[j + 1]) {
      seg.emplace_back(i, j);
    }
    i = j;
    bef = a[i];
  }
  sort(seg.begin(), seg.end());
  /*
  for(auto it : seg) {
    puts("JANCOK");
    printf("%d %d\n", it.first, it.second);
  }
  */
  while(m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int id = upper_bound(seg.begin(), seg.end(), make_pair(l, N)) - seg.begin();
    if(id < seg.size() && seg[id].second < r) {
      puts("No");
    } else {
      puts("Yes");
    }
  }
  
  return 0;
}
