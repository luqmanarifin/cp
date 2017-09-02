#include <bits/stdc++.h>

using namespace std;

int num[] = {1, 5, 10, 50, 100, 500, 1000};
string str = "IVXLCDM";

char a[100], b[100];

int val(char* s){
  int n = strlen(s);
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < str.size(); j++) {
      if (str[j] == s[i]) {
        ret.push_back(num[j]);
      }
    }
  }
  int v = 0;
  for (int i = 0; i < ret.size(); i++) {
    if (i + 1 < ret.size() && ret[i] < ret[i + 1]) {
      v -= ret[i];
    } else {
      v += ret[i];
    }
  }
  return v;
}

void write(int val){
  if (val < 10) {
    if (val >= 9) {
      printf("IX");
    } else if (val >= 5) {
      printf("V");
      write(val - 5);
    } else {
      if (val == 4) {
        printf("IV");
      } else {
        for (int i = 0; i < val; i++) {
          printf("I");
        }
      }
    }
  } else if (val < 100) {
    if (val >= 90) {
      printf("XC");
      write(val - 90);
    } else if (val >= 50) {
      printf("L");
      write(val - 50);
    } else {
      if (val >= 40) {
        printf("XL");
        write(val - 40);
      } else {
        int k = val / 10;
        for (int i = 0; i < k; i++) {
          printf("X");
        }
        write(val - k * 10);
      }
    }
  } else if (val < 1000) {
    if (val >= 900) {
      printf("CM");
      write(val - 900);
    } else if (val >= 500) {
      printf("D");
      write(val - 500);
    } else {
      if (val >= 400) {
        printf("CD");
        write(val - 400);
      } else {
        int k = val / 100;
        for (int i = 0; i < k; i++) {
          printf("C");
        }
        write(val - k * 100);
      }
    }
  } else {
    int k = val / 1000;
    for (int i = 0; i < k; i++) printf("M");
    write(val - k * 1000);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s %s", a, b);
    int c = val(a) + val(b);
    printf("Case #%d: ", tt);
    write(c);
    printf("\n");
  }
  
  return 0;
}