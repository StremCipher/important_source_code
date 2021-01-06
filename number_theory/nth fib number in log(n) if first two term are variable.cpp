/*  CREATED BY
    STREAM_CIPHER
    29-july-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define debug(a) cout<<#a<<"="<<(a)<<"\n"
#define fix_precision(n) cout << fixed << setprecision(n)
const double pi=acos(-1.0);
int inf=1e18;
const int mod=1e9+7;
const int mx=5*1000000;
int a[mx];
int mat[2][2];
int x[2][2];
bool done=false;
int a11,a12,a21,a22;
void mul(int x[2][2],int y[2][2])
{
    a11=((x[0][0]*y[0][0])%mod+(x[0][1]*y[1][0])%mod)%mod;
    a12=((x[0][0]*y[0][1])%mod+(x[0][1]*y[1][1])%mod)%mod;
    a21=((x[1][0]*y[0][0])%mod+(x[1][1]*y[1][0])%mod)%mod;
    a22=((x[1][0]*y[0][1])%mod+(x[1][1]*y[1][1])%mod)%mod;
}
void mat_pow(int n)
{
    x[0][0]=1;
    x[0][1]=0;
    x[1][0]=0;
    x[1][1]=1;
    while(n>0)
    {
        if(n%2==1)
        {
            mul(x,mat);
            x[0][0]=a11;
            x[0][1]=a12;
            x[1][0]=a21;
            x[1][1]=a22;
        }
        mul(mat,mat);
        mat[0][0]=a11;
        mat[0][1]=a12;
        mat[1][0]=a21;
        mat[1][1]=a22;
        n/=2;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int t;
        // cin>>t;
        t=1;
        while(t--)
        {
            //f1=0,f2=1;
            mat[0][0]=0,mat[0][1]=1,mat[1][0]=1,mat[1][1]=1;
            int n;
            cin>>n;
            mat_pow(n);
            cout<<x[0][0]<<endl;
        }
}