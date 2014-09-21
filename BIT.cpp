
// Author : Manish Sharma
// 
// Binary Indexed Tree (BIT) 
// SPOJ : MSE06H
// http://www.spoj.com/problems/MSE06H/

#include<bits/stdc++.h>
#define s(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;

pair<ll,ll> inp[1000006];
ll paths[1004];
ll tree[4000];
ll read(ll idx)
{
      ll sum = 0;
      while(idx > 0)
      {
            sum += tree[idx];
            idx = idx - (idx&(-idx));
      }
      return sum;
}
ll update(ll idx,ll val,ll size)
{
      while(idx<=size)
      {
            tree[idx] += val;
            idx = idx + (idx&(-idx));
      }
}
int main()
{
      ll n,m,k,t,i,j,x,tcase;
      s(t);
      for(tcase=1;tcase<=t;tcase++)
      {
            s(n);s(m);s(k);
            for(i=0;i<k;i++)
            {
                  s(inp[i].first);
                  s(inp[i].second);
            }
            sort(inp,inp+k);
            memset(paths,0,sizeof(paths));
            memset(tree,0,sizeof(tree));
            for(i=0;i<k;i++)paths[inp[i].first]++;
            for(i=1;i<=n;i++)paths[i] += paths[i-1];
            ll powof2 = 0;
            while((1<<powof2)<m)
                  powof2 ++;
            m = 1<<powof2;
            ll ans = 0;
            for(i=0;i<k;i++)
            {
                  j=i;
                  while(j<k && inp[j].first==inp[i].first)
                        j++;
                  j--;
                  for(x=i;x<=j;x++)
                  {
                        n = paths[inp[x].first-1];
                        n -= read(inp[x].second);
                        ans += n;
                  }
                  for(x=i;x<=j;x++)
                        update(inp[x].second,1,m);
                  i=j;
            }
            printf("Test case %lld: %lld\n",tcase,ans);
      }
      return 0;
}
