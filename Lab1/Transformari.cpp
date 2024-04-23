#include<stdio.h>

struct lista {int x,y;};


int main()
 {
     int n, m;
     //se citeste nr de noduri
     printf("Dati n:");
     scanf("%d", &n);
     //se citeste nr de muchii
     printf("Dati m:");
     scanf("%d", &m);

     int i,j;
     int x[100], y[100]; ///x si y sunt extremitatile muchiilor

     for (i = 0; i < m; i++)
     {
         printf("Dati x:");
         scanf("%d", &x[i]);
         printf("Dati y:");
         scanf("%d", &y[i]);

     }

     int Ma[100][100];  ///matricea de adiacenta
     for(i=0; i<n; i++)
         for (j = 0; j < n; j++)
         {
             Ma[i][j] = 0;
         }

     int a;
     int b;


     for (i = 0; i < n; i++)
     {
         a = x[i];
         b = y[i];
         Ma[a][b] = Ma[a][b]+1;
         Ma[b][a] = Ma[b][a] +1;
     }

     for (i = 0; i = n; i++) {
         for (j = 0; j = n; j++)
             printf("%d", Ma[i][j]);
         printf("\n");
     }
     return 0;
 }

 lista V[100];
int k;

///transformare din matricea de adiacenta in lista

 for(i=0; i<n; i++)
    for (j = 0; j < i; j++)
{
v[k].x = i;
v[k].y = j;
k++;
}
            }
 for(i=0;i<m;i++)
     printf("(%d,%l) \n",v[i].x,v[i].y);


    return 0;

}


