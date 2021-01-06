/*  CREATED BY
    STREAM_CIPHER
    05-sep-2020
*/
#include<bits/stdc++.h>
using namespace std;
void __print(long long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long int
#define double long double
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int parent[mx];
int size[mx];
int find(int x)
{
    while(x!=parent[x])
        x=parent[x];
    return x;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void join(int x,int y)//it join the two set haveing element x and y respectively
{
    x=find(x);
    y=find(y);
    if(size[x]<size[y])
        swap(x,y);
    size[x]+=size[y];
    parent[y]=x;//connect parent of smaller set to larger set always
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        for(int i=1;i<=100;i++)
            parent[i]=i,size[i]=1;        
}