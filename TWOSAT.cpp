#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define mangam(temp,type,name,size) type temp[size]; type *name = temp + (size/2)
using namespace std;
mangam(mang0,vector<int>,ke,16010);
mangam(mang1,vector<int>,c,16010);
mangam(mang2,int,label,16010);
mangam(mang3,int,num,16010);
mangam(mang4,int,low,16010);
mangam(mang5,int,a,16010);
int n, m, cnt, tplt, b[16010], s[16010];
void enter() {
    scanf("%d%d",&n,&m);
    int u, v;
    for (;n;n--) {
        scanf("%d%d",&u,&v);
        ke[-u].push_back(v);
        ke[-v].push_back(u);
    }
}
void visit(int u) {
    s[0]++; s[s[0]] = u; cnt++; low[u] = num[u] = cnt;
    for (vector<int>::iterator i=ke[u].begin();i!=ke[u].end();++i)
    if (num[*i]) low[u] = min(low[u],num[*i]);
    else visit(*i), low[u] = min(low[u],low[*i]);
    if (num[u] == low[u]) {
        tplt++; int v; b[tplt] = u;
        do {
            v = s[s[0]]; s[0]--;
            num[v] = low[v] = 1e9;
            label[v] = tplt;
            c[u].push_back(v);
        }
        while (v != u);
    }
}
void outno() {printf("NO"); exit(0);}
void process() {
    for (int i=-m;i<=m;++i) num[i] = 0, a[i] = 0;
    cnt = tplt = s[0] = 0;
    for (int i=-m;i<=m;++i) if (!num[i]) visit(i);
    for (int i=1;i<=m;++i)
    if (label[i] == label[-i]) outno();
    s[0] = 0;
    for (int i=1;i<=tplt;++i) {
        if (a[b[i]] == 0) a[b[i]] = 1;
        if (a[b[i]] == 1) {
            for (vector<int>::iterator j=c[b[i]].begin();j!=c[b[i]].end();++j) {
                if (*j > 0) s[0]++, s[s[0]] = *j;
                a[b[label[-*j]]] = -1;
            }
        }
    }
    printf("YES\n%d\n",s[0]);
    for (int i=1;i<=s[0];++i) printf("%d ",s[i]);
}
int main()
{
    enter();
    process();
}
