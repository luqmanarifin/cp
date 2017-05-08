#include <bits/stdc++.h>

using namespace std;

const int N = 15;

long long a[N][N];
int n, m, l;
char s[55];
bool vis[N];

int get_rand(int pol) {
  int num = 0;
  long long now = 1;
  while (now < pol) {
    num++;
    now *= RAND_MAX;
  }
  long long ret = 1;
  for (int i = 0; i < num; i++) {
    ret *= rand();
  }
  return ret % pol;
}

set<long long> all;

void dfs(int now, int ke, long long sum) {
  vis[now] = 1;
  //printf("%d %d %I64d\n", now, ke, sum);
  if (ke == n) {
    all.insert(sum + a[now][0]);
  } else {
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(i, ke + 1, sum + a[now][i]);
      }
    }
  }
  vis[now] = 0;
}

int main() {
  srand(time(NULL));
  scanf("%s %d %d %d", s, &n, &m, &l);
  if (s[6] == '6' || s[7] == '7' || s[8] == '8') {
    
    for (int it = 1; ; it++) {
      all.clear();
      memset(vis, 0, sizeof(vis));
      int p = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          a[i][j] = a[j][i] = (1LL << p);
          cerr << a[i][j] << endl;
          p++;
        }
      }
      dfs(0, 1, 0);
      cerr << all.size() << endl;
      if (all.size() >= m) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (j) printf(" ");
            printf("%I64d", a[i][j]);
          }
          printf("\n");
        }
        return 0;
      }
      cerr << "iter " << it << " ga nemu\n";
    }
    
  } else {
    
    
    for (int it = 1; ; it++) {
      memset(vis, 0, sizeof(vis));
      all.clear();
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          a[i][j] = a[j][i] = get_rand(l) + 1;
        }
      }
      dfs(0, 1, 0);
      cerr << all.size() << endl;
      if (all.size() >= m) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (j) printf(" ");
            printf("%d", a[i][j]);
          }
          printf("\n");
        }
        return 0;
      }
      cerr << "iter " << it << " ga nemu\n";
    }
  }

  return 0;
}
