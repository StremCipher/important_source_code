/*  CREATED BY
    STREAM_CIPHER
    12-may-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int cpd[1000000];
void SieveOfEratosthenes(int n) 
{ 
    memset(cpd,0,sizeof cpd);
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cpd[p]=p;
    for(int i=2;i<=100008;i++)
    {
        if(cpd[i]==i)
        {
            for(int j = 2*i;j<=100000;j+=i)
            {
                cpd[j]=i;
            }
        }
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
        SieveOfEratosthenes(100000);

}