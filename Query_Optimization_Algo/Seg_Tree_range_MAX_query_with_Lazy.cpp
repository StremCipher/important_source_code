/*  CREATED BY
    STREAM_CIPHER
    07-sep-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int a[mx];
int segtree[mx];
int lazyupdate[mx];
void update(int l,int r,int update_index_l,int update_index_r,int val,int index)
{
    if(l>update_index_r||r<update_index_l)//completely outside
        return;
    if(l>=update_index_l&&r<=update_index_r)//completely inside
    {
        lazyupdate[index]=max(lazyupdate[index],val); 
        return;
    }
    else//partly overlap
        segtree[index]=max(segtree[index],val);
    if(l!=r)
    {
        update(l,(l+r)/2,update_index_l,update_index_r,val,2*index);
        update((l+r)/2+1,r,update_index_l,update_index_r,val,2*index+1);
    }
}
int query(int l,int r,int start,int end,int index)
{
    segtree[index]=max(segtree[index],lazyupdate[index]);
    lazyupdate[2*index]=max(lazyupdate[2*index],lazyupdate[index]);
    lazyupdate[2*index+1]=max(lazyupdate[2*index+1],lazyupdate[index]);
    lazyupdate[index]=0;
    if(start<=l&&r<=end)
        return segtree[index];
    if(start>r||end<l)
        return 0;
    if(l==r)
        return segtree[index];
    return max(query(l,(l+r)/2,start,end,2*index),query((l+r)/2+1,r,start,end,2*index+1));
    
}
int creat(int l,int r,int index)
{
    if(l==r)
    {
        // subtree_size[index]=1;
        segtree[index]=max(segtree[index],a[l]);
        return segtree[index];
    }
    segtree[index]=max(creat(l,(l+r)/2,2*index),creat((l+r)/2+1,r,2*index+1));
    // subtree_size[index]+=subtree_size[2*index]+subtree_size[2*index+1];
    return segtree[index];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        creat(1,n,1);
        update(1,n,1,n,15,1);//replace all values from 1 to n by 15
        int val=query(1,n,1,n,1);//find max of all among 1 to n
        // update(1,n,1,n,21,1);
        // debug1(val);
}