#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

string s[N];
int til[N];

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    til[i] = s[i].size();
    //cout << s[i] << endl;
  }
  for (int i = n - 1; i >= 1; i--) {
    int len = min(til[i-1], til[i]); 
    //printf("%d %d\n", i, len);
    bool same = 1;
    for (int j = 0; j < len; j++) {
      //printf("%c %c\n", s[i-1][j], s[i][j]);
      if (s[i-1][j] > s[i][j]) {
        til[i-1] = min(til[i-1], j);
        same = 0;
        break;
      } else if (s[i-1][j] < s[i][j]) {
        same = 0;
        break;
      }
    }
    if (same) {
      til[i-1] = min(til[i-1], til[i]);
    }
    //printf("\n");
  }
  //for (int i = 0; i < n; i++) printf("%d ", til[i]); printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < til[i]; j++) printf("%c", s[i][j]);
    printf("\n");
  }
  
  return 0;
}