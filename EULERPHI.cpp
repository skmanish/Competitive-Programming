//
// Author  : Manish Sharma
// SPOJ    : EULER TOTIENT FUNCTION
// Problem : http://www.spoj.com/problems/ETF/
//

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define LIM 1000000
using namespace std;
typedef long long int ll;
int etf[1000010];
void precomp()
{
      int i,j;
      
      /*** Generate Euler Totient Function ***/
      for(i=1;i<=LIM;i++)etf[i] = i;
      for(i=2;i<=LIM;i++)
            if(etf[i] == i)
                  for(j=2*i;j<=LIM;j+=i)
                        etf[j] = etf[j]-(etf[j]/i);
      for(i=2;i<=LIM;i++)
            if(etf[i]==i)
                  etf[i] = i-1;
      /*** Generate Euler Totient Function ***/
}
int main()
{
      int t,n;
      ll ans;
      precomp();
      s(t);
      while(t--)
      {
            s(n);
            printf("%d\n",etf[n]);
      }
      return 0;
}
