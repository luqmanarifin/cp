#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
const int lim = 1e9;

int ans[N];
vector<int> num[N];
vector<int> at[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  k = min(k, n);
  for(int i = 0; i < n; i++) {
    char s[100];
    scanf("%s", s);
    ans[i] = (s[0] == '?'? inf : atoi(s));
    num[i % k].push_back(ans[i]);
    at[i % k].push_back(i);
  }
  for(int i = 0; i < k; i++) {
    int bef = -inf;
    for(auto it : num[i]) {
      if(it == inf) bef++;
      else if(bef <= it) bef = it + 1;
      else {
        puts("Incorrect sequence");
        return 0;
      }
    }
  }
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < num[i].size(); j++) {
      int pt = j;
      while(num[i][pt] == inf && pt < num[i].size()) pt++;
      int pol = (pt == num[i].size()? inf : num[i][pt]);
      int pil = (j == 0? -inf : num[i][j - 1] + 1);
      int cnt = pt - j;
      int start = (-cnt / 2);
      start = max(start, pil);
      start = min(start, pol - cnt);
      for(; j < pt; j++, start++) {
        num[i][j] = start;
        ans[at[i][j]] = start;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}