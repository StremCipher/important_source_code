int count_div(int n) {
    if(n==1)
    return 1;
    int ans=1;
    for (int i = 2;  i <= n; ++i) 
    {
          if(n%i==0)
          {
              int temp=1;
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