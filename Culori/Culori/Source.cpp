#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("intrare.txt");
ofstream fout("iesire.txt");

int adj[16][16];
int minCol[1 << 15];
long long dp[1 << 15], fact[16];

int v[16], cnt;

int main() {

	int n, m;
	fin >> n >> m;

	for (int i = 1; i <= m; ++i) {

		int x, y;
		fin >> x >> y;

		adj[x][y] = adj[y][x] = 1;

	}

	for (int config = 1; config < (1 << n); ++config) {

		cnt = 0;
		for (int i = 0; i < n; ++i)
			if ((config >> i) & 1)
				v[cnt++] = i + 1;

		bool ok = true;
		for (int i = 0; i < cnt && ok; ++i)
			for (int j = i + 1; j < cnt && ok; ++j)
				if (adj[v[i]][v[j]])
					ok = false;								//daca au muchie comuna ok devine false

		if (ok)
			minCol[config] = 1, dp[config] = 1;


	}

	fact[0] = 1;
	for (int i = 1; i <= n; ++i)		///calculare factorial
		fact[i] = fact[i - 1] * i;

	for (int config = 1; config < (1 << n); ++config) {

		if (minCol[config])
			continue;

		minCol[config] = 20;

		for (int oldConfig = (config & (config - 1)); oldConfig > 0; oldConfig = (config & (oldConfig - 1))) {

			if (minCol[config] > minCol[oldConfig] + minCol[config ^ oldConfig]) {

				minCol[config] = minCol[oldConfig] + minCol[config ^ oldConfig];
				dp[config] = 0;

			}

			if (minCol[config] == minCol[oldConfig] + minCol[config ^ oldConfig]) {

				dp[config] += dp[oldConfig] * dp[oldConfig ^ config];

			}

		}

		dp[config] /= (1 << minCol[config]) - 2;

	}

	dp[(1 << n) - 1] *= fact[minCol[(1 << n) - 1]];

	fout << minCol[(1 << n) - 1];
	fout << endl;
	int V[100];
	for (int i = 0; i <= n; i++)
		V[i]= minCol[(1 << n) - 1];
	
	
	int k = minCol[(1 << n) - 1];
	while (k > 0){
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
			{
				if (adj[i][j] == 0)
					V[i] = minCol[(1 << n) - 1];
				else if (V[i] == V[j]) {
					V[j] = minCol[(1 << n) - 1] - 1;
				}
			}
		k -= 1;
	}
	fout << endl;
	/*for (int i = 0; i <= n; i++)
		fout << V[i] << " ";
		*/

	return 0;
}