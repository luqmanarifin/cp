#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e8;

int x[N][N], d[N][N];
int tx[N][N], td[N][N];

char s[N][N];
int ax[N][N], ad[N][N];

tuple<int, int, char> p[N];
vector<int> px, py;

int idx(int a) {
  return lower_bound(px.begin(), px.end(), a) - px.begin();
}

int idy(int a) {
  return lower_bound(py.begin(), py.end(), a) - py.begin();
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(x, 0, sizeof(x));
    memset(d, 0, sizeof(d));
    memset(s, 0, sizeof(s));
    memset(ax, 0, sizeof(ax));
    memset(ad, 0, sizeof(ad));
    px.clear();
    py.clear();
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int cnto = 0;
    for(int i = 0; i < k; i++) {
      int a, b;
      char ch;
      scanf("%d %d %c", &a, &b, &ch);
      px.push_back(a);
      py.push_back(b);
      if(ch == 'O') {
        cnto++;
      }
      p[i] = make_tuple(a, b, ch);
    }
    int cntx = k - cnto;
    
    px.push_back(0); px.push_back(n);
    py.push_back(0); py.push_back(m);
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    px.resize(distance(px.begin(), unique(px.begin(), px.end())));
    py.resize(distance(py.begin(), unique(py.begin(), py.end())));
    for(int i = 0; i < k; i++) {
      int a, b; char ch;
      tie(a, b, ch) = p[i];
      a = idx(a);
      b = idy(b);
      if(ch == 'O') {
        ad[a][b]++;
      } else {
        ax[a][b]++;
      }
    }
    for(int i = 1; i < px.size(); i++) {
      for(int j = 1; j < py.size(); j++) {
        ad[i][j] += ad[i - 1][j];
        ax[i][j] += ax[i - 1][j];
      }
    }
    
    for(int i = 0; i < k; i++) {
      int a, b; char ch;
      tie(a, b, ch) = p[i];
      a = idx(a);
      b = idy(b);
      s[a][b] = ch;
    }
    for(int it = 1; it < py.size(); it++) {
      for(int i = 1; i < px.size(); i++) {
        for(int j = 0; j <= k; j++) {
          td[i][j] = d[i][j];
          tx[i][j] = x[i][j];
          d[i][j] = 0;
          x[i][j] = 0;
        }
      }
      for(int i = 1; i < px.size(); i++) {
        for(int j = 0; j <= k; j++) {
          int a = d[i - 1][j];
          int b = x[i - 1][j];
          int to = j - ad[i][it] - ax[i][it];
          
          if(to >= 0) {
            a = max(a, td[i][to] + ad[i][it]);
            b = max(b, tx[i][to] + ax[i][it]);
          }
          d[i][j] = a;
          x[i][j] = b;
        }
      }
    }
    int last = px.size() - 1;
    int ans = min(cnto - d[last][cnto], cntx - x[last][cntx]);
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
