#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
const int MOD=1e8;
int n,m,a[15][15],f[15][1<<15],x[15];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            x[i]=(x[i]<<1)+a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            
        }
    }
    return 0;
}