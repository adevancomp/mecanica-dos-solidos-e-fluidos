#include <stdio.h>
#include <stdlib.h>
#include "trelica.h"
#include "AG.h"

extern trelica casos_de_teste[NUM_CASOS_TESTE];

int main(int argc, char const *argv[])
{
    inicializa_casos_de_teste();
    printf("\n=== Casos de teste ======\n");
    for(int i=0;i<NUM_CASOS_TESTE;i++)
    {
        printf("## Caso de teste [%d]##\n",i);
        printf("Barra L(m)  N(kN)     n(kN)   Delta (m)\n");
        for(int j=0;j<NUM_BARRAS;j++)
        {
            printf("%2.d  %6.3f %7.3f  %7.3f   %7.2E\n",j+1,casos_de_teste[i].barras[j],casos_de_teste[i].FN[j],casos_de_teste[i].VFN[j],casos_de_teste[i].DY[j]);
        }
        printf("Deslocamento Final: %.4f mm\n",casos_de_teste[i].desloc_C);
        printf("\n\n");
    }
    printf("Antes da ordenação:\n");
    for(int i=0;i<NUM_CASOS_TESTE;i++){
        printf("Treliça %d deslocamento:%.4f\n",i,casos_de_teste[i].desloc_C);
    }
    qsort(casos_de_teste,NUM_CASOS_TESTE,sizeof(trelica),compare);
    printf("Depois da ordenação:\n");
    for(int i=0;i<NUM_CASOS_TESTE;i++){
        printf("Treliça %d deslocamento:%.4f\n",i,casos_de_teste[i].desloc_C);
    } 
}