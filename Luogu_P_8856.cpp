//P8856 [POI 2002] 火车线路
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,s,q;
struct Node{int val;int laz;}segTree[240005];
inline void pushup(int p){segTree[p].val=max(segTree[p*2].val,segTree[p*2+1].val);}
inline void pushdown(int p,int l,int r){
    if(segTree[p].laz){
        segTree[p*2].val+=segTree[p].laz;
        segTree[p*2+1].val+=segTree[p].laz;
        segTree[p*2].laz+=segTree[p].laz;
        segTree[p*2+1].laz+=segTree[p].laz;
        segTree[p].laz=0;
    }
}
void update(int p,int l,int r,int lpos,int rpos,int k){
    if(l>rpos||r<lpos)return;
    if(lpos<=l&&r<=rpos){
        segTree[p].val+=k;
        segTree[p].laz+=k;
        return;
    }
    pushdown(p,l,r);
    int mid=(l+r)/2;
    update(p*2,l,mid,lpos,rpos,k);
    update(p*2+1,mid+1,r,lpos,rpos,k);
    pushup(p);
}
int query(int p,int l,int r,int lpos,int rpos){
    if(l>rpos||r<lpos)return -2e9;
    if(lpos<=l&&r<=rpos)return segTree[p].val;
    pushdown(p,l,r);
    int mid=(l+r)/2;
    return max(query(p*2,l,mid,lpos,rpos),query(p*2+1,mid+1,r,lpos,rpos));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s>>q;
    while(q--){
        int l,r,x;
        cin >> l >> r >> x;
        update(1,1,n,l,r-1,x);
        if(query(1,1,n,l,r-1)>s){
            update(1,1,n,l,r-1,-x);
            cout << "N" << endl;
        }
        else cout << "T" << endl;
    }
    return 0;
}