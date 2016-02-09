#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool done[N];

int solve(vector<int> opp, vector<int> me) {
  set<int> ada;
  for(auto it : me) {
    //cout << "me " << it << endl;
    ada.insert(it);
  }
  int ret = 0;
  for(auto it : opp) {
    //cout << "opp " << it << endl;
    auto iter = ada.lower_bound(it);
    if(iter == ada.end()) {
      ada.erase(ada.begin());
    } else {
      ret++;
      ada.erase(iter);
    }
  }
  return ret;
}

int main() {
  freopen("cardgame.in","r",stdin);
  freopen("cardgame.out","w",stdout);
  
  int n;
  scanf("%d", &n);
  vector<int> a, b;
  for(int i = 0; i < n; i++) {
    int u;
    scanf("%d", &u);
    done[u] = 1;
    if(i < n / 2) {
      a.push_back(u);
    } else {
      b.push_back(u);
    }
  }
  vector<int> lom;
  for(int i = 1; i <= 2 * n; i++) {
    if(!done[i]) {
      lom.push_back(i);
    }
  }
  sort(lom.begin(), lom.end());
  reverse(lom.begin(), lom.end());
  vector<int> mea, meb;
  for(int i = 0; i < n; i++) {
    if(i < n / 2) {
      mea.push_back(lom[i]);
    } else {
      meb.push_back(lom[i]);
    }
  }
  for(auto& it : b) it = -it;
  for(auto& it : meb) it = -it;
  cout << solve(a, mea) + solve(b, meb) << endl;
  return 0;
}
