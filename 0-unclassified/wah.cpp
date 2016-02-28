#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> a, b;
vector<int> na[N], nb[N];

int take_cowok(int val) {
  return na[val].back();
}

int take_cewek(int val) {
  return nb[val].back();
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    
    a.clear();
    b.clear();
    for(int i = 0; i < N; i++) {
      na[i].clear();
      nb[i].clear();
    }
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      a.push_back(num);
      na[num].push_back(i);
    }
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      b.push_back(num);
      nb[num].push_back(i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++) {
      if(i && a[i] == a[i - 1]) {
        continue;
      }
      sort(na[a[i]].begin(), na[a[i]].end());
      reverse(na[a[i]].begin(), na[a[i]].end());
    }
    for(int i = 0; i < b.size(); i++) {
      if(i && b[i] == b[i - 1]) {
        continue;
      }
      sort(nb[b[i]].begin(), nb[b[i]].end());
      reverse(nb[b[i]].begin(), nb[b[i]].end());
    }
    int ia = 0, ja = (int) a.size() - 1, ib = 0, jb = (int) b.size() - 1;
    for(int i = 0; i < n; i++) {
      int maxa = a[ja];
      int mina = a[ia];
      int maxb = b[jb];
      int minb = b[ib];
      if(abs(maxa - minb) > abs(maxb - mina)) {
      
        int co = take_cowok(maxa);
        int ce = take_cewek(minb);
        printf("%d %d %d\n", co, ce, (maxa - minb) * (maxa - minb));
        ja--;
        ib++;
        na[maxa].pop_back();
        nb[minb].pop_back();
        
      } else if(abs(maxa - minb) < abs(maxb - mina)) {
        
        int co = take_cowok(mina);
        int ce = take_cewek(maxb);
        printf("%d %d %d\n", co, ce, (maxb - mina) * (maxb - mina));
        ia++;
        jb--;
        na[mina].pop_back();
        nb[maxb].pop_back();
        
      } else {
        
        assert(abs(maxa - minb) == abs(maxb - mina));
        int coa = take_cowok(maxa);
        int cob = take_cowok(mina);
        if(coa < cob) {
          int ce = take_cewek(minb);
          printf("%d %d %d\n", coa, ce, (maxa - minb) * (maxa - minb));
          ja--;
          ib++;
          na[maxa].pop_back();
          nb[minb].pop_back();
          
        } else if(coa > cob) {
        
          int ce = take_cewek(maxb);
          printf("%d %d %d\n", cob, ce, (maxb - mina) * (maxb - mina));
          ia++;
          jb--;
          na[mina].pop_back();
          nb[maxb].pop_back();
          
        } else {
          assert(coa == cob);
          int cea = take_cewek(maxb);
          int ceb = take_cewek(minb);
          if(cea <= ceb) {
            printf("%d %d %d\n", coa, cea, (maxb - mina) * (maxb - mina));
            ia++;
            jb--;
            na[mina].pop_back();
            nb[maxb].pop_back();
          } else {
            printf("%d %d %d\n", coa, ceb, (minb - mina) * (minb - mina));
            ia++;
            ib++;
            na[mina].pop_back();
            nb[minb].pop_back();
          }
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}
