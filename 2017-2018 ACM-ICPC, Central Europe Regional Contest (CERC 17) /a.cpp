#include <bits/stdc++.h>

using namespace std;
const int R = 50, C = 11;

char ar[R + 5][C + 5];
int r, n;
int cnt[R + 5];

int jarak(int x){
  int minjarak = x;
  minjarak = min(minjarak, abs(x - (r / 2 + 1)));
  minjarak = min(minjarak, abs(x - (r + 2)));
  return minjarak;
}

int cntleft = 0;
int cntright = 0;

char avail = '-';

int main() {
  scanf("%d%d", &r, &n);
  for(int i = 0;i < r + 3;i++) {
    scanf("%s", ar[i]);
    if((i == 0) || (i == (r / 2) + 1) || (i == r + 2)) continue;
    for(int j = 0;j < C; ++j) {
      if(ar[i][j] == avail) cnt[i]++;
      else if(ar[i][j] == '#') {
        if(j <= 4) cntleft++;
        else if(j >= 6) cntright++;
      }
    }
  }
  
  for(int i = 0;i < n; ++i){
    int row = -1;
    if(cnt[1] || cnt[r/2 + 2]){
      if(cnt[1] >= cnt[r/2 + 2]){
        row = 1;
      }
      else row = r / 2 + 2;
    }
    else{
      int idxmaks = 1;
      for(int j = 0; j < r + 3; ++j){
        if(cnt[j] > cnt[idxmaks]) idxmaks = j;
        else if(cnt[j] == cnt[idxmaks] && jarak(j) < jarak(idxmaks)){
          idxmaks = j;
        }
      }
      row = idxmaks;
    }
    
    int cols = -1;
    if(ar[row][4] == avail || ar[row][6] == avail){
      if(ar[row][4] == avail && ar[row][6] == avail){
        if(cntleft <= cntright) cols = 4;
        else cols = 6;
      }
      else if(ar[row][4] == avail) cols = 4;
      else cols = 6;
    }
    else if(ar[row][2] == avail || ar[row][8] == avail){
      if(ar[row][2] == avail && ar[row][8] == avail){
        if(cntleft <= cntright) cols = 2;
        else cols = 8;
      }
      else if(ar[row][2] == avail) cols = 2;
      else cols = 8;
    }
    else if(ar[row][0] == avail || ar[row][10] == avail){
      if(ar[row][0] == avail && ar[row][10] == avail){
        if(cntleft <= cntright) cols = 0;
        else cols = 10;
      }
      else if(ar[row][0] == avail) cols = 0;
      else cols = 10;
    }
    else if(ar[row][5] == avail) cols = 5;
    else {
      if(ar[row][1] == avail && ar[row][9] == avail){
        if(cntleft <= cntright) cols = 1;
        else cols = 9;
      }
      else if(ar[row][1] == avail) cols = 1;
      else cols = 9;
    }
    fprintf(stderr, "SELECT %d : %d %d\n",i, row, cols); 
    ar[row][cols] = 'a' + i;
    
    cnt[row]--;
    if(cols <= 4) cntleft++;
    else if(cols >= 6) cntright++;
  }
  
  
  for(int i = 0;i < r + 3; ++i) {
    for(int j = 0;j < C; ++j) printf("%c", ar[i][j]);
    printf("\n");
  }
  
  return 0;
}
