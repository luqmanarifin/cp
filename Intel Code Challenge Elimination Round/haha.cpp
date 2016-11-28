#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000

double p[MAXN+5], u[MAXN+5], pu[MAXN+5];
double dp[MAXN+5][MAXN+5];

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) pu[i] = p[i]+u[i]-p[i]*u[i];
    int cnt = 0;
    for (int i = 0 ; i < n; ++i) {
        int mna = max(0, a+i-n+1);
        int mxa = min(a,i+1);
        int mnb = max(0, b+i-n+1);
        int mxb = min(b,i+1);
        for (int aa = mxa; aa >= mna; --aa)
            for (int bb = mxb; bb >= mnb; --bb) {
              cnt++;
                double &r = dp[aa][bb];
                if (aa) r = max(r, dp[aa-1][bb]+p[i]);
                if (bb) r = max(r, dp[aa][bb-1]+u[i]);
                if (aa && bb) r = max(r, dp[aa-1][bb-1]+pu[i]);
            }
    }
    cout << cnt << endl;
    printf("%lf\n", dp[a][b]);
    return 0;
}