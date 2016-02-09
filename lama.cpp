#include <stdio.h>
#include <stdlib.h>

int back(int X[][2], int i, int n){
  while (i>0 && X[i-1][0] != -1 && X[i-1][0] == X[i][0]) i--;
  if (X[i][0] != -1) return i;
  if (i+1<n && X[i+1][0] != -1) return i+1;
  while (i>0 && (X[i][0] == -1 || X[i-1][0] == X[i][0])) i--;
  return i;
}

int X[10000][2], Y[10000][2];

int cmp(const void *a, const void *b){
  int *x = (int*) a, *y = (int*) b;
  if (x[0] != y[0]) return x[0] - y[0];
  return x[1] - y[1];
}

int main(){
  for (int n; scanf("%d",&n)!=EOF; ){
    for (int i=0; i<n; i++) scanf("%d",&X[i][0]), X[i][1] = i;
    for (int i=0; i<n; i++) scanf("%d",&Y[i][0]), Y[i][1] = i;

    qsort(X, n, sizeof(X[0]), cmp);
    qsort(Y, n, sizeof(Y[0]), cmp);
    
    for (int i=0, x1=0, x2=n-1, y1=0, y2=n-1; i<n; i++){
      while (x1<n && X[x1][0]==-1) x1++;
      while (y1<n && Y[y1][0]==-1) y1++;
      x2 = back(X, x2, n);
      y2 = back(Y, y2, n);

      int *co1 = X[x1], *co2 = X[x2], *ce1 = Y[y1], *ce2 = Y[y2];
      int co1ce2 = (co1[0] - ce2[0]) * (co1[0] - ce2[0]);
      int co2ce1 = (co2[0] - ce1[0]) * (co2[0] - ce1[0]);

      int cmp = co2ce1 - co1ce2;      // wah value terbesar
      if (cmp==0) cmp = co1[1] - co2[1];  // index co terkecil
      if (cmp==0) cmp = ce2[1] - ce1[1];  // index ce terkecil

      if (cmp < 0){
        co1[0] = ce2[0] = -1;
        printf("%d %d %d\n",co1[1],ce2[1],co1ce2);
      } else {
        co2[0] = ce1[0] = -1;
        printf("%d %d %d\n",co2[1],ce1[1],co2ce1);
      }
    }
    puts("");
  }
}