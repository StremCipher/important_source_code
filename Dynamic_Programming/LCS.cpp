/*  CREATED BY
    STREAM_CIPHER
    18-apr-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
Question:
//LONGEST COMMON SUBSEQUENCE OF A and B;
int dp[500][500];
int solve(string a,string b,int m,int n)
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			{
				if(i==0||j==0)
				{
					dp[i][j]=0;
					continue;
				}
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
	}
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
			int m,n;
			cin>>m>>n;
			string a,b;
			cin>>a>>b;
			memset(dp,0,sizeof dp);
			int ans=solve(a,b,m,n);
			cout<<ans<<endl;
		}
}