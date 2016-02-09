#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
vector<int> ans;

int main() {
  int n;
  char s[20];
  scanf("%d %s", &n, s);
  for(int i = 0; i < n; i++) {
    pq.push(s[i] - '0');
  }
  while(!pq.empty()) {
    int num = pq.top();
    pq.pop();
    switch(num) {
      case 9 : pq.push(3); pq.push(3); pq.push(2); pq.push(7);
        break;
      case 8 : pq.push(2); pq.push(2); pq.push(2); pq.push(7);
        break;
      case 6 : pq.push(3); pq.push(5);
        break;
      case 4 : pq.push(2); pq.push(2); pq.push(3);
        break;
    }
    if(num == 9 || num == 8 || num == 6 || num == 4) {
      continue;
    }
    ans.push_back(num);
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for(auto it : ans) {
    if(it < 2) break;
    printf("%d", it);
  }
  printf("\n");
  return 0;
}