#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

#define fi first
#define se second

using namespace std;
const int N = 2000010;
int n, m, z[N];
string s, t;

int main() {
    cin >> s >> t;
    m = t.length();
    s = t + '#' + s;
    n = s.length();
    for (int i=1,l=0,r=0;i<n;++i) {
        if (i <= r)
            z[i] = min(r-i+1,z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i+z[i]-1 > r)
            r = i+z[i]-1, l = i;
    }
    for (int i=m+1;i<n;++i)
        if (z[i] == m) printf("%d ",i-m);
    return 0;
}
