#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
int n, m, f[(int)1e6+2];
char s[(int)1e6+2], t[(int)1e6+2];

int main() {
    scanf("%s%s",s,t);
    n = strlen(s); m = strlen(t);
    f[0] = -1;
    for (int i=1,k=-1;i<m;++i) {
        while (k >= 0 && t[k+1] != t[i]) k = f[k];
        if (t[k+1] == t[i]) k++;
        f[i] = k;
    }
    for (int i=0,k=-1;i<n;++i) {
        while (k >= 0 && t[k+1] != s[i]) k = f[k];
        if (t[k+1] == s[i]) k++;
        if (k == m-1) {
            printf("%d ",i-k+1);
            k = f[k];
        }
    }
    return 0;
}
