/*  CREATED BY
    STREAM_CIPHER
    21-july-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(a) cout<<#a<<"="<<(a)<<"\n"
#define fix_precision(n) cout << fixed << setprecision(n)
// fill(vis, vis + n + 1, false);
const double pi=acos(-1.0);
ll inf=0x3f3f3f3f;
vector<int>arr;
int n;
bool find(int sum)
{
    int table[n][sum];
    memset(table,0,sizeof table);
    sort(arr.begin(),arr.end());
    table[0][arr[0]]=1;
    bool possible=false;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(table[i-1][j]!=0)
            {
                table[i][j]=1;
                table[i][j+arr[i]]=1;
            }
        }
        table[i][arr[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(table[i][sum]==1)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        cin>>n;
        for(int i=0,in;i<n;i++)
            cin>>in,arr.push_back(in);
        int sum=0;
        cin>>sum;
        bool is=find(sum);
}