#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int sisan = n % k;
    int sisam = m - k;
    if(n == 1){
      puts("mustahil");
      continue;
    }
    if(sisan == 0){
      if(sisam == 0) {
        puts("mustahil");
        continue;
      }
      else{
        puts("mungkin");
        for(int i = 0;i < n / 2; i++){
          printf("1 2 3\n");
          printf("2 1 3\n");  
        }
      }
    }
    else {
      if(n == 3){
        if(sisam < 2){
          puts("mustahil");
          continue;
        }
        else{
          puts("mungkin");
          printf("1 4 3\n");
          printf("3 2 4\n");
          printf("2 1 4\n");
        }
      }
      else{
        puts("mungkin");
        printf("1 2 3\n");
        printf("2 3 1\n");
        printf("3 1 2\n");
        for(int i = 0;i < (n - 3) / 2; ++i){
          printf("1 2 3\n");
          printf("2 1 3\n");
        }
      }
    }
    
  }
  return 0;
}