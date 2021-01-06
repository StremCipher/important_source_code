/*  CREATED BY
    STREAM_CIPHER
    29-aug-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout << fixed << setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int a[mx];
int segtree[mx];
int lazyupdate[mx];
int subtree_size[mx];
// max size of array of segtree;
// int x=(int)(ceil(log2(n)));
// int max_size=2*(int)pow(2,x)-1; 
int cnt_overlap(int l,int r,int l1,int r1)
{
	if(l1>=l&&l1<=r&&r1>=r)
		return (r-l1+1);
	if(r1>=l&&r1<=r&&l1<=l)
		return r1-l+1;
	if(l1>=l&&r1<=r)
		return r1-l1+1;
	return 0;
} 
void update(int l,int r,int update_index_l,int update_index_r,int val,int index)
{
    if(l>update_index_r||r<update_index_l)//completely outside
        return;
    if(l>=update_index_l&&r<=update_index_r)//completely inside
    {
    	lazyupdate[index]+=val; 
    	return;
    }
    else//partly overlap
    	segtree[index]+=cnt_overlap(l,r,update_index_l,update_index_r)*val;
    if(l!=r)
    {
        update(l,(l+r)/2,update_index_l,update_index_r,val,2*index);
        update((l+r)/2+1,r,update_index_l,update_index_r,val,2*index+1);
    }
}
int query(int l,int r,int start,int end,int index)
{
	segtree[index]+=lazyupdate[index]*subtree_size[index];
    lazyupdate[2*index]+=lazyupdate[index];
    lazyupdate[2*index+1]+=lazyupdate[index];
    lazyupdate[index]=0;
    if(start<=l&&r<=end)
        return segtree[index];
    if(start>r||end<l)
        return 0;
    if(l==r)
    	return segtree[index];
    return query(l,(l+r)/2,start,end,2*index)+query((l+r)/2+1,r,start,end,2*index+1);
    
}
int creat(int l,int r,int index)
{
    if(l==r)
    {
    	subtree_size[index]=1;
        segtree[index]=a[l];
        return a[l];
    }
    segtree[index]=creat(l,(l+r)/2,2*index)+creat((l+r)/2+1,r,2*index+1);
    subtree_size[index]+=subtree_size[2*index]+subtree_size[2*index+1];
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
        //all are 1 base indexing
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        creat(1,n,1);
        for(int i=1;i<=16;i++)
            cout<<segtree[i]<<" ";
        cout<<endl;
        cout<<query(1,n,2,3,1)<<endl;
        update(1,n,1,5,10,1);
        update(1,n,1,5,-10,1);
        cout<<query(1,n,2,4,1)<<endl;
}
