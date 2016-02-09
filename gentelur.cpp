#include <bits/stdc++.h>

using namespace std;

bool done[100000];

int main() {
  srand(time(0));
  int n = 300, m = 100;
  printf("%d %d\n", n, m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", rand() % 5000);
    }
    printf("\n");
  }
  int q = 100;
  vector<int> a;
  while(q--) {
    int at = rand() % (n * m);
    if(done[at]) continue;
    done[at] = 1;
    a.push_back(at);
  }
  cout << a.size() << endl;
  for(auto it : a) {
    printf("%d %d\n", it / m + 1, it % m + 1);
  }
  return 0;
}
