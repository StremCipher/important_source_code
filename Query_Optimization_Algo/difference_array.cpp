/*  CREATED BY
    STREAM_CIPHER
    14-may-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int difference_arr[200000];
void update(int l,int r ,int val)
{
	difference_arr[l]+=val;
	difference_arr[r+1]-=val;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		memset(difference_arr,0,sizeof difference_arr);
		int query;
		cin>>query;
		while(query--)
		{
			int l,r,val;
			cin>>l>>r>>val;
			update(l,r,val);
		}
		//construct final array as prefix sum of difference_arr;
		int ans_array[20000]={0};
		for(int i=1;i<20000;i++)
		{
			ans_array[i]+=ans_array[i-1]+difference_arr[i];
		}
		//print ans_array
		for(int i=1;i<=11;i++)
			cout<<ans_array[i]<<" ";
}