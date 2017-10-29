#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int N = 210;
const int oo = 1e9+7;
int n, c[N][N], mx[N], my[N], T[N];
int vx[N], vy[N], fx[N], fy[N], q[2*N];
vector<int> ke[N];

void enter() {
    scanf("%d",&n);
    int u, v, w;
    FOR(i,1,n)
    FOR(j,1,n) c[i][j] = oo;
    while (scanf("%d%d%d",&u,&v,&w) != EOF) ke[u].pb(v), c[u][v] = w;
}

int Get(int u,int v) {return c[u][v] - fx[u] - fy[v];}

int Findpath(int s) {
    FOR(u,1,n) T[u] = 0;
    int l = 1, r = 1, u, v; q[1] = s;
    queue<int> Q; Q.push(s);
    while (l <= r) {
        u = q[l]; l++;
        FOR(v,1,n)
        if (T[v] == 0 && Get(u,v)==0) {
            T[v] = u;
            if (my[v] == 0) return v;
            r++; q[r] = my[v];
        }
    }
    return 0;
}

void Enlarge(int f) {
    int x, next;
    do {
        x = T[f]; next = mx[x];
        mx[x] = f; my[f] = x;
        f = next;
    }
    while (f);
}

void subx_addy(int s) {
    int delta = oo;
    FOR(i,1,n) {vx[i]=0;vy[i] = 0;}
    vx[s] = 1;
    FOR(i,1,n)
    if (T[i]) vy[i] = 1, vx[my[i]] = 1;
    FOR(i,1,n)
    if (vx[i])
        FOR(j,1,n)
        if (!vy[j] && Get(i,j) < delta)
            delta = Get(i,j);
    FOR(i,1,n) {
        if (vx[i]) fx[i] += delta;
        if (vy[i]) fy[i] -= delta;
    }
}

void process() {
    int t, v, ans = 0;
    FOR(i,1,n) {
        t = 0;
        do {
            t = Findpath(i);
            if (t == 0) subx_addy(i);
        }
        while (t == 0);
        Enlarge(t);
    }
    vector<int> kq;
    FOR(u,1,n) {
        v = mx[u];
        if (c[u][v] < oo) ans += c[u][v], kq.pb(u);
    }
    printf("%d\n",ans);
    for (vector<int>::iterator i=kq.begin();i!=kq.end();++i)
        printf("%d %d\n",*i,mx[*i]);
}

int main() {
    //freopen("test.inp","r",stdin);
    enter();
    process();
    return 0;
}
