#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

vector <int> v[N];
int n,s[N],ans[N];

struct point{
    int x,y,id;
};

vector <point> p;

void input(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        point po;
        scanf("%d%d",&po.x, &po.y);
        po.id = i;
        p.push_back(po);
    }
}

int Gx,Gy;

bool mycomp1(point a, point b) {
    return (a.x-Gx)*(b.y-Gy) > (b.x-Gx)*(a.y-Gy);
}

void dfs1(int g, int fr) {
    s[g] = 1;
    for (int t:v[g]) {
        if (t != fr) {
            dfs1(t, g);
            s[g] += s[t];
        }
    }
}


void dfs2(int g, int fr,int l,int r) {

    for (int i = l+1; i < r; i++) {
        if (p[l].x > p[i].x || (p[l].x == p[i].x && p[l].y > p[i].y)) {
            swap(p[l], p[i]);
        }
    }

    ans[g] = p[l].id;

    Gx = p[l].x;
    Gy = p[l].y;

    l++;

    sort(p.begin() + l, p.begin() + r, mycomp1);

    for (int t:v[g]) {
        if (t != fr) {
            dfs2(t, g, l, l + s[t]);
            l += s[t];
        }
    }
}


void sol(){
    dfs1(1,1);
    dfs2(1,1,0,int(p.size()));
    for (int i = 1; i < n; i++) printf("%d ",ans[i]);
    printf("%d\n", ans[n]);
}

int main() {
    input();
    sol();
    return 0;
}