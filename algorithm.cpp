#include <stdio.h>

int main(){
  int i;
  for(i = 0; i < 10; i++) {
    printf("??%d>>%d??\n", i, i);
  }
  printf("??>>?\n");
  for(i = 0; i < 9; i++) {
    printf("%d?<>%d\n", i, i + 1);
  }
  printf("9?>>?0\n?<>1\n>>??\n");
}