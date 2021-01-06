/*  CREATED BY
    STREAM_CIPHER
    28-apr-2020
*/
// Question
// Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) 
// (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the
// subsequence ai, ai+1, ..., aj.
#include<bits/stdc++.h>
using namespace std;
struct query
{
	int l,r,index;
};
int a[100000],final_ans[100000];
int answer=0;
int cnt[100000];
query Q[100000];
int BLOCK=320;//sqrt(100000);
//this add and remove fns depends on our logic
void add(int index)
{
    cnt[a[index]]++;
    if(cnt[a[index]]==1) answer++;
}

void remove(int index)
{
    cnt[a[index]]--;
    if(cnt[a[index]]==0) answer--;
}
bool cmp(query f,query s)
{
    if((f.l/BLOCK)!=(s.l/BLOCK))
        return (f.l/BLOCK)<(s.l/BLOCK);
    else
        return f.r<s.r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int left,right;
			cin>>left>>right;
			Q[i].index=i;
			Q[i].l=--left;
			Q[i].r=--right;
		}
		sort(Q,Q+q,cmp);
		int cl=0,cr=0;
		for(int i=0;i<q;i++)
		{
			int left=Q[i].l,right=Q[i].r;
			while(cl<left)
				remove(cl),cl++;
			while(cl>left)
				add(cl-1),cl--;
			while(cr<=right)
				add(cr),cr++;
			while(cr>(right+1))
				remove(cr-1),cr--;
			final_ans[Q[i].index]=answer;
		}
		for(int i=0;i<q;i++)
			cout<<final_ans[i]<<endl;
}
explanation:
we have taken block =320,because this algo work for n<=100000;and sqrt(100000)=320 approx
intput
10
1 2 1 1 3 1 2 2 3 1
7
1 2
1 4
2 8
3 9
5 5
5 9
8 9
query range after sorting
0 1
0 3
4 4
1 7
2 8
4 8
7 8
first select aint ranges a/t their blocks in case of tie sort a/t right values of ranges
initiainty cl=0,cr=0
.now process first query then cl become 0 and cr become 1
.process second query as we have alredy calculated ans for query cl to cr so for this query we wiint add those
 indices which are in query2 but not in query1 and we wiint remove those indices which are in query1 but not in
 query2 update cl and cr to current query range
.repeate step to for remening query

