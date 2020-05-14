ll count_div(ll n) {
    if(n==1)
    return 1;
    ll ans=1;
    for (ll i = 2;  i <= n; ++i) 
    {
          if(n%i==0)
          {
               ll temp=1;
              while(n%i==0)
              {
                n/=i;
                temp++;
              }
              ans=(ans%mod*temp%mod)%mod;
          }
    }
    return ans;
}