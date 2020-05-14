/*   CREATED BY
       STREAM_CIPHER
       28-03-2020
  */
  #include <bits/stdc++.h>
  #include <cstdio>
  using namespace std;
  typedef long long  int ll;
ll table[1000+9]; 
void min_coin(ll coins[], ll m, ll V) //this is function to find minimum coin to make V coins[] is set of avalable coin in infinit amt each 
{ 
    table[0] = 0; 
    ll MMx=1e17;
    for (int i=1; i<=V; i++) 
        table[i] = MMx; 
    for (int i=1; i<=V; i++) 
    { 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              ll sub_res = table[i-coins[j]]; 
              if ((sub_res < MMx) && (sub_res + 1 < table[i])) 
                  table[i] = sub_res + 1; 
          } 
    } 
    //return table[V]; 
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
          int n;
          cin>>n;
          ll num[2*n+9];
          ll coin[2*n+9];
          ll Mx=0;
          for(int i=0;i<n;i++)
          {
               cin>>num[i];
               Mx=max(Mx,num[i]);
          }
          ll ans=0;
          for(int i=0;i<n;i++)
               cin>>coin[i];
               
          min_coin(coin,n,Mx*2+1);//note calling min_coin by passing arg Mx*2+1 then it fill the table[] from 1 to Mx*2+1 where table[i]=minimum coin to make i;
          for(int i=0;i<n;i++)
             ans+=table[num[i]*2];
          cout<<ans<<endl;
          //cout<<INT_MAX<<endl;
       }
          
   }      