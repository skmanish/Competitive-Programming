//
//  Problem Link : http://codeforces.com/contest/392/problem/C
//  Matrix Exponentiation
//
#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define p(a) scanf("%d",a)
#define ss(a) scanf("%s",a)

#define MP           make_pair
#define PB           push_back
#define SZ(a)        ((int)a.size())
#define REP(i, n)    for(int i = 0; i < n; i++)
#define INC(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)
#define CLEAR(a, b)  memset(a, b, sizeof a)

using namespace std;

typedef long long          LL;
typedef unsigned long long ULL;
typedef vector<int>        VI;
typedef pair<int, int>     II;
typedef vector<II>         VII;

const int MOD = 1e9+7;
LL n;
int k;
int C[50][50],Cp[50][50];
int mat[100][100],temp[100][100],ans[100][100],temp2[100][100];
int sz;
LL modexp(int a,int b)
{
      if(b==0)return 1;
      if(b==1)return a%MOD;
      LL temp = modexp(a,b/2);
      temp = (temp*temp)%MOD;
      if(b&1) temp = (temp*a)%MOD;
      return temp;
}
void fill()
{
      CLEAR(mat,0);
      int x,y;
      mat[0][0] = 1;
      DEC(i,k,0) INC(j,0,i)
      {
            x = k+1-i;
            y = k+1-j;
            mat[x][y] = C[i][j];
            if(i==k) mat[0][y] = mat[x][y];
            y = k+1 + (k+1-j);
            mat[x][y] = Cp[i][j];
            if(i==k) mat[0][y] = mat[x][y];
      }
      DEC(i,k,0)
      {
            x = k+1 + (k+1-i);
            y = k+1-i;
            mat[x][y] = 1;
      }
}
void cpy(int mat1[100][100], int mat2[100][100],int sz)
{
      REP(i,sz) REP(j,sz)
            mat2[i][j] = mat1[i][j];
}
void print(int mat[100][100],int sz);
inline void mult(int mat1[100][100],int mat2[100][100],int sz)
{
      CLEAR(temp,0);
      REP(i,sz) REP(j,sz) REP(l,sz) temp[i][j] = (temp[i][j] + 1LL*mat1[i][l]*mat2[l][j]) %MOD;
      cpy(temp,mat1,sz);
}
int solve()
{
      CLEAR(ans,0);
      fill();
      sz = 2*k+2+1;
      REP(i,sz) ans[i][i] = 1;
      n = n-2;
      while(n>0)
      {
            if(n&(1LL))
                  mult(ans,mat,sz);
            cpy(mat,temp2,sz);
            mult(mat,temp2,sz);
            n=(n>>1LL);
      }
      
      int col[100];
      CLEAR(col,0);
      REP(i,k+1) col[k+1-i] = (2*modexp(2,i))%MOD;
      REP(i,k+1) col[k+1+k+1-i] = 1;
      col[0] = (col[1]+col[k+2]) %MOD;
      
      int ret = 0;
      REP(i,sz) ret = (ret + 1LL*ans[0][i]*col[i])%MOD;
      return ret;
}
void print(int mat[100][100],int sz)
{
      REP(i,sz)
      {
            REP(j,sz)
                  cout<<mat[i][j]<<" ";
            cout<<endl;
      }
      printf("\n");
}
int main()
{
      sl(n);
      s(k);
      if(n<=2)
      {
            int ans = 0;
            INC(i,1,n) ans = (ans + 1LL*i*modexp(i,k))%MOD;
            printf("%d\n",ans);
            return 0;
      }
      REP(i,k+1) C[i][0] = C[i][i] = 1;
      INC(i,1,k) INC(j,1,i-1) C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
      
      CLEAR(Cp,0);
      INC(i,0,k) INC(j,0,i) INC(l,j,i) Cp[i][j] = (Cp[i][j] + (1LL*C[i][l]*C[l][j]) %MOD) %MOD;

      cout<<solve()<<endl;
      return 0;
}
