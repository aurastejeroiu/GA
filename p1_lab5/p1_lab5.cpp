//
// Created by Stejeroiu Aura on 5/7/2020.
//

#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;
int a[1000][1000];
int flux[1000][1000];
vector<int> b[1000];
int parList[1000];
int caleCurenta[1000];
int bfs(int sNode, int eNode)//breadth first search
{
    memset(parList, -1, sizeof(parList));
    memset(caleCurenta, 0, sizeof(caleCurenta));
    queue<int> q;//declare queue vector
    q.push(sNode);
    parList[sNode] = -1;//initialize parlist�s source node
    caleCurenta[sNode] = 999;//initialize currentpath�s source node
    while (!q.empty())// if q is not empty
    {
        int currNode = q.front();
        q.pop();
        for (int i = 0; i < b[currNode].size(); i++)
        {
            int to = b[currNode][i];
            if (parList[to] == -1)
            {
                if (a[currNode][to] - flux[currNode][to] > 0)
                {
                    parList[to] = currNode;
                    caleCurenta[to] = min(caleCurenta[currNode],
                                          a[currNode][to] - flux[currNode][to]);
                    if (to == eNode)
                    {
                        return caleCurenta[eNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
int EdmondsKarp(int sursa, int dest)
{
    int FluxMaxim = 0;
    while (true)
    {
        int flow = bfs(sursa, dest);
        if (flow == 0)
        {
            break;
        }
        FluxMaxim += flow;
        int nodcurent = dest;
        while (nodcurent != sursa)
        {
            int nodanterior = parList[nodcurent];
            flux[nodanterior][nodcurent] += flow;
            flux[nodcurent][nodanterior] -= flow;
            nodcurent = nodanterior;
        }
    }
    return FluxMaxim;
}
int main()
{
    ifstream f("input.txt");
    ofstream h("output.txt");
    int V,E;
    f >> V >> E;
    int sursa,dest;
    sursa = 0; dest = V - 1;
    for (int ed = 0; ed < E; ed++)
    {
        int x,y,z;
        f >> x >> y >> z;
        a[x][y] = z;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    int FlowMaxim = EdmondsKarp(sursa,dest);
    h << FlowMaxim;
}
