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
double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > pi)
      dtheta -= 2*pi;
   while (dtheta < -pi)
      dtheta += 2*pi;

   return(dtheta);
}
int InsidePolygon(vector<pt>polygon,int n,pt p)
{
   int i;
   double angle=0;
   pt p1,p2;

   for (i=0;i<n;i++) {
      p1.x = polygon[i].x - p.x;
      p1.y = polygon[i].y - p.y;
      p2.x = polygon[(i+1)%n].x - p.x;
      p2.y = polygon[(i+1)%n].y - p.y;
      angle += Angle2D(p1.x,p1.y,p2.x,p2.y);
   }
    if (abs(angle) < pi)
      return(false);
   else
      return(true);
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
          InsidePolygon(a,n,point);//this will return true if point lie inside or on the polygon
        }
}