/*  CREATED BY
    STREAM_CIPHER
    20-july-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(a) cout<<#a<<"="<<(a)<<"\n"
#define fix_precision(n) cout << fixed << setprecision(n)
const double pi=acos(-1.0);
ll inf=0x3f3f3f3f;
int cpd[2000000];
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
    for(int i=2;i<=n;i++)
    {
        if(cpd[i]==i)
        {
            for(int j = 2*i;j<=n;j+=i)
            {
                cpd[j]=i;
            }
        }
    }
} 
vector<int> find(int n)
{
	vector<int>ans;
	while(n!=1)
	{
		ans.push_back(cpd[n]); 
		n = n / cpd[n]; 
	}
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        SieveOfEratosthenes(500000);
        int n;
        cin>>n;
        vector<int>prime_factor=find(n);
}