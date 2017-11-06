#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(int)a;i<=(int)b;++i)
#define FORD(i,a,b) for (int i=(int)a;i>=(int)b;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 110;
int m, n, mx[N], my[N], T[N], q[N];
vector<int> ke[N];

void Enlarge(int f) {
    int x, next;
    do {
        x = T[f]; next = mx[x];
        mx[x] = f; my[f] = x;
        f = next;
    }
    while (f);
}

int Find() {
    FOR(i,1,n) T[i] = 0;
    int l = 1, r = 0, u;
    FOR(i,1,m) if (mx[i] == 0) r++, q[r] = i;
    while (l <= r) {
        u = q[l]; l++;
        for (vector<int>::iterator i=ke[u].begin();i!=ke[u].end();++i)
        if (T[*i] == 0) {
            T[*i] = u;
            if (my[*i] == 0) return *i;
            r++, q[r] = my[*i];
        }
    }
    return 0;
}

int main() {
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    int u, v;
    while (scanf("%d%d",&u,&v) != EOF) ke[u].pb(v);
    while (u = Find())
        Enlarge(u);
    int ans = 0;
    FOR(i,1,m) ans += mx[i] > 0;
    printf("%d\n",ans);
    FOR(i,1,m) if (mx[i] > 0) printf("%d %d\n",i,mx[i]);
    /* match1 */
    return 0;
}
