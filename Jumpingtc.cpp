#include <bits/stdc++.h>

using namespace std;

class Jumping {
  int dist(int a, int b, int c, int d) {
    return (a - c)*(a - c) + (b - d)*(b - d);
  }
  string ableToGet (int gx, int gy, vector<int> jump) {
    for(int i = 0; i < jump.size(); i++) {
      jump[i] *= jump[i];
    }
    for(int i = 1; i <= 1000; i++) {
      for(int j = 0; j <= 1000; j++) {
        int ret = i*i - j*j;
        int l = 0, r = 1000;
        while(l < r) {
          int mid = (l + r) >> 1;
          if(mid * mid < ret) l = mid + 1;
          else r = mid;
        }
        if(l*l == ret) move[i].push_back(make_pair(j, l));
      }
    }
    queue< pair< pair<int,int>, int> > q;
    q.push(make_pair(make_pair(1000, 1000), 0));
    while(!q.empty()) {
      int px = q.first.first;
      int py = q.first.second;
      int ke = q.second;
      if(ke == jump.size()) break;
      if(px == gx && py == gy) return "Able";
      for(int i = 0; i < move[jump[ke]].size(); i++) {
        pair<int,int> mv = move[jump[ke]][i];
        if()
        q.push(make_pair(make_pair(1000 + px + mv.first, 1000 + py + mv.second), ke + 1));
      }
    }
    if(done[gx + 1000][gy + 1000]) return "Able";
    else return "Not able";
  }
  bool done[2005][2005];
  vector< pair<int, int> > move[1005];
  const int lim = 2000;
};