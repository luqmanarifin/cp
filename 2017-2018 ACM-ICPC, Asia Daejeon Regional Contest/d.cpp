#include <bits/stdc++.h>
using namespace std;
map<int,bool> MAP;
int process(int x){
  int ans = 0;
  int tmpx = x;
  while(tmpx){
    int mods = tmpx % 10;
    tmpx /= 10;
    ans += mods * mods;
  }
  return ans;
}
int main(){
  int n;
  scanf("%d", &n);
  int now = n;
  while(now != 1 && !MAP.count(now)){
    MAP[now] = 1;
    now = process(now);
  }
  puts(now == 1 ? "HAPPY" : "UNHAPPY");
  return 0;
}