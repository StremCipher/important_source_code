/*  CREATED BY
    STREAM_CIPHER
    26-may-2020
*/
// question given an array you need to answer several query l,r in which you need to 
// find minimum element from array in range l and r
// time compexity o(1)//per query
//                o(nlogn)//building sparsetable
//                o(nlogn)//space complexity
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int exp(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x);
        x=(x*x);
        n=n/2;
    }
    return result;
}
int sparse_table[20][200000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		int n;
		cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		memset(sparse_table,-1,sizeof sparse_table);
		for(int i=0;i<n;i++)
			sparse_table[0][i]=a[i];
		for(int i=1;i<=log2(n);i++)
			for(int j=0;(j+(1<<i)-1)<n;j++)
				sparse_table[i][j]=min(sparse_table[i-1][j],sparse_table[i-1][j+(1<<(i-1))]);
		// for(int i=0;i<=log2(n);i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 		cout<<sparse_table[i][j]<<" ";
		// 	cout<<endl;
		// }
		int q;
		cin>>q;
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			int row_index=log2(r-l+1);
			int col1=l-1;
			int col2=(r+1-(exp(2,(log2(r-l+1)))))-1;
			cout<<min(sparse_table[row_index][col1],sparse_table[row_index][col2])<<endl;
		}
}