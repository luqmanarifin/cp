#include <bits/stdc++.h>

using namespace std;

char s[22];

string toString(int num) {
  stringstream ss;
  ss << num;
  return ss.str();
}

int main() {
  for(int tt = 1; tt <= 5; tt++) {
    string in = "osn-2016-matriks-biner_" + toString(tt) + "_1.in";
    string out = "osn-2016-matriks-biner_" + toString(tt) + "_1.out";
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
    
    int n, m;
    scanf("%s %d %d", s, &n, &m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int num;
        scanf("%d", &num);
        if(j) printf(" ");
        printf("0");
      }
      printf("\n");
    }
    
    fclose(stdin);
    fclose(stdout);
  }
  
  return 0;
}