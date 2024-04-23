#include <iostream.h>
using namespace std;
/*Să se implementeze o soluție, folosind euristici, care să rezolve problema de colorare în grafuri.
Dându-se un graf neorientat, să se determine numărul minim de culori care sunt necesare
pentru colorare și o colorare care respectă acest număr minim.
*/

int N, M, a[20][20] = {0}, x, y,i=1,nr=0,j,nrmax;
int main()
{
    ifstream f("intrare.txt"); // se citesc datele din intrare.txt
    ofstream g("iesire.txt"); //se afiseaza datele
    f >> N >> M;
    while (i<=N)
    {
        cin >> x;
        cin >> y;
        a[x][y] = 1;
        a[y][x] = 1;
        i++;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (a[i][j] == 1)
                nr++;

        }
        if (nr > nrmax)
            nrmax = nr;
        nr = 0;
    }
    cout << nr + 1;

}
