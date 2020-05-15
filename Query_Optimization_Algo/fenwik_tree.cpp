 /*  CREATED BY
    STREAM_CIPHER
    29-apr-2020
*/
// question
// given array of integrs and q quries of two type in type 1  query we need to answer sum of elements of array in given
// range in type 2 query we need to update a particular element;
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll BIT_array[300000];
//query fns depends on question logic;
ll query(int index,int n)
{
	index++;
	ll ans=0;
	while(index>0)
	{
		ans+=BIT_array[index];
		index-=index&(-index);
	}
	return ans;
}
void updateBIT(int index,ll value,int n)
{
	index++;
	while(index<=n)
	{
		BIT_array[index]+=value;
		index+=index&(-index);
	}
}

constructBIT(ll a[],int n)
{
	memset(BIT_array,0,sizeof BIT_array);
	for(int i=0;i<n;i++)
	{
		updateBIT(i,a[i],n);
	}	
}
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
		ll a[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		constructBIT(a,n);
		for(int i=1;i<=n;i++)
			cout<<BIT_array[i]<<" ";
		cout<<endl;
		int q;
		cin>>q;
		while(q--)
		{
			int type,l,r;
			cin>>type>>l>>r;
			if(type==1)
			{
				l--,r--;
				ll ans=query(r,n)-query(l-1,n);
				cout<<ans<<endl;
			}
			else
			{
				l--;
				ll diff=r-a[l];
				updateBIT(l,diff,n);
			}
		}
}
