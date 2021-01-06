/*  CREATED BY
    STREAM_CIPHER
    10-oct-2020
*/
// lps table
#include<bits/stdc++.h>
using namespace std;
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
int lps[mx];
//lps denotes the longest prefix of each prefix which is also a suffix
//ex-    abasdbababbaba
//     1-a              lps=1
//     2-ab             lps=0
//     3-aba            lps=1
//     4-abas           lps=0
//     5-abasd          lps=0
//     6-abasdb         lps=0
//     7-abasdba        lps=2
//     8-abasdbab       lps=0
//     9-abasdbaba      lps=3
//    10-abasdbabab     lps=0
//    11-abasdbababb    lps=0
//    12-abasdbababba   lps=2
//    13-abasdbababbab  lps=0
//    14-abasdbababbaba lps=3

void creat_lps(string a)
{
	int n=a.size();
	// int prev=0;
	int lps[n+1]={0};
	for(int i=1;i<n;i++)
	{
		int prev=lps[i-1];
		cout<<prev<<endl;
		while(prev>0&&a[i]!=a[prev])
			prev=lps[prev-1];
		if(a[prev]==a[i])
			lps[i]=prev+1;
		else
			lps[i]=prev;
	}
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	return lps[n-1];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        string a;
        cin>>a;
        creat_lps(a);//lps=longest perfect sufficx which is also a suffix

}
// important question
// https://codeforces.com/problemset/problem/1326/D2
// https://codeforces.com/problemset/problem/1200/E