#include <bits/stdc++.h>
#define int long long
using namespace std;
struct segTree{
    int sum,lazy;
    int lson,rson;
} seg[4000005];
int root[100005],a[100005],n,m,tot;

int build(int l,int r){
    int now=++tot;
    if(l==r){
        seg[now].sum=a[l];
        return now;
    }
    int mid=(l+r)/2;
    seg[now].lson=build(l,mid);
    seg[now].rson=build(mid+1,r);
    seg[now].sum=seg[seg[now].lson].sum+seg[seg[now].rson].sum;
    return now;
}

int update(int pre,int l,int r,int ql,int qr,int val){
    int now=++tot;
    seg[now]=seg[pre];
    if(ql<=l&&r<=qr){
        seg[now].sum+=val*(r-l+1);
        seg[now].lazy+=val;
        return now;
    }
    int mid=(l+r)/2;
    if(ql<=mid) seg[now].lson=update(seg[pre].lson,l,mid,ql,qr,val);
    if(qr>mid) seg[now].rson=update(seg[pre].rson,mid+1,r,ql,qr,val);
    seg[now].sum=seg[seg[now].lson].sum+seg[seg[now].rson].sum+seg[now].lazy*(r-l+1);
    return now;
}

int query(int now,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return seg[now].sum;
    int mid=(l+r)/2,ans=0;
    if(ql<=mid) ans+=query(seg[now].lson,l,mid,ql,qr);
    if(qr>mid) ans+=query(seg[now].rson,mid+1,r,ql,qr);
    int len=min(r,qr)-max(l,ql)+1;
    ans+=seg[now].lazy*len;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    root[0]=build(1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int x,y,k;
            cin>>x>>y>>k;
            root[i]=update(root[i-1],1,n,x,y,k);
        }else{
            int x,y;
            cin>>x>>y;
            cout<<query(root[i-1],1,n,x,y)<<"\n";
            root[i]=root[i-1];
        }
    }
}
