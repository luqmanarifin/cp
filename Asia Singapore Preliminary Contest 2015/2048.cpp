#include <bits/stdc++.h>

using namespace std;

int x[5][5];

int main() {
  for(int i = 0; i<4; i++)
    for(int j = 0; j<4; j++) {
      scanf("%d", &x[i][j]);
    }
  int k;
  scanf("%d", &k);
  switch(k) {
    case 0 :
      for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
          int y = j, z = j;
          while(y < 4 && x[i][y] == 0) y++;
          z = y+1;
          while(z < 4 && x[i][z] == 0) z++;
          if(y < 4 && z < 4) {
            if(x[i][y] == x[i][z]) {
              int temp = x[i][y];
              x[i][y] = x[i][z] = 0;
              x[i][j] = temp*2;
            }
            else {
              int temp = x[i][y];
              x[i][y] = 0;
              x[i][j] = temp;
            }
          }
          else if(y < 4) {
            int temp = x[i][y];
            x[i][y] = 0;
            x[i][j] = temp;
          }
          else
            x[i][j] = 0;
        }
      }
    break;
    case 1 :
      for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
          int y = j, z = j;
          while(y < 4 && x[y][i] == 0) y++;
          z = y+1;
          while(z < 4 && x[z][i] == 0) z++;
          if(y < 4 && z < 4) {
            if(x[y][i] == x[z][i]) {
              int temp = x[y][i];
              x[y][i] = x[z][i] = 0;
              x[j][i] = temp*2;
            }
            else {
              int temp = x[y][i];
              x[y][i] = 0;
              x[j][i] = temp;
            }
          }
          else if(y < 4) {
            int temp = x[y][i];
            x[y][i] = 0;
            x[j][i] = temp;
          }
          else
            x[j][i] = 0;
        }
      }
    break;
    case 2 :
      for(int i = 0; i<4; i++) {
        for(int j = 3; j >= 0; j--) {
          int y = j, z = j;
          while(y >= 0 && x[i][y] == 0) y--;
          z = y-1;
          while(z >= 0 && x[i][z] == 0) z--;   
          if(y >= 0 && z >= 0) {
            if(x[i][y] == x[i][z]) {
              int temp = x[i][y];
              x[i][y] = x[i][z] = 0;
              x[i][j] = temp*2;
            }
            else {
              int temp = x[i][y];
              x[i][y] = 0;
              x[i][j] = temp;
            }
          }
          else if(y >= 0) {
            int temp = x[i][y];
            x[i][y] = 0;
            x[i][j] = temp;
          }
          else
            x[i][j] = 0;
        }
      }
    break;

    case 3 :
      for(int i = 0; i<4; i++) {
        for(int j = 3; j>= 0; j--) {
          int y = j, z = j;
          while(y >= 0 && x[y][i] == 0) y--;
          z = y-1;
          while(z >= 0 && x[z][i] == 0) z--;
          if(y >= 0 && z >= 0) {
            if(x[y][i] == x[z][i]) {
              int temp = x[y][i];
              x[y][i] = x[z][i] = 0;
              x[j][i] = temp*2;
            }
            else {
              int temp = x[y][i];
              x[y][i] = 0;
              x[j][i] = temp;
            }
          }
          else if(y >= 0) {
            int temp = x[y][i];
            x[y][i] = 0;
            x[j][i] = temp;
          }
          else
            x[j][i] = 0;
        }
      }
    break;
  }
  for(int i = 0; i<4; i++)
    for(int j = 0; j<4; j++)
      printf("%d%c", x[i][j], (j < 3) ? ' ': '\n');
  return 0;
}