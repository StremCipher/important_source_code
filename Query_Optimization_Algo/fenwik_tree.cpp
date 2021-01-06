/*  CREATED BY
    STREAM_CIPHER
    10-oct-2020
*/
//range sum query using binary indexed tree
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
int BIT[mx];
int a[mx];
void update(int index,int value,int n)
{
    while(index<=n)
        BIT[index]+=value,index+=index&(-index);
}
int query(int index,int n)
{
    int ans=0;
    while(index>0)
        ans+=BIT[index],index-=index&(-index);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        for(int i=1;i<=n;i++)
            a[i]=1;
        for(int i=1;i<=n;i++)
            update(i,a[i],n);
        query(index,n);//to find sum from 1 to index;
}