  /*   CREATED BY
       STREAM_CIPHER
       22-03-2020
  */
  #include <bits/stdc++.h>
  #include <cstdio>
  using namespace std;
  typedef long long  int ll;
  ll count_set_bit(ll a[],ll n,ll pattern)
  {
      int cnt=0;
      for(ll i=0;i<n;i++)
      {
          if((pattern&a[i])==pattern)
               cnt++;
      }
      return cnt;
  }

  ll max_and(ll a[],ll n)
  {
     ll ans=0;
     ll count;
     for(ll i=31;i>=0;i--)
     {
          count=count_set_bit(a,n,ans|(1ll<<i));
          //cout<<count<<endl;
          if(count>=2)
            ans|=(1ll<<i);
     } 
     return ans;
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
           ll n;
           cin>>n;
           ll a[n];
           for(ll i=0;i<n;i++)
           {
               cin>>a[i];
           }
           ll ans;
           ans=max_and(a,n);
           cout<<ans<<endl;
        }

   }      