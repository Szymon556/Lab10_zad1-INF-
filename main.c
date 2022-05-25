#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int dzielenie (int * tab, int poczatek, int koniec);
void zamiana (int * a, int * b);
void quicksort(int * tab, int poczatek,int koniec);
void wypisztablice(const int * tab,int ile);
bool median(const int * tab, int n,float * buffer);


int main()
{
int ile;
float buffer=0;
 printf("Podaj ile chcesz wpisac liczb\n");
 scanf("%d",&ile);
int * tab = (int*)malloc(ile*sizeof(int));//alokujemy dynamiznie pamiec
int * tabkopia = (int*)malloc(ile*sizeof(int));//bedziemy dzialac na kopi tablicy
if (tab == NULL||tabkopia==NULL) {
        printf("Pamiec nie zostala przydzielona.\n");
        exit(0);
    }
for(int i =0; i<ile; ++i)//wypelniamy tablice
{
    printf("Podaj liczbe:\t");
    scanf("%d",&tab[i]);
}
for(int i =0; i<ile; ++i)//wypelniamy kopietablicy
{
    tabkopia[i]=tab[i];
}
quicksort(tabkopia,0,ile-1);
wypisztablice(tabkopia,ile);
median(tabkopia,ile ,&buffer);
printf("Mediana jest rowna%f",buffer);
    return 0;
}
int dzielenie (int * tab, int poczatek, int koniec)//porównujemy liczby z pivotem
{
    int pivot = tab[koniec];
    int granica = poczatek;
    for( int i = poczatek; i< koniec;++i)  
    {
        if(tab[i]<=pivot)       // jeśli mnieszjesze od pivota to na lewo od granicy DEBILU KURWA SREDNIK TU BYL
        {
            zamiana(tab + i,tab + granica);
            granica++;
        }
        
    }
    zamiana(tab + koniec,tab + granica);
    return granica;
}

void zamiana (int * a, int * b)// tutaj zamianiamy komortki w tablicy
{
    int bufor = *a;
    *a = *b;
    *b = bufor;
   
}

void quicksort(int * tab, int poczatek, int koniec)//algorytm sortowania
{
    if(tab!=NULL&& koniec>poczatek)
    {   
        int podzial = dzielenie(tab,poczatek,koniec);

         quicksort(tab,poczatek, podzial-1);
          quicksort(tab,podzial+1, koniec);
    }
}

void wypisztablice(const int * tab,int ile)
{
    if(tab!=NULL)
    {
        for(int i = 0; i<ile; i++)
        {
            printf("%d",tab[i]);
        }
    }
}

bool median(const int * tab, int n,float * buffer)//liczymy mediane
{   float sum = 0;
    bool result = true;
     if(tab==NULL&&buffer==NULL)
    {
         return false;
    }
    if(n%2==1)
    {
        *buffer = tab[(n-1)/2];
        
    }else
    {
        sum=tab[((n-1)/2)+1]+tab[((n-1)/2)];

        *buffer = sum/2;
    }
   
    return result;
}