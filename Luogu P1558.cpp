//P1558 色板游戏
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,t,q;
struct segTree{int val,laz;}segTree[400005];
void build(int l,int r,int now) {
    if(l==r) {segTree[now].val=(1<<1);return ;}
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    segTree[now].val=segTree[now*2].val|segTree[now*2+1].val;
}
void pushdown(int now) {
    if(!segTree[now].laz) return ;
    segTree[now*2].laz=segTree[now*2+1].laz=segTree[now].laz;
    segTree[now*2].val=segTree[now*2+1].val=(1<<segTree[now].laz);
    segTree[now].laz=0;
}
void update(int l,int r,int ll,int rr,int now,int c) {
    if(l>rr||r<ll) return ;
    if(l>=ll&&r<=rr) {
        segTree[now].laz=c;
        segTree[now].val=(1<<c);
        return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    if(ll<=mid) update(l,mid,ll,rr,now*2,c);
    if(mid<rr) update(mid+1,r,ll,rr,now*2+1,c);
    segTree[now].val=segTree[now*2].val|segTree[now*2+1].val;
}
int getsum(int l,int r,int ll,int rr,int now) {
    if(l>rr||r<ll) return 0;
    if(l>=ll&&r<=rr) return segTree[now].val;
    pushdown(now);
    int mid=(l+r)/2,ans=0;
    if(ll<=mid) ans|=getsum(l,mid,ll,rr,now*2);
    if(mid<rr) ans|=getsum(mid+1,r,ll,rr,now*2+1);
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> t >> q;
    build(1,l,1);
    while(q--) {
        char op;
        cin >> op;
        if(op=='C') {
            int a,b,c;
            cin >> a >> b >> c;
            if(a>b) swap(a,b);
            update(1,l,a,b,1,c);
        }
        else {
            int a,b;
            cin >> a >> b;
            if(a>b) swap(a,b);
            int s=getsum(1,l,a,b,1),x=0;
            while(s) {
                x+=s%2;
                s/=2;
            }
            cout << x << endl;
        }
    }
    return 0;
}