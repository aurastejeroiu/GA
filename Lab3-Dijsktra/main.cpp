//Utilizand tehnica Dijkstra
/* SPECIFICARE
 date intrare & preconditii:
	- n intreg si nintre 1 si DIM (constanta predefinita de ex. 50)
	- secventa de valori intregi S de dimensiune n
 rezultate & postconditii:
	- exista k astfel incat S[1],...,S[k]<=0 si S[k+1]...S[n]>0
	  (se afiseaza secventa astfel obtinuta)
    -se afiseaza cel mai scurt drum din graf
   END SPECIFICARE
COMPLEXITATE
		O(n)


*/


#define DIM 50
#include <iostream>

using namespace std;

typedef struct
{ int n;			//dimensiunea secventei
    int Sir[DIM+1];
} SECV;


enum BOOL {FALSE,TRUE};              		//  FALSE=0   TRUE=1

void Citire(SECV& S)         			//
{ S.n   = DIM+1;
    while  ( S.n<=0 || S.n>DIM )    		// citirea dimensiunii
    {cout	<<"\ndati dim. secventa:";
        cin 	>>S.n;
    }
    // citirea secventei
    for (int i=1;i<=S.n;i++)                   	//
    { cout	<<"S["<<i<<"]=";		//printf ("\nS[%2d]=",i);
        cin		>>S.Sir[i];		//scanf  ("%d",&S[i]);
    }
}

void Afisare(SECV S)
{ int i;				 	// afisarea secventei
    i    = 1;
    while  (i<=S.n)
    { cout	<<S.Sir[i++]<<" ";
        if (i % 10 == 0) cout<<endl;		//printf("\n");afisarea a cate 10 elem pe linie
    }
}

void NegDijkstra(SECV& S)
{ int i,j,aux;               			// spatiul: S[1],...,S[n]
    i=j=1;
    while(j<=S.n)
    { if ( S.Sir[j] > 0 ) j++;			//creste zona pozitiva
        else {     aux     = S.Sir[i];
            S.Sir[i]= S.Sir[j];
            S.Sir[j]= aux;
            i++;j++;			//creste zona negativa, se deplaseaza zona pozitiva
        }
    }
}

int main ()
{ SECV   	 A;
    Citire	 (A);
    cout		 <<"\nSecventa initiala\n";	   //printf ("\nsecventa nesortata este:\n");
    Afisare	 (A);
    NegDijkstra(A);
    cout		 <<"\n\nSecventa aranjata este:\n";//cout("\n\nsecventa aranjata este:\n");
    Afisare	 (A);
    return	 0;
}


