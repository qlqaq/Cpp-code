#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int n,m,top,a[40000005],root[40000005];
struct segTree {
    int l,r,val;
}segTree[40000005];
int build(int l,int r,int now) {
    now=++top;
    if(l==r) {
        segTree[now].val=a[l];
        return top;
    }
    int mid=(l+r)/2;
    segTree[now].l=build(l,mid,segTree[now].l);
    segTree[now].r=build(mid+1,r,segTree[now].r);
    return now;
}
int clone(int now) {
    segTree[++top]=segTree[now];
    return top;
}
int update(int l,int r,int now,int x,int val) {
    now=clone(now);
    if(l==r) segTree[now].val=val;
    else {
        int mid=(l+r)/2;
        if(x<=mid) segTree[now].l=update(l,mid,segTree[now].l,x,val);
        else segTree[now].r=update(mid+1,r,segTree[now].r,x,val);
    }
    return now;
}
int query(int l,int r,int now,int x) {
    if(l==r) return segTree[now].val;
    else {
        int mid=(l+r)/2;
        if(x<=mid) return query(l,mid,segTree[now].l,x);
        else return query(mid+1,r,segTree[now].r,x);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    root[0]=build(1,n,0);
    for(int i=1; i<=m; i++) {
        int v,op,p,c;
        cin >> v >> op >> p;
        if(op==1) {
            cin >> c;
            root[i]=update(1,n,root[v],p,c);
        }
        else {
            cout << query(1,n,root[v],p) << endl;
            root[i]=root[v];
        }
    }
    return 0;
}