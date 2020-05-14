 /*   CREATED BY
       STREAM_CIPHER
       22-03-2020
  */
  #include <bits/stdc++.h>
  #include <cstdio>
  using namespace std;
  typedef long long  int ll;
  ll minXOR(ll arr[], ll n) 
     { 
          sort(arr, arr + n); 
         ll minXor = INT_MAX; 
         ll val = 0;  
         for (int i = 0; i < n - 1; i++) { 
             val = arr[i] ^ arr[i + 1]; 
             minXor = min(minXor, val); 
         }
         return minXor; 
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
          cout<<minXOR(a,n)<<endl;
        }
 
   }  