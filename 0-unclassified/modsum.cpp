#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool done[N];
int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    vector<int> num;
    for(int j = 0; j < m; j++) {
      if(done[j]) {
        int at = (j + a[i]) % m;
        if(!done[at]) {
          num.push_back(at);
        }
      }
    }
    done[a[i] % m] = 1;
    for(auto it : num) {
      done[it] = 1;
    }
    if(done[0]) {
      puts("YES");
      return 0;
    }
  }
  if(done[0]) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
