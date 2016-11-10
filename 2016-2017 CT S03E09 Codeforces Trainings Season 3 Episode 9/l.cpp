#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int a[N][N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    if (s[0] == 'l') {
      for (int i = 0; i < n; i++) {
        vector<int> num, be;
        for (int j = 0; j < n; j++) {
          if (a[i][j]) {
            num.push_back(a[i][j]);
          }
          a[i][j] = 0;
        }
        for (int j = 0; j < num.size(); j++) {
          if (j + 1 < num.size() && num[j] == num[j + 1]) {
            be.push_back(num[j] * 2);
            j++;
          } else {
            be.push_back(num[j]);
          }
        }
        for (int j = 0; j < be.size(); j++) {
          a[i][j] = be[j];
        }
      }
    } else if (s[0] == 'r') {
      for (int i = 0; i < n; i++) {
        vector<int> num, be;
        for (int j = n - 1; j >= 0; j--) {
          if (a[i][j]) {
            num.push_back(a[i][j]);
          }
          a[i][j] = 0;
        }
        for (int j = 0; j < num.size(); j++) {
          if (j + 1 < num.size() && num[j] == num[j + 1]) {
            be.push_back(num[j] * 2);
            j++;
          } else {
            be.push_back(num[j]);
          }
        }
        for (int j = 0; j < be.size(); j++) {
          a[i][n - 1 - j] = be[j];
        }
      }
    } else if (s[0] == 'd') {
      for (int j = 0; j < n; j++) {
        vector<int> num, be;
        for (int i = n - 1; i >= 0; i--) {
          if (a[i][j]) {
            num.push_back(a[i][j]);
          }
          a[i][j] = 0;
        }
        for (int i = 0; i < num.size(); i++) {
          if (i + 1 < num.size() && num[i] == num[i + 1]) {
            be.push_back(num[i] * 2);
            i++;
          } else {
            be.push_back(num[i]);
          }
        }
        for (int i = 0; i < be.size(); i++) {
          a[n - 1 - i][j] = be[i];
        }
      }
    } else {
      for (int j = 0; j < n; j++) {
        vector<int> num, be;
        for (int i = 0; i < n; i++) {
          if (a[i][j]) {
            num.push_back(a[i][j]);
          }
          a[i][j] = 0;
        }
        for (int i = 0; i < num.size(); i++) {
          if (i + 1 < num.size() && num[i] == num[i + 1]) {
            be.push_back(num[i] * 2);
            i++;
          } else {
            be.push_back(num[i]);
          }
        }
        for (int i = 0; i < be.size(); i++) {
          a[i][j] = be[i];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
