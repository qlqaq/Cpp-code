//B4169 [GXPC-S 2024] 演唱会
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[400005];
struct segTree{int val,max;}segTree[400005];
void build(int l,int r,int now) {
    if(l==r) {segTree[now].val=segTree[now].max=a[l];return ;}
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    segTree[now].val=segTree[now*2].val+segTree[now*2+1].val;
    segTree[now].max=max(segTree[now*2].max,segTree[now*2+1].max);
}
void update(int l,int r,int x,int v,int now) {
    if(l==r) {
        if(l==x) segTree[now].val=v,segTree[now].max=v;
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(l,mid,x,v,now*2);
    else update(mid+1,r,x,v,now*2+1);
    segTree[now].val=segTree[now*2].val+segTree[now*2+1].val;
    segTree[now].max=max(segTree[now*2].max,segTree[now*2+1].max);
}
int getsum(int l,int r,int ll,int rr,int now) {
    if(l>rr||r<ll) return 0;
    if(l>=ll&&r<=rr) return segTree[now].val;
    int mid=(l+r)/2,ans=0;
    ans+=getsum(l,mid,ll,rr,now*2);
    ans+=getsum(mid+1,r,ll,rr,now*2+1);
    return ans;
}
int getmax(int l,int r,int ll,int rr,int now) {
    if(l>rr||r<ll) return INT_MIN;
    if(l>=ll&&r<=rr) return segTree[now].max;
    int mid=(l+r)/2,maxn=0;
    maxn=max(maxn,getmax(l,mid,ll,rr,now*2));
    maxn=max(maxn,getmax(mid+1,r,ll,rr,now*2+1));
    return maxn;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1,n,1);
    while(m--) {
        int op,x,y;
        cin >> op >> x >> y;
        if(op==1) cout << getsum(1,n,x,y,1)*getmax(1,n,x,y,1) << endl;
        else update(1,n,x,y,1);
    }
    return 0;
}