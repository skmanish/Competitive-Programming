
// Author : Manish Sharma
// 
// Optimized Bitmask DP 
// Codeforces Contest# 259 Div 2
// http://codeforces.com/contest/454/problem/D

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;
int n,inp[105];
int dp[105][(1<<17)];
int prev[105][(1<<17)];
int used[105][(1<<17)];
int primes[17]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int fact[62];
int ans[105];
void solve()
{
	int i,j,x,s;
	for(i=0;i<(1<<17);i++)
		dp[0][i] = 0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<60;j++)
		{
			x = ((~fact[j])&((1<<17)-1));
			for(s=x;;s=(s-1)&x)
			{
				if(dp[i][s|fact[j]]==-1 || abs(inp[i]-j)+dp[i-1][s] < dp[i][s|fact[j]])
				{
					dp[i][s|fact[j]] = abs(inp[i]-j) + dp[i-1][s];
					prev[i][s|fact[j]] = s;
					used[i][s|fact[j]] = j;
				}
				if(s==0)break;
			}
		}
	}
	int mini = 0;
	for(i=1;i<(1<<17);i++)
		if(dp[n][i]<dp[n][mini] && dp[n][i]!=-1)
			mini = i;
	for(i=n;i>=1;i--)
	{
		ans[i] = used[i][mini];
		mini = prev[i][mini];
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
int main()
{	
	int i,j;
	s(n);
	for(i=1;i<=n;i++)
		s(inp[i]);
	memset(dp,-1,sizeof(dp));
	memset(fact,0,sizeof(fact));
	for(i=1;i<60;i++)
		for(j=0;j<17;j++)
			if(i%primes[j]==0)
				fact[i]|=(1<<j);
	solve();
	return 0;
}
