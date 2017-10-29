#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int ara[100000];
int indexx[100000];
int root[100000];
vector<int>adj[10000];
int n;
bool fl=1;
int rut;
void build_tree(int in,int l,int r,int par)
{
    if(l>=r)
    {
        if(par==-1)
        {
            rut=ara[l];
            return;
        }
        adj[par].push_back(ara[l]);
        return;
    }
    int mx=0;
    int data;
    int indexx;
    for(int i=l; i<=r; i++)
    {
        if(root[i]>mx)
        {
            mx=root[i];
            data=ara[i];
            indexx=i;
        }
    }

    if(par!=-1)
        adj[par].push_back(data);
     else
        rut=data;
    if(indexx!=l)
        build_tree(in+1,l,indexx-1,data);
    if(indexx!=r)

        build_tree(in+2,indexx+1,r,data);
}
int mx=10000000;
int ans;
void print(int n,int lvl,int m)
{
   m+=n;
   for(int i=0;i<adj[n].size();i++)
   {
              int u=adj[n][i];
              print(u,lvl+1,m);
   }
   if(adj[n].size()==0)
   {
      if(mx>m)
      {
          mx=m;
          ans=n;
      }
      if(mx==n)
      {
          ans=min(ans,n);
      }
   }
}
int main()
{
    freopen("out.txt","w",stdout);

    string a,b;
    while(getline(cin,a ))
    {
        mx=10000000;
        if(a=="")
            break;
        getline(cin,b);


        for(int i=1;i<=10000;i++)
        {
            adj[i].clear();

        }
        stringstream ss(a);
        int x;
        int i=1;

        while(ss>>x)
        {


            ara[i]=x;
            indexx[ara[i]]=i;
            i++;
        }
        n=--i;
        stringstream ss1(b);
        i=1;
        while(ss1>>x)
        {




            root[indexx[x]]=i;
            i++;
        }
        build_tree(1,1,n,-1);

       print(rut,1,0);
        cout <<ans<<endl;


    }




}
