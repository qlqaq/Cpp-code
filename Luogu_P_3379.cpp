#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int n,m,s,f[1000005][35],dep[1000005];
vector<int> v[1000005];
bool vis[1000005];
void dfs(int u,int fa) {
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=0; i<v[u].size(); i++) {
        int to=v[u][i];
        if(to!=fa) dfs(to,u);
    }
}
int lca(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=30; i>=0; i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
    if(u==v) return u;
    for(int i=30; i>=0; i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
void init() {
    for(int j=1; j<=30; j++) {
        for(int i=1; i<=n; i++) {
            if(f[i][j-1]!=-1) f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i=1; i<n; i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(f,-1,sizeof(f));
    dfs(s,0);
    init();
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        cout << lca(u,v) << endl;
    }
    return 0;
}