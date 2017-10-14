#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int N = 100010;
int n, Q, T[4*N], child[N], p[N];
int n_node = 0, l_node[4*N], r_node[4*N], root[N];
int n_chain, n_h, H[N], chain_of[N], pos[N], head[N];
int s[N], q[N], kn[N], it[N], next_of[N];
vector<int> ke[N];

int build(int l,int r) {
    int k = ++n_node;
    if (l == r) return k;
    int m = (l+r)>>1;
    l_node[k] = build(l,m); r_node[k] = build(m+1,r);
    return k;
}

void update(int k,int l,int r,int p) {
    if (l > p || r < p) return;
    if (l == r) {T[k] = 1-T[k]; return;}
    int m = (l+r)>>1;
    update(l_node[k],l,m,p); update(r_node[k],m+1,r,p);
    T[k] = T[l_node[k]] + T[r_node[k]];
}

int getres(int k,int l,int r,int L,int R) {
    if (L > r || R < l) return 0;
    if (L <= l && r <= R) return T[k];
    if (l != r) {
        int m = (l+r)>>1;
        return getres(l_node[k],l,m,L,R) + getres(r_node[k],m+1,r,L,R);
    }
    return 0;
}

void enter() {
    scanf("%d%d",&n,&Q);
    int u, v;
    for (int i=1;i<n;++i) {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v); ke[v].push_back(u);
        kn[u]++; kn[v]++;
    }
}

void BFS() {
    p[1] = -1;
    int l = 1, r = 1, u, v; q[1] = 1;
    while (l <= r) {
        u = q[l]; l++;
        for (vector<int>::iterator i=ke[u].begin();i!=ke[u].end();++i)
        if (*i != p[u]) p[*i] = u, child[u]++, r++, q[r] = *i;
    }
}

void hld(int u) {
    if (head[n_chain] == 0) head[n_chain] = u;
    chain_of[u] = n_chain;
    n_h++; H[n_h] = u; pos[u] = n_h;
    int next = -1;
    for (vector<int>::iterator i=ke[u].begin();i!=ke[u].end();++i)
    if (*i != p[u])
        if (next == -1 || child[*i] > child[next]) next = *i;
    if (next != -1) hld(next);
    for (vector<int>::iterator i=ke[u].begin();i!=ke[u].end();++i)
    if (*i != p[u] && *i != next) n_chain++, hld(*i);
}

void query(int u) {
    int cur = -1, l, r, m, t;
    while (u != -1) {
        t = chain_of[u];
        if (getres(root[t],pos[head[t]],pos[head[t+1]]-1,pos[head[t]],pos[u]) > 0) cur = u;
        u = p[head[chain_of[u]]];
    }
    if (cur != -1) {
        t = chain_of[cur];
        l = pos[head[chain_of[cur]]], r = pos[cur], m = (l+r)>>1;
        while (l!=m && r!=m) {
            if (getres(root[t],pos[head[t]],pos[head[t+1]]-1,pos[head[t]],m) == 0) l = m+1;
            else r = m;
            m = (l+r)>>1;
        }
        for (m=l;m<=r;++m)
        if (getres(root[t],pos[head[t]],pos[head[t+1]]-1,pos[head[t]],m) == 1) {printf("%d\n",H[m]); return;};
        printf("-1\n");
    }
    printf("-1\n");
}

void process() {
    BFS();
    hld(1); head[n_chain+1] = n+1; pos[n+1] = n+1;
    for (int i=0;i<=n_chain;++i)
        root[i] = build(pos[head[i]],pos[head[i+1]]-1);
    int c, v, t;
    for (int i=1;i<=Q;++i) {
        scanf("%d%d",&c,&v);
        if (c == 0)
            t = chain_of[v], update(root[t],pos[head[t]],pos[head[t+1]]-1,pos[v]);
        //update(1,1,n,pos[v]);
        else query(v);
    }
}

int main()
{
    //freopen("test.inp","r",stdin);
    enter();
    process();
}
