#include <stdio.h>
#include <conio.h>

int n;         // n=numarul de varfuri ale grafului
int a[20][20];    // matricea care are val:a[i][j]=1,daca exista muchie intre i
           // si j;a[i][j]=0 daca nu exista arc de la i la j sau i=j}
           // a[i][i]=0
int x[20], xmax[20], lmax;
int alfa;      // numarul de stabilitate interna
FILE* f;
void citire(int& n, int a[20][20])
{
    int i, j;
    f = fopen("lab4.txt", "rt");
    fscanf(f, "%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &a[i][j]);
    fclose(f);
}
void afisare(int n, int a[20][20])
{
    printf("\n Matricea de adiacenta este: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)  printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n O multime interior stabila este:");
    printf("\n {");
    for (int s = 0; s < n; s++)  printf("%d ", xmax[s]);
    printf("}");
}
void comp(int x[20], int n)
{
    int l = 0, i;
    for (i = 0; i < n; i++) l = l + x[i];
    printf("%d,%d", l, lmax);
    if (l > lmax)
        for (i = 0; i < n; i++)
            xmax[i] = x[i];
}

int conditie(int a[20][20], int x[20], int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        if (x[k] == 1) return 0;
        if ((x[i] == 1) && ((a[x[i]][x[k]] == 1) || (a[x[k]][x[i]] == 1))) return 0;
    }
    return 1;
}

void det(int n, int a[20][20], int k)
{
    if (k == n - 1) comp(x, n);
    else
        for (int i = x[k - 1] + 1; i < n; i++)
            if ((a[k][x[k]] == 0) && (a[x[k]][k] == 0) && (conditie(a, x, k)))
            {
                x[k] = 1;
                det(n, a, k);
            }
}

// Program principal
void main()
{
    //clrscr();
    citire(n, a);
    det(n, a, 0);
    afisare(n, a);
    getch();
}
