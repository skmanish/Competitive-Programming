
// Author : Manish Sharma
// 
// Set Union 
// SPOJ Problem : Dark roads
// http://www.spoj.com/problems/ULM09/

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
using namespace std;
typedef long long int ll;
typedef struct edge{
	int x,y,w;
} edge;
bool operator< (const edge &l, const edge &r)
{
	return (l.w < r.w);
}
edge inp[200005];
short visited[200005];
int p[200005],rank[200005];
int findset(int node)
{
	if(p[node]!=node)
		p[node]=findset(p[node]);
	return p[node];
}
inline bool mergeset(int x,int y)
{
	int px = findset(x);
	int py = findset(y);
	if(px == py)return false;
	if(rank[px]<rank[py])
		p[px] = py;
	else
		p[py] = px;
	if(rank[px] == rank[py])
		rank[px] = rank[px] + 1;
	return true;
}
int main()
{
	int n,i,m,x,y,w;
	int res,total,count;
	while(1)
	{
		s(n);
		s(m);
		res = 0; total = 0; count=0;
		if(!(n && m))
			return 0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&(inp[i].x),&(inp[i].y),&(inp[i].w));
			total += inp[i].w;
		}
		sort(inp,inp+m);
		for(i=0;i<n;i++)
		{
			p[i]=i;
			rank[i]=0;
		}
		for(i=0;i<m;i++)
		{
			if(count == n-1)
				break;
			bool temp = mergeset(inp[i].x,inp[i].y);
			if(temp)
			{
				res += inp[i].w;
				count++;
			}
		}
		printf("%d\n",total-res);
	}
	return 0;
}
