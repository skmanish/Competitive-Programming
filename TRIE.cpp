
// Author : Manish Sharma
// 
// Prefix Tree / Trie of alphabets
// Codeforces Contest# 260 Div 2
// http://codeforces.com/contest/456/problem/D

#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
using namespace std;
typedef long long int ll;
char inp[100005];
int trie[100005][26],size=0;
int dpw[100005],dpl[100005];
int add(int node,char c)
{
    c = c-'a';
    if(trie[node][c])
          return trie[node][c];
    return (trie[node][c] = ++size);
}
void dfs(int node)
{
    int i,isLeaf = true;
    dpw[node] = dpl[node] = false;
    for(i=0;i<26;i++)
    {
        if(!trie[node][i])continue;
        isLeaf = false;
        dfs(trie[node][i]);
        if(!dpl[trie[node][i]])dpl[node]=true;
        if(!dpw[trie[node][i]])dpw[node]=true;
    }
    if(isLeaf)
        dpw[node] = true;
}
int main()
{
    int i,n,k,l,u,j;
    s(n);s(k);
    memset(trie,0,sizeof(trie));
    for(i=0;i<n;i++)
    {
        ss(inp);
        l = strlen(inp);
        u=0;
        for(j=0;j<l;j++)
            u = add(u,inp[j]);
    }
    dfs(0);
    k = k&1;
    if(dpw[0] && dpl[0])cout<<"First\n";
    else if((dpl[0] && k))
          cout<<"First\n";
    else cout<<"Second\n";
    return 0;
}
