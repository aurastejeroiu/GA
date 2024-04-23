#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <fstream>

using namespace std;

int matrice[20][20];
int C;
int N;
int path[100];

bool bfs(int residualGraph[20][20], int sursa, int centrala, int path[])
{
	bool vizitat[20];
	queue <int> coada;

	memset(vizitat, 0, sizeof(vizitat));
	coada.push(sursa);
	vizitat[sursa] = true;
	path[sursa] = -1;
	while (!coada.empty())
	{
		int u = coada.front();
		coada.pop();
		for (int v = 0; v < N; v++)
		{
			if (vizitat[v] == false && residualGraph[u][v] > 0)
			{
				coada.push(v);
				path[v] = u;
				vizitat[v] = true;
			}
		}
	}
	return (vizitat[centrala] == true);
}

int fordFulkerson(int sursa, int centrala)
{
	int u, v;
	int residualGraph[20][20];
	int path[20];
	int max_flow = 0;

	for (u = 0; u <= N; u++)
		for (v = 0; v <= N; v++)
			residualGraph[u][v] = matrice[u][v];
	while (bfs(residualGraph, sursa, centrala, path))
	{
		int path_flow = INT_MAX;
		for (v = centrala; v != sursa; v = path[v])
		{
			u = path[v];
			path_flow = min(path_flow, residualGraph[u][v]);
		}
		for (v = centrala; v != sursa; v = path[v])
		{
			u = path[v];
			residualGraph[u][v] -= path_flow;
			residualGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	int vertex_flow;
	for (int i = 0; i < C; i++) {
		vertex_flow = 0;
		for (int j = 0; j < N; j++) {
			vertex_flow += residualGraph[j][i] - residualGraph[i][j];
		}
		cout << vertex_flow << endl;
	}
	return max_flow;
}

void init_matrix() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			matrice[i][j] = 0;
		}
	}
}

void	print_matrix() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << matrice[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void createSource(){
	for (int i = 0; i < C; i++) {
		matrice[N][i] = 1000;
	}
}

int getMaxFlow() {

	createSource();
	int flow = 0;
	flow = fordFulkerson(N, N - 1);
	return flow;
}

int	main()
{
	int D;
	int x;
	int y;
	int l;
	int j;
	int flow;

	init_matrix();
	ifstream testfile;
	testfile.open("test.txt");
	testfile >> N;
	testfile >> C;
	testfile >> D;
	for (int i = 0; i < D; i++)
	{
		testfile >> x;
		testfile >> y;
		testfile >> l;
		matrice[x][y] = l;
	}
	cout << getMaxFlow();
	cout << endl;
	testfile.close();

	print_matrix();
	return 0;
}