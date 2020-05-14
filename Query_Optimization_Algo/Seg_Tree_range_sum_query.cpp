/*   CREATED BY
     STREAM_CIPHER
     23-03-2020
*/
// qustion this is also a range sum query with update;
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long  int ll;
ll  update(ll seg_tree[],ll start,ll end,ll index,ll diff,ll current_node)
{
   if(index>end||index<start)
        return 0;
   seg_tree[current_node]+=diff;
   if(start!=end)
   {
        update(seg_tree,start,(start+end)/2,index,diff,2*current_node);
        update(seg_tree,(start+end)/2+1,end,index,diff,2*current_node+1);

   }

}
ll  query(ll seg_tree[],ll start,ll end,ll l,ll r,ll current_node)
{
   if(l<=start&&r>=end)
   {
        return seg_tree[current_node];
   }
   if(l>end||r<start)
        return 0;
   return   query(seg_tree,start,(start+end)/2,l,r,2*current_node)+
            query(seg_tree,(start+end)/2+1,end,l,r,2*current_node+1);
}
ll  create_seg_tree(ll a[],ll seg_tree[],ll start,ll end,ll current_node)
{
   if(start==end)
   {
        seg_tree[current_node]=a[start];
        return a[start];
   }

    seg_tree[current_node]=create_seg_tree(a,seg_tree,start,(start+end)/2,current_node*2)+
                      create_seg_tree(a,seg_tree,(start+end)/2+1,end,current_node*2+1);
    return seg_tree[current_node];
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
         ll x = (int)(ceil(log2(n)));
         ll max_size = 2*(int)pow(2, x) - 1;  
         ll seg_tree[max_size]={0};
         create_seg_tree(a,seg_tree,0,n-1,1);
         /*
         for(int i=1;i<=max_size-1;i++)
             cout<<i<<"="<<seg_tree[i]<<"\n ";
             */
         ll ans;
         int q;
         cin>>q;
         while(q--)
         {
             ll index,value,diff,l,r;
             int type;
             cin>>type>>l>>r;
             if(type==1)
             {
                  l--;
                  r--;
                  ans=query(seg_tree,0,n-1,l,r,1);
                  cout<<ans<<endl;
             }
              else
              {
                  index=l;
                  value=r;
                  index--;
                  //cout<<a[4]<<endl;
                  if(index<=n-1&&index>=0)
                   {
                       diff=value-a[index];
                       a[index]=value;
                       //cout<<"DIFF="<<diff<<endl;
                       update(seg_tree,0,n-1,index,diff,1);
                   }
                   //cout<<a[4]<<endl;
              }
              
         }
         
      }
 }      