//
// SPOJ : DISUBSTR : Distinct Substrings
// Suffix Array Computation   O(nlog^2n)
// Longest Common Prefix      O(logn)
//
#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;
struct triplet{
      int val1,val2,ind;
};
char inp[1005];
int SA[15][1005],logmax,l;
int sortedSAindex[1005];
triplet t[1005];
inline bool operator < (const triplet a,const triplet b)
{
      if(a.val1<b.val1)return true;
      else if(a.val1==b.val1 && a.val2<b.val2)return true;
      return false;
}
int computeLCP(int ind1,int ind2)
{
      int i,ret=0;
      if(ind1==ind2)
            return (l-ind1);
      for(i=logmax;i>=0 && ind1<l && ind2<l;i--)
            if(SA[i][ind1]==SA[i][ind2])
                  ret+=(1<<i), ind1+=(1<<i), ind2+=(1<<i);
      return ret;
}
int computeSA()
{
      int stp,cnt,i,rank;
      l = strlen(inp);
      if(l==1)return 1;
      for(i=0;i<l;i++)
            SA[0][i] = inp[i]-'A';
      logmax = 1;
      while((1<<logmax)<l)
            logmax = logmax++;
      for(stp=1,cnt=1;cnt<l;stp++,cnt=2*cnt)
      {
            for(i=0;i<l;i++)
            {
                  t[i].val1 = SA[stp-1][i];
                  if(i+cnt<l)
                        t[i].val2 = SA[stp-1][i+cnt];
                  else
                        t[i].val2 = -1;
                  t[i].ind = i;
            }
            sort(t,t+l);
            rank = 0;
            for(i=0;i<l;i++)
            {
                  if(i>0 && t[i].val1==t[i-1].val1 && t[i].val2==t[i-1].val2)
                        SA[stp][t[i].ind] = rank;
                  else SA[stp][t[i].ind] = ++rank;
            }
      }
      stp--;
      for(i=0;i<l;i++)
            sortedSAindex[SA[stp][i]-1] = i;
      int ans = 0;
      for(i=0;i<l;i++)
      {
            if(i==0)
                  ans += (l-sortedSAindex[i]);
            else
                  ans += (l-sortedSAindex[i]-computeLCP(sortedSAindex[i],sortedSAindex[i-1]));
      }
      return ans;
}
int main()
{
      int t;
      s(t);
      while(t--)
      {
            ss(inp);
            printf("%d\n",computeSA());
      }
      return 0;
}
