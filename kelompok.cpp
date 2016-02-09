#include <bits/stdc++.h>

using namespace std;

vector<int> neg, zero, pos;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num < 0) {
      neg.push_back(num);
    } else if(num == 0) {
      zero.push_back(num);
    } else {
      pos.push_back(num);
    }
  }
  for(auto it : neg) printf("%d\n", it);
  for(auto it : zero) printf("%d\n", it);
  for(auto it : pos) printf("%d\n", it);
  return 0;
}
