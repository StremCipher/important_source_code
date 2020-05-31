#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

ll power(ll x,ll n,ll mod)
{
   ll result=1;
    while(n>0)
     {
        if(n%2==1)
         result=(result*x)%mod;
          x=(x*x)%mod;
          n/=2;
     }
     return result;
  
}

ll modInverse(ll a,ll m) 
{
    return power(a,m-2,m);
}
int main()
{
    //finding modulae_inverce of a under modulo M;
     ll ans,a,M;
    ans=modinverce(a,M);
    cout<<ans<<"\n";

}