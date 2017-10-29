#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>    
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>

#define fi first
#define se second
#define pb push_back
#define debug(x) cout << x << ' ';
#define debun(x) cout << x << '\n';

using namespace std;
int maximize(int &a,int b) {if (b > a) a = b; else return false; return true;}
int minimize(int &a,int b) {if (b < a) a = b; else return false; return true;}
typedef pair<int,int> ii;
typedef long long ll;
const int N = 100010;
int n, par[N], level[N];
int f[N][20];


void pre_LCA() {
    for (int i=1;i<=n;++i)
        for (int j=0;1<<j <= n;++j)
            f[i][j] = -1;
    for (int i=1;i<=n;++i)
        f[i][0] = par[i];
    for (int j=1;1<<j <= n; ++j)
        for (int i=1;i<=n;++i)
            if (f[i][j-1] != -1)
                f[i][j] = f[f[i][j-1]][j-1];
}
int get_lca(int u,int v) {
    if (level[u] < level[v]) 
        swap(u,v);
    int k = 0;
    for (k=1; 1<<k <= level[u]; ++k);
    k--;
    for (int i=k; i>=0; --i)
        if (level[u]- (1<<i) >= level[v])
            u = f[u][i];
    if (u == v)
        return u;
    for (int i=k; i>=0; --i)
        if (f[u][i] != -1 && f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

int main() {

    return 0;
}
