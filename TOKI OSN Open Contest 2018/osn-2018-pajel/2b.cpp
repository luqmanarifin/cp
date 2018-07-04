#include <bits/stdc++.h>

using namespace std;

const int N = 505;

#define RED 2
#define BLUE 3
#define WHITE 0
#define UNKNOWN -1

int a[N][N];
string U[N], L[N], R[N], D[N];


int main() {
  memset(a, UNKNOWN, sizeof(a));
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> U[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> D[i];
  }
  for (int i = 1; i <= n; i++) {
    // U
    if (U[i] == "0") {
      for (int j = 1; j <= n; j++) {
        a[j][i] = WHITE;
      }
    } else if (U[i] != "-") {
      int color = (U[i].back() == 'B'? BLUE : RED);
      // cout <<U[i].substr(U[i].size() - 1) << endl;
      int num = atoi(U[i].substr(0, U[i].size() - 1).c_str());
      // printf("u %d\n", num);
      for (int j = 1; j < num; j++) {
        a[j][i] = WHITE;
      }
      a[num][i] = color;
    }

    // L
    if (L[i] == "0") {
      for (int j = 1; j <= n; j++) {
        a[i][j] = WHITE;
      }
    } else if (L[i] != "-") {
      int color = (L[i].back() == 'B'? BLUE : RED);
      int num = atoi(L[i].substr(0, L[i].size() - 1).c_str());
      for (int j = 1; j < num; j++) {
        a[i][j] = WHITE;
      }
      a[i][num] = color;
    }

    // R
    if (R[i] == "0") {
      for (int j = 1; j <= n; j++) {
        a[i][n+1-j] = WHITE;
      }
    } else if (R[i] != "-") {
      int color = (R[i].back() == 'B'? BLUE : RED);
      int num = atoi(R[i].substr(0, R[i].size() - 1).c_str());
      for (int j = 1; j < num; j++) {
        a[i][n+1-j] = WHITE;
      }
      a[i][n+1-num] = color;
    }

    // D
    if (D[i] == "0") {
      for (int j = 1; j <= n; j++) {
        a[n+1-j][i] = WHITE;
      }
    } else if (D[i] != "-") {
      int color = (D[i].back() == 'B'? BLUE : RED);
      int num = atoi(D[i].substr(0, D[i].size() - 1).c_str());
      for (int j = 1; j < num; j++) {
        a[n+1-j][i] = WHITE;
      }
      a[n+1-num][i] = color;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == UNKNOWN) {
        printf("X");
      } else if (a[i][j] == BLUE) {
        printf("B");
      } else if (a[i][j] == RED) {
        printf("M");
      } else {
        printf("-");
      }
    }
    printf("\n");
  }
  return 0;
}
