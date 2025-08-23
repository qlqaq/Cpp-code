#include <bits/stdc++.h>
using namespace std;
const int MAXN=1900005;
struct segTree{int l,r,val,laz;}segTree[MAXN];
int n,q,b[MAXN];
void build(int l,int r,int now) {
    segTree[now].l=l,segTree[now].r=r;
    if(l==r) {segTree[now].val=!b[l];return ;}
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    segTree[now].val=segTree[now*2].val+segTree[now*2+1].val;
}
void pushdown(int now) {
    if(!segTree[now].laz) return ;
    segTree[now*2].laz=segTree[now*2+1].laz=segTree[now].laz;
    segTree[now].laz=segTree[now].val=0;
}
int getsum(int l,int r,int now) {
    if(segTree[now].l==l&&segTree[now].r==r) return (!segTree[now].laz)*segTree[now].val;
    pushdown(now);
    if(r<=segTree[now*2].r) return getsum(l,r,now*2);
    else if(l>=segTree[now*2+1].l) return getsum(l,r,now*2+1);
    else return getsum(l,segTree[now*2].r,now*2)+getsum(segTree[now*2+1].l,r,now*2+1);
}
void update(int l,int r,int now) {
    if(segTree[now].l==l&&segTree[now].r==r) {segTree[now].laz=1;return ;}
    pushdown(now);
    if(r<=segTree[now*2].r) update(l,r,now*2);
    else if(l>=segTree[now*2+1].l) update(l,r,now*2+1);
    else {
        update(l,segTree[now*2].r,now*2);
        update(segTree[now*2+1].l,r,now*2+1);
    }
    segTree[now].val=(!segTree[now*2].laz)*segTree[now*2].val+(!segTree[now*2+1].laz)*segTree[now*2+1].val;
}
signed main() {
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        int s;
        cin >> s;
        for(int j=1; j<=s; j++) {
            int x;
            cin >> x;
            b[x]=1;
        }
    }
    build(1,n,1);
    for(int i=1; i<=q; i++) {
        int op;
        cin >> op;
        if(op==1) {
            int x,y;
            cin >> x >> y;
            cout << getsum(1,n,1)-getsum(x,y,1) << endl;
        }
        else {
            int x,y,z;
            cin >> x >> y >> z;
            update(x,y,1);
        }
    }
    return 0;
}