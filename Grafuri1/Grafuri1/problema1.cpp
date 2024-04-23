#include <iostream>
#include <fstream>

using namespace std;

int	matrice[20][20];
int	colour[20];
int	points[20];


void	init_matrix()
{
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			matrice[i][j] = 0;
		}
	}
}

void	print_matrix(int n)
{
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << matrice[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

int	searchNextNode(int n)
{
	int nrmuchii = 0;
	int nrculori = 0;
	int nrmaxmuchii = 0;
	int nrmaxculori = 0;
	int nodmaxim = 0;

	for (int i = 0; i < n; i++){
		if (colour[i] == 0)
		{
			for (int j = 0; j < n; j++){
				if (matrice[i][j] == 1)
					nrmuchii++;
				if (colour[j] != 0)
					nrculori++;
			}
			if (nrculori > nrmaxculori)
			{
				nodmaxim = i;
				nrmaxculori = nrculori;
				nrmaxmuchii = nrmuchii;
			}
			else if (nrculori == nrmaxculori)
			{
				if (nrmuchii > nrmaxmuchii)
				{
					nodmaxim = i;
					nrmaxculori = nrculori;
					nrmaxmuchii = nrmuchii;
				}
			}
			nrculori = 0;
			nrmuchii = 0;
		}
	}

	return nodmaxim;
}

int	colours_used(int n)
{
	int max;
	
	max = 0;
	for (int i = 0; i < n; i++){
		if (colour[i] > max)
			max = colour[i];
	}
	return max;
}

void	init_points()
{
	for (int i = 1; i < 20; i++)
	{
		points[i] = 10;
	}
}

void	eliminate_neighbours(int node, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (matrice[node][i] != 0 && colour[i] != 0)
		{
			points[colour[i]] = 0;
		}
	}			
}

void	adaptpoints(int node, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (colour[i] != 0 && matrice[node][i] != 0)
			points[colour[i]] = points[colour[i]] * 2;
	}
}

void	neighbours_max_color(int used, int n)
{
	for (int i = 0; i < n; i++)
		if (colour[i] != 0 && matrice[used][i] != 0)
			adaptpoints(i, n);
}

int	getMaxColour(int n)
{
	int colorsUsed;
	int max;

	max = 0;
	colorsUsed = colours_used(n);
	for (int i = 0; i < colorsUsed; i++)
	{
		if (points[i] > max)
			max = points[i];
	}
	for (int i = 0; i < colorsUsed; i++)
	{
		if (points[i] == max)
			return i;
	}
	return -1;
}

bool	nocolor(int n)
{
	for (int i = 0; i < n; i++)
		if (colour[i] == 0)
			return true;
	return false;
}

bool	nomorecolors(int n)
{
	int colused = colours_used(n);
	for (int i = 0; i < colused; i++)
	{
		if (points[i] != 0)
			return false;
	}
	return true;
}

void	print_Colours(int n)
{
	for (int i = 0; i < n; i++)
		cout << colour[i] << " " ;
	cout << endl;
}

int	giveColour(int n, int node)
{	
	int used;
	int color;

	used = colours_used(n);
	init_points();
	eliminate_neighbours(node, n);
	neighbours_max_color(node, n);
	if (nomorecolors(n))
		color = colours_used(n) + 1;
	else
		color = getMaxColour(n);
	return color;	
	
}



void	color_rest(int m, int n)
{
	int node;
	int color;
	
	while (nocolor(n))
	{
		node = searchNextNode(n);
		color = giveColour(n, node);
		cout << node << " ";
		cout << color;
		cout << endl;
		colour[node] = color;
	}
}

void	start_color(int m, int n)
{
	int first_color = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (matrice[i][j] == 1 && first_color == 0)
			{
				colour[i] = 1;
				first_color = 1;
				break;
			}
		}
		if (first_color == 1)
			break;
	}
	color_rest(m, n);
	print_Colours(n);
}
		



int	main ()
{
	int m;
	int n;
	int x;
	int y;

	init_matrix();
	ifstream testfile;
	testfile.open ("test");
	testfile >> n;
	testfile >> m;
	for (int i = 0; i < m; i++)
	{
		testfile >> x;
		testfile >> y;
		matrice[x][y] = 1;
		matrice[y][x] = 1;
	}
	start_color(m,n);
	testfile.close();
	
	print_matrix(n);
	return 0;
}	
