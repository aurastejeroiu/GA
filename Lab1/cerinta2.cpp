//
// Created by Stejeroiu Aura on 3/10/2020.
//
///Se citeste matricea de adiacenta si se cauta nodurile izolate.
int main()
    {
        int n, m;
        //se citeste nr de noduri
        printf("Dati n:");
        scanf("%d", &n);
        //se citeste nr de muchii
        printf("Dati m:");
        scanf("%d", &m);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                scanf("%d", &M[i][j]);

            }
        ///nodurile izolate sunt cele care au pe linie sau pe coloana doar 0;
        for(int i=0; i<n;i++)
        {
            ok=1;
            for(int j=0;j<n;j++)
                if(M[i][j]!=0)
                    ok=0;
            if (ok==1) printf("%d,\n",i);   ///se afiseaza nodurile
        }

    ///pt a demonstra daca un graf este conex trebuie verificat daca intr oricare 2 noduri exista un drum
    int q=1; ///presupunem ca graful este conex

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                    if(M[i][j]==0)
                        q=0;
            }
if (q==1) printf("Graful este conex");
else printf("Graful nu e conex");

return 0;
    }
