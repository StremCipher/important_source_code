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

bool onLine(line l1, pt p) {        //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
         return true;

   return false;
}

ll direction(pt a, pt b, pt c) {
   ll val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;           //colinear
   else if(val < 0)
      return 2;
      return 1;          //clockwise direction
}

bool isllersect(line l1, line l2) {
   //four direction for two lines and pts of other line
   ll dir1 = direction(l1.p1, l1.p2, l2.p1);
   ll dir2 = direction(l1.p1, l1.p2, l2.p2);
   ll dir3 = direction(l2.p1, l2.p2, l1.p1);
   ll dir4 = direction(l2.p1, l2.p2, l1.p2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;           //they are llersecting
   if(dir1==0 && onLine(l1, l2.p1))      
      return true;
   if(dir2==0 && onLine(l1, l2.p2))         
      return true;
   if(dir3==0 && onLine(l2, l1.p1))      
      return true;
   if(dir4==0 && onLine(l2, l1.p2)) 
      return true;
   return false;
}
bool checkOnside(vector<pt>poly, ll n, pt p) {
                 
   line exline = {p, {9999999999, p.y}};   
   ll i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};    
      if(isllersect(side, exline)) {          
         if(direction(side.p1, p, side.p2) == 0)
            return true;
      }
      i = (i+1)%n;
   } while(i != 0);
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
	        pt point;
	        point.x=10;
	        point.y=10;
	        checkOnside(a,n,point);//this will return true if point lie on the polygon
        }
}