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
bool bsf(int res[20][20], int sursa, int dest, int P[])
{
	bool V[20]; //va fi notat cu 1 daca studentul a vizitat orasul respectiv
	queue <int> coada;
	
	memset(V, 0, sizeof(V));

	coada.push(sursa);
	V[sursa] = true;
	P[sursa] = -1;
	while (!coada.empty())  //Cat timp mai am de parcurs
	{
		int i = coada.front();
		coada.pop();
		for (int j = 0; j < N; j++) {
			if (V[j] == false && res[i][j] > 0)
			{
				coada.push(i);
				P[j] = i;
				V[j] = true;
			}

		}
	}
	return (V[dest] == true);	//Se stabileste traseul si daca ajunge la destinatie pe acel traseu sau nu
		
}

//Algoritmul FordFulkerson perimite rezolvarea acestei probleme de flux;
//In combinatie cu BSF pt a det calea reziduala timpul de executie este polinomial

int Ford(int sursa, int dest)
{
	int i, j;
	int res[20][20];
	int P[20];
	int fluxmax = 0;

	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
			res[i][j] = a[i][j];	//matricea de dist
	while (bsf(res, sursa, dest, P))
	{
		int fluxP = INT_MAX;
		for (j = dest; j != sursa; j = P[j])
		{
			i = P[j];
			fluxP = min(fluxP, res[i][j]);

		}
		for (j = dest; j!= sursa; j = P[j])
		{
			i = P[j];
			res[i][j] -= fluxP;
			res[j][i] += fluxP;
		}
		fluxmax += fluxP; //fluxul maxim;
	}
	
	int FLuxNod;
	for (int k = 0; k < C; k++)
	{
		FLuxNod = 0;
		for (int q = 0; q < N; q++)
		{
			FLuxNod += res[q][k] - res[k][q];

		}
		cout <<abs( FLuxNod) << endl;

	}
	return fluxmax;
}

void MatrDr() {
	for (int i = 0; i < C; i++) 
		a[N][i] = 10000;
	}

	int MaxFlux(){
		MatrDr();
		int fluxmax = 0;
		fluxmax = Ford(N, N - 1);
			return fluxmax;
	}

	int main() {
		int D, x, y;
		int lungime;
		ifstream in("intrare.txt");
		
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				a[i][j] = 0;
			}
		}

		in >> N;
		in >> C;
		in >> D;
		
		for (int i = 0; i < D; i++) {
			in >> x;
			in >> y;
			in >> lungime;
			a[x][y] = lungime;
		}
		cout << MaxFlux() << endl;

		in.close();


	for (int i = 0; i <=N; i++) {
		for (int j = 0; j <=N; j++) {
			cout << a[i][j] << " ";

		}
		cout << endl;
	}

	return 0;
}

