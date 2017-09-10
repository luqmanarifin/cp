#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define int long long

const int INF = 2e9;
const double EPS = 1e-9;
const int N = 2000, M = 5000;
int poi[N + 5];
pii ve[N + 5][M + 5];
piii edge[M + 5];
int dist[N + 5];
set<pii> pq;
int n, m;
int A[M + 5], B[M + 5], C[M + 5];

bool checkBellmanFord(){
    memset(dist, 0, sizeof(dist));
    for(int loop = 1; loop < n; ++loop){
        for(int i = 0;i < m; ++i){
            if(dist[A[i]] + C[i] < dist[B[i]]){
                dist[B[i]] = dist[A[i]] + C[i];
            }
        }
    }

    for(int i = 0;i < m; ++i){
        if(dist[A[i]] + C[i] < dist[B[i]]){
            return false;
        }
    }
    return true;
}

main(){
    int t;
    scanf("%I64d", &t);
    while(t--){
        scanf("%I64d%I64d", &n, &m);
        int minEdge = INF;
        memset(poi, 0, sizeof poi);
        for(int i = 0;i < m; ++i){
            int x, y, c;
            scanf("%I64d%I64d%I64d", &x, &y, &c);
            ve[x][poi[x]] = mp(y, c);
            poi[x]++;
            minEdge = min(minEdge, c);
            A[i] = x;
            B[i] = y;
            C[i] = c;
            edge[i] = mp(mp(x, y), c);
        }
        if(minEdge >= 0){
            printf("%I64d\n", minEdge);
            continue;
        }
        bool valid = checkBellmanFord();
        if(!valid){
            puts("-inf");
            continue;
        }
        int mindist = INF;
        for (int i = 1; i <= n; i++) mindist = min(mindist, dist[i]);
        printf("%I64d\n", mindist);
    }
    return 0;
}