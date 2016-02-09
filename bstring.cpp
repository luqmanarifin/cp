#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d %s", &n, &k, &s[1]);
    if(k == 1) {
    
      int temp[] = {0, 0};
      for(int i = 1; i <= n; i++) {
        temp[i % 2 == s[i] - '0']++;
      }
      int id = (temp[0] > temp[1]);
      printf("%d\n", temp[id]);
      for(int i = 0; i < n; i++) {
        if(id) printf("%d", i % 2);
        else printf("%d", (i % 2) ^ 1);
      }
      
    } else {
      
      vector<int> cnt;
      int start = s[1] - '0';
      cnt.push_back(1);
      for(int i = 2; i <= n; i++) {
        if(s[i] == s[i - 1]) cnt.back()++;
        else cnt.push_back(1);
      }
      vector<int> anyar;
      int ans = 0; k++;
      for(auto it : cnt) {
        int cuk = it / k - (it % k == 0);
        for(int i = 0; i < cuk; i++) {
          anyar.push_back(k - 1);
          anyar.push_back(1);
          ans++;
        }
        if(it % k) {
          anyar.push_back(it % k);
        } else {
          anyar.push_back(k - 2);
          anyar.push_back(1);
          anyar.push_back(1);
          ans++;
        }
      }
      printf("%d\n", ans);
      for(auto it : anyar) {
        for(int i = 0; i < it; i++) {
          printf("%d", start);
        }
        start ^= 1;
      }
      
    }
    printf("\n");
  }
  
  return 0;
}
