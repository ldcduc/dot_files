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
const int N = 50010;
struct node{
    int res, sum, pre, suf; 
    node() {} 
    node(int x) {res = sum = pre = suf = x;} 
};
int n, a[N];
node T[4*N];

node join(node a, node b) {
    node c;
    c.sum = a.sum + b.sum;
    c.pre = max(a.pre, a.sum+b.pre);
    c.suf = max(b.suf, a.suf+b.sum);
    c.res = max(max(a.res, b.res), a.suf + b.pre);
    return c;
}

void update(int k,int l,int r) {
    if (l == r) {
        T[k] = node(a[l]);
        return;
    }
    int m = (l+r) >> 1;
    update(k<<1, l, m); update((k<<1)+1, m+1, r);
    T[k] = join(T[k<<1], T[(k<<1)+1]);
}

node query(int k,int l, int r, int L, int R) {
    if (l == L && r == R) return T[k];
    int m = (l+r) >> 1;
    if (R <= m)
        return query(k<<1, l, m, L, R);
    else if (L > m) 
        return query((k<<1)+1, m+1, r, L, R);
    return join(query(k<<1, l, m, L, m), query((k<<1)+1, m+1, r, m+1, R));
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    update(1,1,n);
    int q, x, y;
    scanf("%d",&q);
    for (; q; q--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1,1,n,x,y).res);
    }
    return 0;
}
