#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
#define SA_N 6000
#define SA_LN 15
int lg, len, p[SA_LN][SA_N], sa[SA_LN];
int la[SA_N], lb[SA_N], lc[SA_N];
int bucket[SA_N], tla[SA_N], tlb[SA_N], tlc[SA_N];
void constructSA(int *a, int leng) {
	len = leng;
	lg = 1;
	for(int i=0; i<len; i++) p[0][i] = a[i];
	sort(a, a+len);
	map <int, int> M;
	for(int i=0; i<len; i++) if(i==0 || (a[i] != a[i-1])) M[a[i]] = i;
	for(int i=0; i<len; i++) p[0][i] = M[p[0][i]];
	for(int skip=1; skip/2 < len; skip<<=1, lg++) {
		for(int i=0; i<len; i++) {
			la[i] = p[lg-1][i];
			lb[i] = i+skip < len ? p[lg-1][i+skip] : -1;
			lc[i] = i;
		}
		for(int i=0; i<len+10; i++) bucket[i] = 0;
		for(int i=0; i<len; i++) bucket[lb[i]+1]++;
		for(int i=1; i<len+10; i++) bucket[i] += bucket[i-1];
		for(int i=len-1; i>=0; i--) {
			int wer = (bucket[lb[i]+1]--)-1;
			tla[wer] = la[i]; tlb[wer] = lb[i]; tlc[wer] = lc[i];
		}
		for(int i=0; i<len; i++) la[i] = tla[i], lb[i] = tlb[i], lc[i] = tlc[i];
		for(int i=0; i<len+10; i++) bucket[i] = 0;
		for(int i=0; i<len; i++) bucket[la[i]]++;
		for(int i=1; i<len+10; i++) bucket[i] += bucket[i-1];
		for(int i=len-1; i>=0; i--) {
			int wer = (bucket[la[i]]--)-1;
			tla[wer] = la[i]; tlb[wer] = lb[i]; tlc[wer] = lc[i];
		}
		for(int i=0; i<len; i++) la[i] = tla[i], lb[i] = tlb[i], lc[i] = tlc[i];
		for(int i=0; i<len; i++) {
			p[lg][lc[i]] = (i>0 && la[i-1]==la[i] && lb[i-1]==lb[i])? p[lg][lc[i-1]] : i;
		}
	}
	lg--;
	for(int i=0; i<len; i++) sa[p[lg][i]] = i;
	// for(int i=0; i<len; i++) printf("%d ",p[lg][i]); printf("\n");
	//p[lg][] has the rank of every index.
}
void constructSA(char *t, int leng) {
	int *a = new int[leng];
	for(int i=0; i<leng; i++) a[i] = int(t[i]);
	constructSA(a, leng);
	delete a;
}
int lcp(int i, int j) {
	if(i==j) return len - i;
	int ans = 0;
	for(int k = lg; k>=0 && i<len && j<len; k--)
		if(p[k][i] == p[k][j])
			ans += (1<<k), i += (1<<k), j += (1<<k);
	return ans;
}

#define N SA_N
int stk[N], LCP[N], L[N], R[N];
vector <int> li[N];
char s[N];
long long d[N];
long long ans[N];
int comb[N][N];

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(comb[i][j] >= mod) {
        comb[i][j] -= mod;
      }
    }
    comb[i][0] = comb[i][i] = 1;
  }

	int t, q;
	scanf("%d", &t);
	while(t--) {
    memset(ans, 0, sizeof(ans));
		scanf("%d %d %s", &len, &q, s);
		constructSA(s, strlen(s));
		// cerr << string(s) << endl;
		for(int i=0; i<=len+2; i++) li[i].clear(), d[i] = 0;
		for(int i=0; i<len-1; i++) li[ (LCP[i] = lcp(sa[i], sa[i+1])) ].push_back(i);
		int top = 0;
		for(int i=0; i<len-1; i++) {
			while(top && LCP[stk[top-1]] >= LCP[i]) top--;
			if(top == 0) L[i] = -1;
			else L[i] = stk[top-1];
			stk[top++] = i;
		}
		top = 0;
		for(int i=len-2; i>=0; i--) {
			while(top && LCP[stk[top-1]] >= LCP[i]) top--;
			if(top == 0) R[i] = len-1;
			else R[i] = stk[top-1];
			stk[top++] = i;
		}
		for(int i=len; i; i--) {
			int j = 0;
			while(j < li[i].size()) {
				int mini = i;
				int k = li[i][j];
				if(L[k] != -1 && mini > i - LCP[L[k]]) mini = i - LCP[L[k]];
				if(R[k] != len-1 && mini > i - LCP[R[k]]) mini = i - LCP[R[k]];
				int range = R[k] - L[k] - 1 + 1;
				d[range] += (long long)mini * range;
				while(j < li[i].size() && li[i][j] < R[k]) j++;
			}
		}
    int sum = 0;
    for(int i = 1; i <= len; i++) {
      sum += d[i];
    }
    d[1] = len * (len + 1) / 2 - sum;
    for(int i = 1; i <= len; i++) {
      //assert(d[i] % i == 0);
      d[i] /= i;
    }
    
    for(int i = 1; i <= len; i++) {
      for(int j = i; j <= len; j++) {
        ans[i] += d[j] * comb[j][i];
      }
      ans[i] %= mod;
    }
    while(q--) {
      int num;
      scanf("%d", &num);
      if(num > len) {
        printf("0\n");
      } else {
        printf("%lld\n", ans[num]);
      }
    }
	}
	return 0;
}