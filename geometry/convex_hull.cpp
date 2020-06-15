/*  CREATED BY
    STREAM_CIPHER
    15-june-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const double pi=acos(-1.0);
struct pt {
    double x, y;
};
struct line {
   pt p1, p2;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt>& a) {
    vector<pt>ans;
    if (a.size() ==1)
      return ans;
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (ll i = 1; i < (ll)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    // a.clear();
    for (ll i = 0; i < (ll)up.size(); i++)
    {
      // cout<<up[i].x<<" "<<up[i].y<<endl;
        ans.push_back(up[i]);
    }
    for (ll i = down.size() - 2; i > 0; i--)
    {
      // cout<<down[i].x<<" "<<down[i].y<<endl;
        ans.push_back(down[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        ll t;
        cin>>t;
        while(t--)
        {
          ll n,q;
          cin>>n>>q;
          vector<pt>a(n);
          for(ll i=0;i<n;i++)
          {
            ll x1,y1;
            cin>>x1>>y1;
            // cout<<x1<<" "<<y1<<endl;
            a[i].x=x1;
            a[i].y=y1;
          }
          vector<pt>convex_pt=convex_hull(a); //this will return convex hull of all points a
                            //note that in case of points   0 -2
                                        0 0
                                        1 0
                                        2 4
                                        3 0
                                        1 -2
                                        3 -1
                                        -1 -1
                                        -2 -2
                                        -2 1
                                        0 2
                        both points -2,-2 and 1,-2 belong to convex polygon
                        but this algo only return any one of those poits so ,
                        if you want to remove another point too use algo how to 
                          cheak a point lie onside a polygon...
        }
}