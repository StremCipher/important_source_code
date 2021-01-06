/*  CREATED BY
    STREAM_CIPHER
    05-sep-2020
*/
//Rage min query in log(n),with update in log(n)
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
int update(int l,int r,int update_index,int val,int index)
{
    if(update_index<l||update_index>r)
        return inf;
    if(l==r)
    {
        segtree[index]=a[l]+val;
        return segtree[index];
    }
    if(l!=r)
        return min(update(l,(l+r)/2,update_index,val,2*index),update((l+r)/2+1,r,update_index,val,2*index+1));
    return inf;
}
int query(int l,int r,int start,int end,int index)
{
    if(start<=l&&r<=end)
        return segtree[index];
    if(l>end||r<start)
        return inf;
    if(l==r)
        return segtree[index];
    return min(query(l,(l+r)/2,start,end,index*2),query((l+r)/2+1,r,start,end,index*2+1));
}
int creat(int l,int r,int index)
{
    if(l==r)
    {
        segtree[index]=a[l];
        return a[l];
    }
    segtree[index]=min(creat(l,(l+r)/2,2*index),creat((l+r)/2+1,r,2*index+1));
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        creat(1,n,1);
        cout<<query(1,n,5,7,1)<<endl;
        update(1,n,3,-13,1);
        update(1,n,3,13,1);
        cout<<query(1,n,1,n,1)<<endl;
}