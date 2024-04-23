#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <fstream>

using namespace std;

int a[20][20];
int C;
int N;
int P[100];  //reprezinta drumul pe care il va parcurge un student

//Folosind bsf vom gasi distanta de la sursa(caminul studentesc) la dest
bool bsf(int res[20][20], int sursa, int dest, int P[100])
{
	int V[20] = { 0 }; //va fi notat cu 1 daca studentul a vizitat orasul respectiv
	queue <int> coada;
	coada.push(sursa);
	V[sursa] = 1;
	P[sursa] = -1;
	while (!coada.empty())  //Cat timp mai am de parcurs
	{
		int j = coada.front();
		coada.pop();
		for (int i = 0; i < N; i++) {
			if(V[i]==0 && res[j][i]>0)
			{
				coada.push(i);
				P[i] = j;
				V[i] = 1;
			}

		}
	}
	if (V[dest] == 1)		//Se stabileste traseul si daca ajunge la destinatie pe acel traseu sau nu
		return true;
	else return false;
}

//Algoritmul FordFulkerson perimite rezolvarea acestei probleme de flux;
//In combinatie cu BSF pt a det calea reziduala timpul de executie este polinomial

int Ford(int sursa, int dest)
{
	int i, j;
	int res[20][20];
	int P[20];
	int flux = 0;

	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
			res[i][j] = a[i][j];
	while (bsf(res, sursa, dest, P))
	{
		int fluxP = INT_MAX;
		for (i = dest; i != sursa; i = P[i])
		{
			j = P[i];
			fluxP = min(fluxP, res[j][i]);

		}
		for (i = dest; i != sursa; i = P[i])
		{
			j = P[i];
			res[j][i] = res[j][i] - fluxP;
			res[i][j] = res[i][j] + fluxP;
		}
		flux += fluxP; //fluxul maxim;
	}
	int FLuxNod;
	for (int i = 0; i < C; i++)
	{
		FLuxNod = 0;
		for (int j = 0; j < N; j++)
		{
			FLuxNod = res[j][i] - res[i][j];
		}
		cout << FLuxNod << endl;

	}
	return flux;
}

void MatrDr(){
    for (int i = 0; i < C; i++) {
		a[N][i] = 1000;
}

int GetMax(){
    MatrDr();
    int flux=0;
    flux=Ford(N,N-1)
    return flux;
}

int main(){
    int D,x,y,i,j,flux;
    ifstream in("intrare.txt");
    int lungime;
    in>>N;
    in>>C;
    in>>D;
    for(i=0;i<D;i++){
        in>>x;
        in>>y;
        in>>l;
        a[x][y]=1;
    }
    cout<<GetMax();
    in.close();

    return 0;
}





