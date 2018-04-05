#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 4;
map<LL, bool> MAP;
map<LL, bool> WIN;

vector<int> conv_to_vec(LL X){
  vector<int> ans;
  for(int i = 0; i < 16; ++i){
    ans.push_back(int(X & 7));
    X >>= 3;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

LL conv_to_LL(const vector<int>& v){
  LL ans = 0;
  for(int i = 0;i < 16; ++i){
    ans <<= 3;
    ans += v[i];
  }
  return ans;
}

bool cek(const vector<int> &v){
  int row[4] = {0, 0, 0, 0};
  int col[4] = {0, 0, 0, 0};
  for(int i = 0;i < 16; ++i){
    row[i >> 2] += v[i];
    col[i & 3] += v[i];
  }
  for(int i = 0;i < 4; ++i) if(row[i] == 10) return true;
  for(int i = 0;i < 4; ++i) if(col[i] == 10) return true;
  return false;
}



bool precompute(LL now){
  fprintf(stderr, "MASUK %lld\n", now);
  if(MAP.count(now)) return MAP[now];
  vector<int> v = conv_to_vec(now);
  bool ans = 0;
  for(int i = 0;i < 16 && !ans; ++i){
    if(v[i] == 0){
      for(int j = 1;j <= 4 && !ans; ++j){
        v[i] = j;
        if(cek(v)){
          LL nex = conv_to_LL(v);
          MAP[nex] = 0;
          WIN[nex] = 1;
          ans = 1;
        }
        else{
          LL nex = conv_to_LL(v);
          if(MAP.count(nex)) ans |= (!MAP[nex]);
          else ans |= (!precompute(nex));
        }
      }
      v[i] = 0;
    }
  }
  MAP[now] = ans;
  return ans;
}

tuple<int,int,int> ask(int A, int B, int C){
  printf("%d %d %d\n", A, B, C);
  fflush(stdout);
  int AA, BB, CC;
  scanf("%d%d%d", &AA, &BB, &CC);
  tuple<int,int,int> res = make_tuple(AA, BB, CC);
  return res;
}

void answer(int A, int B, int C){
  printf("%d %d %d WIN\n", A, B, C);
  fflush(stdout);
  exit(0);
}

int main(){
  vector<int> init(16, 0);
  int xAwal, yAwal, cAwal;
  scanf("%d%d%d", &xAwal, &yAwal, &cAwal);
  init[((xAwal - 1) << 2) + (yAwal - 1)] = cAwal;
  LL awal = conv_to_LL(init);
  precompute(awal);
  LL now = awal;
  assert(MAP[now] == 1);
  while(1){
    vector<int> v = conv_to_vec(now);
    bool ketemu = false;
    for(int i = 0;i < 16 && !ketemu; ++i){
      if(v[i] == 0){
        for(int j = 1; j <= 4 && !ketemu; ++j){
          v[i] = j;
          LL nex = conv_to_LL(v);
          if(!MAP.count(nex)) continue;
          if(MAP[nex] == 0){
            if(WIN.count(nex)){
              answer((i >> 2) + 1, (i & 3) + 1, j);
            }
            else{
              tuple<int,int,int> ans = ask((i >> 2) + 1, (i & 3) + 1, j);
              int X, Y, C;
              tie(X, Y, C) = ans;
              v[((X - 1) << 2) + (Y - 1)] = C;
              now = conv_to_LL(v);
              ketemu = true;
            }
          }
          v[i] = 0;
        }
      }
    }
  }
  return 0;
}
