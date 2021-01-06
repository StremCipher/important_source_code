/*  CREATED BY
    STREAM_CIPHER
    18-apr-2020
*/
  // question:
// Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].
// 1. Matrix[r+1][c]
// 2. Matrix[r+1][c-1]
// 3. Matrix[r+1][c+1]
// Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
  
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[500][500];
ll N;
ll solve(ll a[500][500],ll m,ll n)
{
	//cout<<m<<" "<<n<<endl;
	if(m<0||m>=N)
		return 0;
	if(n<0||n>=N)
		return 0;
	if(m==0)
			return a[m][n];
	//cout<<m<<" "<<n<<endl;
	if(dp[m][n]==0)
	{
		dp[m][n]= (a[m][n]+max(max(solve(a,m-1,n+1),solve(a,m-1,n)),solve(a,m-1,n-1)));
		//cout<<dp[m][n]<<endl;
		return dp[m][n];
	}	
	else
		return dp[m][n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		ll t;
		cin>>t;
		//cout<<t<<endl;
		while(t--)
		{
			cin>>N;
			ll a[500][500];
			for(ll i=0;i<N;i++)
				for(ll j=0;j<N;j++)
					cin>>a[i][j];

				ll ans=0;
				for(int i=1;i<=N;i++)
				{
				   memset(dp,0,sizeof dp);
				   ans=max(ans,solve(a,N-1,N-i));
				   //cout<<ans<<endl;
				}
				cout<<ans<<endl;
		}
}