#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ca[26], cb[26];
char a[N], b[N];
int cnt[26];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%s %s", a, b);
  int n = strlen(a);
  for(int i = 0; i < n; i++) {
    a[i] -= 'A';
    b[i] -= 'A';
    ca[a[i]]++;
    cb[b[i]]++;
  }
  int let = 0;
  for(int i = 0; i < n; i++) {
    if(ca[a[i]] > cb[a[i]]) {
      bool done = 0;
      for(int j = 0; j < a[i]; j++) {
        if(ca[j] < cb[j]) {
          let++;
          ca[a[i]]--;
          ca[j]++;
          a[i] = j;
          done = 1;
          break;
        }
      }
      if(!done) {
        if(cnt[a[i]] != cb[a[i]]) {
          cnt[a[i]]++;
          continue;
        }
        for(int j = a[i] + 1; j < 26; j++) {
          if(ca[j] < cb[j]) {
            let++;
            ca[a[i]]--;
            ca[j]++;
            a[i] = j;
            break;
          }
        }
      }
    }
    cnt[a[i]]++;
  }
  cout << let << endl;
  for(int i = 0; i < n; i++) {
    printf("%c", a[i] + 'A');
  }
  printf("\n");
  return 0;
}