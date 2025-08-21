//P1558 色板游戏
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int l,t,q;
struct segTree{int val,sum;bool laz;}segTree[400005];
void build(int l,int r,int now) {
    segTree[now].val=segTree[now].sum=1;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
}
void pushdown(int now) {
    if(!segTree[now].laz) return ;
    segTree[now*2].laz=segTree[now*2+1].laz=segTree[now].laz;
    segTree[now*2].val=segTree[now*2+1].val=segTree[now].val;
    segTree[now].laz=0;
}
void pushup(int now) {
    
}
void update(int l,int r,int ll,int rr,int now,int c) {
    if(l>rr||r<ll) return ;
    if(l>=ll&&r<=rr) {
        segTree[now].val=c;
        segTree[now].sum=1;
        return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    if(l<=mid) update(l,mid,ll,rr,now*2);
    if(mid<r) update(mid+1,r,ll,rr,now*2+1);
    pushup(now);
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
            getsum();
        }
    }
    return 0;
}