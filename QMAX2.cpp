#include <iostream>

using namespace std;
const int N = 50002;
int T[4*N] = {0}, lazy[4*N] = {0};

void Update(int *T,int *lazy,int k,int l,int r,int L,int R,int v) {
    T[k] += lazy[k];
    if (l!=r) lazy[k*2] += lazy[k], lazy[(k<<1)+1] += lazy[k];
    lazy[k] = 0;
    // 
    if (r < L || l > R) return;
    if (L <= l && r <= R) {
        T[k] += v;
        if (l!=r) lazy[k<<1] += v, lazy[(k<<1)+1] += v;
        return;
    }
    int mid = (l+r)>>1;
    Update(T,lazy,k<<1,l,mid,L,R,v);
    Update(T,lazy,(k<<1)+1,mid+1,r,L,R,v);
    T[k] = max(T[k<<1],T[(k<<1)+1]);
}

int Get_max(int *T,int *lazy,int k,int l,int r,int L,int R) {
    T[k] += lazy[k];
    if (l!=r) lazy[k*2] += lazy[k], lazy[(k<<1)+1] += lazy[k];
    lazy[k] = 0;
    //
    if (r < L || l > R) return -1e9;
    if (L <= l && r <= R) 
        return T[k];
    int mid = (l+r)>>1;
    return max(
        Get_max(T,lazy,k<<1,l,mid,L,R),
        Get_max(T,lazy,(k<<1)+1,mid+1,r,L,R)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (;q;q--) {
        int c, x, y, v;
        cin >> c;
        if (c) {
            cin >> x >> y;
            cout << Get_max(T,lazy,1,1,n,x,y) << '\n';
        }
        else {
            cin >> x >> y >> v;
            Update(T,lazy,1,1,n,x,y,v);
        }
    }
    return 0;
}
