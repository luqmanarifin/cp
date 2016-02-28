#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int a[N];

int val[N];
int p[N];
int aft[N];

int cat(int n) {
  int cur = 1;
  for(int i = 1; i <= 2 *n; i++) {
    cur *= i;
  }
  for(int i = 1; i <= n + 1; i++) {
    cur /= i;
  }
  for(int i = 1; i <= n; i++) {
    cur /= i;
  }
  return cur;
}

int main() {
  for(int i = 1; i <= 5; i++) {
    printf("%d ", cat(i));
  }
  printf("\n");
  
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(a, 0, sizeof(a));
    memset(val, 0, sizeof(val));
    memset(p, 0, sizeof(p));
    memset(aft, 0, sizeof(aft));
    
    scanf("%s", s);
    int n = strlen(s);
    assert(n % 2 == 0);
    int now = 0;
    for(int i = 0; i < n; i++) {
      if(i) val[i] = val[i - 1];
      if(s[i] == '(') {
        val[i]++;
        p[now++] = i;
      }
    }
    stack<int> st;
    now = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '(') {
        st.push(now++);
      } else {
        a[st.top()] = val[i] - val[p[st.top()]];
        //printf("entry %d %d\n", val[i], val[p[st.top()]]);
        st.pop();
      }
    }
    
    int k = n / 2;
    /*
    puts("val:");
    for(int i = 0; i < n; i++) {
      printf("%d ", val[i]);
    }
    printf("\n");
    */
    bool allZero = 1;
    for(int i = 0; i < k; i++) {
      if(a[i] != 0) {
        allZero = 0;
      }
      printf("%d ", a[i]);
    }
    printf("\n");
    if(allZero) {
      puts("TIDAK ADA");
      continue;
    }
    int first = 0;
    for(int i = 0; i < k; i++) {
      if(a[i]) {
        first = i;
        break;
      }
    }
    for(int i = k - 1; i >= 0; i--) {
      if(a[i] != 0) {
        a[i]--;
        int cok = 0;
        if(a[i] == 0) {
          cok = k - i - 2;
        } else {
          cok = min(k - i - 2, a[i] - 1);
        }
        cok = max(0, cok);
        printf("cok %d\n", cok);
        for(int j = i + 1; j < k; j++) {
          a[j] = cok;
          if(cok > 0) cok--;
        }
        break;
      }
    }
    /*
    puts("ANSWER : ");
    for(int i = 0; i < k; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    */
    for(int i = 0; i < k; i++) {
      aft[i + a[i]]++;
      printf("(");
      for(int j = 0; j < aft[i]; j++) {
        printf(")");
      }
    }
    printf("\n\n");
  }
  
  return 0;
}
