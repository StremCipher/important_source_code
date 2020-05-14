/*  CREATED BY
    STREAM_CIPHER
    16-apr-2020
*/
question:
	// Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of 
	// edits (operations) required to convert ‘str1’ into ‘str2’.
	// Insert
	// Remove
	// Replace
	// All of the above operations are of equal cost.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[500][500];
int solve(string a,string b,int m,int n)
{
	//cout<<m<<" "<<n<<endl;
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(a[m-1]==b[n-1])
		return solve(a,b,m-1,n-1);
	//cout<<m<<" "<<n<<endl;
	if(dp[m][n]==0)
	{
		dp[m][n]= (1+min(min(solve(a,b,m,n-1),solve(a,b,m-1,n)),solve(a,b,m-1,n-1)));
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
		int t;
		cin>>t;
		while(t--)
		{
			memset(dp,0,sizeof dp);
			int m,n;
			cin>>m>>n;
			string a,b;
			cin>>a>>b;
			//cout<<a<<"\n"<<b<<endl;
			int ans=solve(a,b,m,n);
			cout<<ans<<endl;
		}
}