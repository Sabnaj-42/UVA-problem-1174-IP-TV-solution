#include<bits/stdc++.h>
using namespace std;
struct node
{
    string a,b;
    int w;
};
bool comp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
 struct node ar[500005];
 map<string,string>parent;
 string findd(string s)
 {
     if(parent[s]==s)return s;
     else
        return parent[s]=findd(parent[s]);
 }
 void unionn(string c,string d)
 {
     parent[c]=d;
 }
int main()
{
    int k=0;
   int t;cin>>t;
   while(t--)
   {
       int n;cin>>n;
       int m;cin>>m;
       for(int i=0;i<m;i++)
       {
           cin>>ar[i].a>>ar[i].b>>ar[i].w;
           parent[ar[i].a]=ar[i].a;
           parent[ar[i].b]=ar[i].b;
       }
       sort(ar,ar+m,comp);
       long long ans=0;
       for(int i=0;i<m;i++)
       {
           string u=findd(ar[i].a);
           string v=findd(ar[i].b);
           if(u!=v)
           {
               unionn(u,v);
               ans+=ar[i].w;
           }
       }
       if(k!=0)cout<<endl;
       cout<<ans<<endl;
       k++;
   }
}
