#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int main(){
  freopen("binary.out", "r", stdin);
  freopen("angka.txt", "w", stdout);
  printf("{");
  for(int i = 1;i <= N; ++i){
    string s;
    cin >> s;
    cout << "\"" << s << "\"";
    if(i == N) printf("}\n");
    else printf(",");
  }
  return 0;
}