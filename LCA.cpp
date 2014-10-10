// 
// Least Common Ancestor Implementation
// http://www.codechef.com/problems/TALCA/
//

#include <bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)

using namespace std;
typedef long long int ll;

vector<int> graph[300000];	    // Adjacency graph
int parent[20][300000];		    // parent[i][j] :: '2^i'th parent of node 'j', to be used for calculating LCA
int level[300000];	            // level[i] :: Level of node i, here level of the node node is 0 so on
int log2_[300000];
void DFS(int node, bool visited[])
{
	visited[node] = true;
	for(int i=0; i<graph[node].size(); ++i)
	{
		int v = graph[node][i];
		if(!visited[v])
		{
			parent[0][v] = node;
			for(int j=1;j<20;++j)
				parent[j][v] = parent[j-1][parent[j-1][v]];
			level[v] = level[node] + 1;
			DFS(v, visited);
		}
	}
	return ;
}

int LCA(int x, int y)
{
	if(level[x] > level[y]) swap(x,y);
	int diff = level[y] - level[x];
	while(diff)
	{
		int p = (diff&-diff);
		y = parent[(int)log2_[p]][y];
		diff -= p;
	}
	if(x==y) return x;
	for(int i=19;i>=0;--i)
	{
		if(parent[i][x] != parent[i][y]){
			x = parent[i][x], 
			y = parent[i][y];
		}
	}
	return parent[0][x];
}

void initialize_LCA()
{
	bool vis[300000];
        for(int i=1;i<300000;i++)
              if(__builtin_popcount(i)==1)
                    log2_[i] = __builtin_popcount(i-1);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<20;++i) parent[i][0] = 0;
	level[0] = 0;
	DFS(0,vis);
}
int main()
{
	int N, M;
	scanf("%d", &N);
	for(int i=0;i<N-1;++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		graph[u].push_back(v),
		graph[v].push_back(u);
	}
	scanf("%d",&M);
	initialize_LCA();
	int r , u , v , cur , ans;
	while(M--)
	{
		scanf("%d%d%d",&r,&u,&v);
		r--,u--,v--;
		if(LCA(u,r)==LCA(u,v))ans = LCA(v,r);
		else if (LCA(v,r)==LCA(u,v))ans = LCA(u,r);
		else ans = LCA(u,v);
		printf("%d\n",ans+1);
	}
	return 0;
}
