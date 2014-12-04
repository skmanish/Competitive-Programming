
// Author : Manish Sharma
// Code   : Matrix Exponentiation
// Problem: www.codechef.com/NOV14/problems/CHEFWORD
//

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define slf(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;
double inp[26][26],res[26][26];
void cpy(double src[26][26],double dest[26][26])
{
      int i,j;
      for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                  dest[i][j] = src[i][j];
}
void print(double inp[26][26])
{
      int i,j;
      for(i=0;i<26;i++)
      {
            for(j=0;j<26;j++)
                  printf("%.3lf ",inp[i][j]);
            printf("\n");
      }
}
void mult(double mat1[26][26],double mat2[26][26],double mat3[26][26])
{
      int i,j,k;
      for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                  mat3[i][j] = 0;
      for(i=0;i<26;i++)
            for(j=0;j<26;j++)
                  for(k=0;k<26;k++)
                        mat3[i][j] += (mat1[i][k]*mat2[k][j]);
}
void powmod(double res[26][26],double start[26][26],int k)
{
      double temp[26][26];
      while(k)
      {
            if(k&1)
            {
                  mult(res,start,temp);
                  cpy(temp,res);
            }
            mult(start,start,temp);
            cpy(temp,start);
            k>>=1;
      }
}
char str[100005][5];
char source[100005];
int hash(char str[])
{
      int i,l = strlen(str);
      int ans = 10000000*l;
      int temp = 0;
      for(i=0;i<l;i++)
            temp = temp*26 + (str[i]-'a') ;
      return ans + temp;
}
int main()
{
      int t,n,k,i,j;
      s(t);
      while(t--)
      {
            s(n);s(k);
            ss(source);
            for(i=0;i<26;i++)
                  for(j=0;j<26;j++)
                        slf(inp[i][j]);
            memset(res,0,sizeof res);
            for(i=0;i<26;i++)
                  res[i][i] = 1;
            powmod(res,inp,k);
            double ans = 0;
            double temp ;
            int l1=strlen(source),l2;
            map<int,int> mp;
            for(i=0;i<n;i++)
            {
                  ss(str[i]);
                  int temp1 = hash(str[i]);
                  if(mp[temp1])continue;
                  mp[temp1] = 1;
                  l2 = strlen(str[i]);
                  temp = 1;
                  if(l2==l1)
                  {      for(j=0;j<l1;j++)
                              temp = temp*res[source[j]-'a'][str[i][j]-'a'];
                        ans += temp;
                  }
            }
            printf("%.8lf\n",ans);
      }
      return 0;
}
