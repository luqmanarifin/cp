#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;

int A[N + 5], B[N + 5], C[N + 5];

void case1(int n, int m, int k){
  if(m <= 2){
    puts("mustahil");
    return;
  }
  puts("mungkin");
  for(int i = 0;i < n; ++i){
    puts("1 2 3");
  }
}

void case2(int n, int m, int k){
  int sisan = n % k;
  int sisam = m - k;
  if(n == 1){
    puts("mustahil");
    return;
  }
  if(sisan == 0){
    if(sisam == 0) {
      puts("mustahil");
      return;
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
        return;
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

int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(k == 1){
      case1(n, m, k);
    }
    else if(k == 2){
      case2(n, m, k);
    }
    else{
      int medals = n / k;
      int sisan = n - medals * k;
      if(sisan == 0){
        puts("mungkin");
        for(int med = 1;med <= medals; ++med){
          for(int i = 1;i <= k; ++i){
            int x[3] = {i, i + 1, i + 2};
            for(int j = 0;j < 3; ++j) {
              if(x[j] > k) x[j] -= k;
            } 
            for(int j = 0;j < 3; ++j) printf("%d%c", x[j], j == 2 ? '\n' : ' ');
          }
        }
      }
      else if(medals == 1){
        if(m < n + 1){
          puts("mustahil");
          continue;
        }
        else{
          for(int i = 1;i <= n; ++i) A[i] = i;
          B[1] = m, C[1] = k + 1;
          for(int i = 2;i <= k + 1; ++i) B[i] = i - 1, C[i] = m;
          for(int i = k + 2; i <= n; ++i) B[i] = m, C[i] = k + 1;
          puts("mungkin");
          for(int i = 1;i <= n; ++i) printf("%d %d %d\n", A[i], B[i], C[i]); 
        }
      }
      else{
        int minm = k;
        minm += sisan / medals + 1;
        if(m < minm){
          puts("mustahil");
          continue;
        }
        else{
          puts("mungkin");
          for(int med = 0; med < medals; ++med){
            int kiri = med * k;
            for(int i = 1;i <= k; ++i){
              A[kiri + i] = i;
              B[kiri + i + sisan] = i;
            }
          }
          for(int i = 1, now = 2;i <= n; ++i){
            if(i <= sisan || i > sisan * 2){
              C[i] = now;
              now++;
              if(now > k) now -= k;
            }
          
          }
          int atas = n - sisan % k;
          int cnt = 0;
          int now = k + 1;
          for(int i = atas + 1, ii = 1, iii = sisan + 1; i <= n; i++, ii++, iii++){
            A[i] = now;
            C[iii] = now;
            cnt++;
            if(cnt == medals) cnt = 0, now++;
          }
          if(cnt == 0){
            A[n] = now;
            C[2 * sisan] = now; 
          }
          for(int i = 1;i <= sisan; ++i) B[i] = now;
          for(int i = 1;i <= n; ++i) printf("%d %d %d\n", A[i], B[i], C[i]); 
        }
      }

    }
    
  }  

  return 0;
}
