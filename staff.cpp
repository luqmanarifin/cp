#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
int ada[N];

vector<int> ans;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  ada[1] = k;
  ada[1 + n] = -k;
  ans.resize(k, 1);
  for(int i = 1; i < n + m + 1; i++) {
    if(ada[i] < k) {
      int add = k - ada[i];
      ada[i] += add;
      ada[i + n] += -add;
      while(add--) {
        ans.push_back(i);
      }
    }
    ada[i + 1] += ada[i];
    if(ada[i + 1] == 0) {
      ada[i + 1]++;
      ada[i + n]--;
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for(auto it : ans) {
    printf("%d ", it);
  }
  printf("\n");
  return 0;
}