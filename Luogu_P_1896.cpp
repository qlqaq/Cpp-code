#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int n,k,w;
int dp[15][105][1005],f[1005],num[1005],len;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<(1<<n); i++) {
        int sum=0,x=i;
        while(x) {
            sum+=x%2;
            x/=2;
        }
        num[i]=sum;
        if((((i>>1)|(i<<1))&i)==0) f[++len]=i;
    }
    dp[0][0][0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=len; j++) {
            int s1=f[j],cnt=num[f[j]];
            for(int l=1; l<=len; l++) {
                int s2=f[l];
                if(((s2|(s2<<1)|(s2>>1))&s1)==0) {
                    for(int z=0; z<=k; z++) {
                        if(z-cnt>=0) dp[i][z][s1]+=dp[i-1][z-cnt][s2];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1; i<=len; i++) ans+=dp[n][k][f[i]];
    cout << ans;
    return 0;
}