/*  CREATED BY
    STREAM_CIPHER
    16-apr-2020
*/
question
// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of 
// S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3},
//  there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
//  there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[501][501];
int solve(int a[],int n,int size,int cent)
{
	//cout<<n<<" "<<size<<" "<<cent<<endl;
	if(cent==0)
		return 1;
	if(n<=0||cent<0)
		return 0;
	if(dp[n][cent]!=0)
		return dp[n][cent];
	dp[n][cent]= solve(a,n,size,cent-a[size-n])+solve(a,n-1,size,cent);
	return dp[n][cent];

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
			int n;
			cin>>n;
			int a[n+1];
			for(int i=0;i<n;i++)
				cin>>a[i];
			int cent;
			cin>>cent;
			int ans=solve(a,n,n,cent);
			cout<<ans<<endl;
		}
}