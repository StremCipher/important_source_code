 /*   CREATED BY
       STREAM_CIPHER
       22-03-2020
  */
  #include <bits/stdc++.h>
  #include <cstdio>
  using namespace std;
  typedef long long  int ll;
 ll max_xor(ll arr[], ll n) 
{ 
    ll maxx = 0, mask = 0; 
  
    set<ll> se; 
  
    for (ll i = 30; i >= 0; i--) { 
  
        // set the i'th bit in mask 
        // like 100000, 110000, 111000.. 
        mask |= (1 << i); 
  
        for (ll i = 0; i < n; ++i) { 
  
            // Just keep the prefix till 
            // i'th bit neglecting all 
            // the bit's after i'th bit 
            se.insert(arr[i] & mask); 
        } 
  
        ll newMaxx = maxx | (1 << i); 
  
        for (ll prefix : se) { 
  
            // find two pair in set 
            // such that a^b = newMaxx 
            // which is the highest 
            // possible bit can be obtained 
            if (se.count(newMaxx ^ prefix)) { 
                maxx = newMaxx; 
                break; 
            } 
        } 
  
        // clear the set for next 
        // iteration 
        se.clear(); 
    } 
  
    return maxx; 
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
           for(int i=0;i<n;i++)
               cin>>a[i];
          cout<<max_xor(a,n)<<endl;
        }
 
   }  