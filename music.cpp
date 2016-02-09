#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> dapet[N];
int a;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    for(int j = k; j >= a; j--) {
      if(dapet[j - a].size() + 1 > dapet[j].size()) {
        dapet[j] = dapet[j - a];
        dapet[j].push_back(i + 1);
      }
    }
  }
  cout << dapet[k].size() << endl;
  for(auto it : dapet[k]) printf("%d ", it);
  printf("\n");
  return 0;
}