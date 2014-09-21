// 
// Matrix Exponentiation
//

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define MOD 1000000007
#define SIZE 30                           // Max dimension of matrix
using namespace std;
typedef long long int ll;
int n,m;
int A[SIZE][SIZE],res[SIZE][SIZE],prod[SIZE][SIZE];
ll modexp(ll a,ll b)
{
      if(b==0)return 1;
      if(b==1)return a;
      ll temp = modexp(a,b/2);
      temp = (temp*temp)%MOD;
      if(b&1)temp = (temp*a)%MOD;
      return temp;
}
void fillA(int m)
{
      int i,j;
      memset(A,0,sizeof(A));
      for(i=0;i<m;i++)
      {
            if(i-1>=0)
            {
                  if(i-2>=0)A[i][i-2]++;
                  A[i][i]++;
                  A[i][i-1]++;
            }
            if(i+1<m)
            {
                  A[i][i]++;
                  A[i][i+1]++;
                  if(i+2<m)A[i][i+2]++;
            }
      }
}
// Multiply b into a
void mult(int a[SIZE][SIZE],int b[SIZE][SIZE],int dim)
{
      int i,j,k;
      int temp[SIZE][SIZE];
      memset(temp,0,sizeof(temp));
      for(i=0;i<dim;i++)
      for(j=0;j<dim;j++)
      for(k=0;k<dim;k++)
            temp[i][j] = (temp[i][j] + ((ll)a[i][k])*b[k][j])%MOD;
      for(i=0;i<dim;i++)
      for(j=0;j<dim;j++)
            a[i][j] = temp[i][j];

}
void print(int A[SIZE][SIZE],int dim)
{
      int i,j;
      printf("\nMatrix :\n");
      for(i=0;i<dim;i++)
      {
            for(j=0;j<dim;j++)
                  printf("%d\t",A[i][j]);
            printf("\n");
      }
}
int main()
{
      int t,i,j;
      s(t);
      while(t--)
      {
            s(n);s(m);
            // Compute Matrix A (dim = m) whose nth power is to be computed
            fillA(m);
            while(n)
            {
                  if(n&1)
                        mult(res,prod,m);
                  for(i=0;i<m;i++)for(j=0;j<m;j++) A[i][j] = prod[i][j];
                  mult(prod,A,m);
                  n = n/2;
            }
      }
      return 0;
}
