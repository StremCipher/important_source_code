/*  CREATED BY
    STREAM_CIPHER
    07-sep-2020
*/
// use of policy based data structure,unlike in multiset we can only acces any element in log(n) time but in this 
// data structure we can also acces it's index also many more;
// note that multiset contain dublicates elements also but this data structure only contains unique elements
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds; 
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        1.oset.order_of_key (k) : Number of items strictly smaller than k .
        2.oset.find_by_order(k) : K-th element in a set (counting from zero).
        3.oset.find(value);to find a value in set
        4.oset.insert(value);
        5.oset.erase(oset.find(value));
        int n,k;
        cin>>n>>k;
        ordered_set oset;
        for(int i=1;i<=n;i++)
            oset.insert({i,i});
        vector<int>q(k);
        for(auto &i:q)
            cin>>i;
        // for(auto [x,y]:oset)
        //     cout<<x<<" "<<y<<endl;
        map<int,int>pos,dynamic_value;
        for(int i=1;i<=n;i++)
            pos[i]=i,dynamic_value[i]=i;
        int mn_ans[n+1],mx_ans[n+1];
        for(int i=1;i<=n;i++)
            mn_ans[i]=i,mx_ans[i]=i;
        for(int i=0;i<k;i++)
        {
            int x,y;
            q[i];
            x=dynamic_value[q[i]];
            y=pos[q[i]];
            int less=oset.order_of_key({x,y});
            less++;
            oset.erase(oset.find({x,y}));
            pair<int,int>ff=*oset.find_by_order(0);
            pos[q[i]]=1;
            dynamic_value[q[i]]=ff.first-1;
            oset.insert({ff.first-1,1});
            mn_ans[q[i]]=1;
            mx_ans[q[i]]=max(mx_ans[q[i]],less);
        }
        for(int i=1;i<=n;i++)
        {
           int x,y;
           x=dynamic_value[i];
           y=pos[i];
           int less=oset.order_of_key({x,y});
           less++;
           mx_ans[i]=max(mx_ans[i],less);
        }
        for(int i=1;i<=n;i++)
            cout<<mn_ans[i]<<" "<<mx_ans[i]<<endl;

}