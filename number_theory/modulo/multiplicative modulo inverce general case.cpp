#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int power(int x, int y, int p) 
{ 
    int res = 1;   
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
int main()
{
    //finding modulae_inverce of a under modulo M;
     ll ans,a,M;
    ans=modinverce(a,M);
    cout<<ans<<"\n";

}