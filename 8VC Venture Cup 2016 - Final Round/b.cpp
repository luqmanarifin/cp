#include <bits/stdc++.h>

using namespace std;

void normalize(deque<int>& a){
  while(a.front() != 1) {
    int num = a.front();
    a.pop_front();
    a.push_back(num);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  deque<int> a, b;
  for(int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    if(e) a.push_back(e);
  }
  for(int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    if(e) b.push_back(e);
  }
  normalize(a);
  normalize(b);
  //for(auto it : a) printf("%d ", it); printf("\n");
  //for(auto it : b) printf("%d ", it); printf("\n");
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
