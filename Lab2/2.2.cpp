//
// Created by Stejeroiu Aura on 3/13/2020.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#define inf 99999
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
vector <pair<int,int> > v[1001];
queue <int> q;
int n,m;
int L[1001];
int T[1001];
void credCaMoore(int x)
{

    for(int i=1;i<=n;i++)
        L[i]=inf;
    L[x]=0;

    q.push(x);
    while(!q.empty())
    {
        int nod=q.front();
        for(int i=0;i<v[nod].size();i++)
        {
            if(L[v[nod][i].first]>v[nod][i].second+L[nod])
            {
                L[v[nod][i].first]=v[nod][i].second+L[nod];
                T[v[nod][i].first]=nod;
                q.push(v[nod][i].first);
            }
        }
        q.pop();
    }

}
void afis(int x)
{
    if(T[x]!=0)
        afis(T[x]);
    g<<x<<" ";
}
int main()
{
    int x,y,c;
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        v[x].push_back({y,c});
    }
    f>>x;
    credCaMoore(x);
    f>>y;
    g<<L[y]<<'\n';
    afis(y);
    return 0;
}

