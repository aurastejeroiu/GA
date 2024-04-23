#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int N, M, a[20][20] = { 0 }, x, y, i = 0, nr = 0, j, C;
	C = 0;
	ifstream in("intrare.txt"); // se citesc datele din intrare.txt
	ofstream out("iesire.txt"); //se afiseaza datele on iesire.txt

	in >> N;
	in >> M;
	for (int i = 0; i < M; i++)
	{
		in >> x;
		in >> y;
		a[x][y] = 1;
		a[y][x] = 1;		//creeam o matrice de adiacenta pentru a fi retinute muchiile
		i++;
	}


	for (i = 0; i < N; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (a[i][j] == 1)
				C++;				//daca exista muchie atunci extremitatile trebuie sa fie colorate diferit.

		}

	}
	out<<C;


	int V[N]={0};   //Va fi un vector de frecventa care tine minte culorile.
                    //Va fi parcurs pana cand fiecare nod va avea o culoare
                    //Principiul este ca se verifica daca exista muchia v[i],v[j] daca nu exista vor putea fi aceasi culoare. apoi pentru v[i] si v[j+1]
                    // Daca nu exista muchia se va pune aceasi culoare Dar daca exista muchia v[j[ si v[j+1] atunci v[j+1] va trebui sa aiba alta culoare
    int c=C;    //o copie a numarului minim de culori

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(a[i][j]==0)
            {
                V[i]=c;
                V[j]=c;

            }
            else {
                    c++;
                    for(i1=0;i1<N;i1++){
                    for(j1=i+1;j1<N;j1++)
            }
        }
    }
    }

}
