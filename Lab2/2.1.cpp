#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
int a[101][101];
int main()
{
    int n,m,x,y;
    f>>n>>m;
    for(int i=0;i<m;i++)
    {
        f>>x>>y;
        a[x][y]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(a[i][k]&&a[k][j])
                    a[i][j]=1;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }

    return 0;
}
