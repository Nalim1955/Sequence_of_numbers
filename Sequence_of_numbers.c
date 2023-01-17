#include <stdio.h> //Kniznica standardnych funkcii
#include <time.h>
#include <stdlib.h>

#define RND_OD -20 //definovany rozsah pre rand_rozsah
#define RND_DO 130 //definovany rozsah pre rand_rozsah

/* ***************** 9C **************************
Vytvorte program, ktory do pola nacita postupnost cisel a najde maximalny a
minimalny prvok a vypise aj ich pozicie v poli.

Ako C1 ale na uchovanie hodnoty prvku a jej pozicie v poli pouzite strukturu.
******************** 9C ************************** */
typedef struct pole
{
    float prvok;
} POLE;

typedef struct extminmax
{
    int arr_pozmin, arr_pozmax;
} EXTMINMAX;

float rand_rozsah(float min, float max);

int main(void)
{

    int i=0, gener_data, rozsah_pola;

    printf("Je moznost pouzit automaticke generovanie cisel.");
    printf("\nPre generovanie cisel zadaj: 0 | Pre manualne zadavanie cisel zadaj: 1 az 9 ");
    printf("\nVasa volba :");
    scanf("%d", &gener_data);

    if (gener_data == 0)
    {
        /* *****************Generovanie********************** */
        srand((unsigned) time(0));

        do
        {
            printf("\nZadaj kolko prvkov pola chces: ");
            scanf("%d", &rozsah_pola);
        }
        while(rozsah_pola<1);

        POLE arr_prvky[rozsah_pola];

        for(i=0; i<rozsah_pola; i++)
        {
            arr_prvky[i].prvok=rand_rozsah(RND_OD,RND_DO);
        }

    }
    else
    {
        /* *****************Manualne zadavanie********************** */
        do
        {
            printf("\nZadaj kolko prvkov pola chces: ");
            scanf("%d", &rozsah_pola);
        }
        while(rozsah_pola<1);

    }

    POLE arr_prvky[rozsah_pola];

    for (i; i < rozsah_pola; i++)
    {
        printf("\nZadaj prvok c. %d do pola: ", i+1);
        scanf("%f", &arr_prvky[i].prvok);
    }

    EXTMINMAX ext;
    ext.arr_pozmin=0;
    ext.arr_pozmax=0;

    for(i=0; i<rozsah_pola; i++)
    {
        if(arr_prvky[i].prvok<arr_prvky[ext.arr_pozmin].prvok)
            ext.arr_pozmin=i;

        if(arr_prvky[i].prvok>arr_prvky[ext.arr_pozmax].prvok)
            ext.arr_pozmax=i;
    }

    printf("\nMinimalny prvok z pola je: %f . Prvok je na pozicii %d.\n\n", arr_prvky[ext.arr_pozmin].prvok,ext.arr_pozmin);
    printf("\nMaximalny prvok z pola je: %f . Prvok je na pozicii %d.\n\n", arr_prvky[ext.arr_pozmax].prvok,ext.arr_pozmax);

    return 0;
}

/* ******* Funkcia na generovanie nahodnych cisel z vybraneho rozsahu min | max ******* */
float rand_rozsah(float min, float max)
{

    float rnd_cislo = ((float) rand()) / RAND_MAX;

    float rng_rozsah = (max - min) * rnd_cislo;

    float cislo = min + rng_rozsah;

    return cislo; // vysledne generovane cislo

}
