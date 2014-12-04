// 
// Dynamic Sum of rooted subtrees with update of node
// http://www.codechef.com/TSTKAN14/problems/TYTACTIC
// Author : Manish Sharma
//
#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;
int sk[100005];
vector<int> graph[100005];
int ts;
int in[100005],out[100005],rev[100005];
int tree[300005],size;
bool vis[100005];
void dfs(int node)
{
      in[node] = ts++;
      rev[ts-1] = node;
      vis[node] = true;
      for(int i=0;i<graph[node].size();i++)
      {
            if(vis[graph[node][i]])
                  continue;
            dfs(graph[node][i]);
      }
      out[node] = ts-1;
}
void build(int n)
{
      int i;
      size = 1;
      while(size<n)
            size = size<<1;
      memset(tree,0,sizeof tree);
      for(i=0;i<n;i++)
      {
            assert(rev[i]<n);
            tree[i+size] = sk[rev[i]];
      }
      for(i=size-1;i>=1;i--)
            tree[i] = tree[2*i] + tree[2*i+1];

}
void update(int pos,int val)
{
      tree[pos+size] = val;
      for(int i=(pos+size)/2;i>=1;i>>=1)
            tree[i] =  tree[2*i] + tree[2*i+1];
}
int query(int l,int r)
{
    int ans = 0;  
    for(l=l+size,r=r+size;l<r;l>>=1,r>>=1)
    {
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
    }
    return ans;
}
void print()
{
      int i;
      printf("Tree is %d: \n",size);
      for(i=1;i<2*size;i++)
            printf("%d ",tree[i]);
      printf("\n");
}
int main()
{
      int n,m,i,a,b;
      s(n);s(m);
      for(i=0;i<n;i++)
            s(sk[i]);
      for(i=1;i<n;i++)
      {
            s(a);s(b);
            a--;b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
      }
      ts = 0;
      memset(vis,0,sizeof vis);
      dfs(0);
      build(n);
      char type[5];
      while(m--)
      {
            ss(type);
            if(type[0]=='Q')
            {
                  s(a);
                  a--;
                  printf("%d\n",query(in[a],out[a]+1));
            }
            else
            {
                  s(a);s(b);
                  a--;
                  update(in[a],b);
            }
      }
      return 0;
}
