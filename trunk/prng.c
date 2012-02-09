#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

/*
** Autor: Jorge Pereira 12063
** MESI
** Implementacao de um gerador de numeros pseudo-aleatorios na linguagem C
** Processador Intel Core2 Duo T6500 @ 2.10GHz
** Tempos medidos por quantidade de PRN:
** 1000 -> 0.0
** 10000 -> 0.04
** 100000 -> 0.38
** 1000000 -> 2.47
*/

/*
** Funcao que efetua a troca dos valores de duas variaveis
*/
void swap(int *valor1, int *valor2)
{
    int tmp = *valor1;
    *valor1 = *valor2;
    *valor2 = tmp;
}

/*
** Funcao gera uma quantidade de numeros pseudo aleatorios atribuida pelo utilizador
*/
void prng(int totalNumbers)
{
    srand((unsigned)time(NULL));
    clock_t start, end;
    double elapsed;
    
    start = clock();
    
    int T[1000];
    int digits[10] = {0,0,0,0,0,0,0,0,0,0};
    
    int x = 0;
    while(x < 1000)
    {
        int r = rand()%10;
        if((digits[r]) < 100)
        {
            T[x]=r;
	    digits[r]++;
            x++;
        }
    }
    
    int p = rand()%1000;
    int j,n;
    int z1 = 0;
    int z2 = 0;
    int z3 = 0;
    int z4 = 0;
    
    for(j = 0; j < totalNumbers; j++ )
    {
        if(p < 1000)
        {
            z1 = T[p];
            swap(&T[p], &T[0]);
        }
        else if(p >= 1000)
        {
            z1 = T[0];
        }

        if(p < 999)
        {
            z2 = T[p+1];
            swap(&T[p+1], &T[0]);
        }
        else if(p >= 999)
        {
            z2 = T[0];
        }

        if(p < 998)
        {
            z3 = T[p+2];
            swap(&T[p+2], &T[0]);
        }
        else if(p >= 998)
        {
            z3 = T[0];
        }

        if(p < 997)
        {
            z4 = T[p+3];
            swap(&T[p+3], &T[0]);
        }
        else if(p >= 997)
        {
            z4 = T[0];
        }

        n = (z1 << 12) | (z2 << 8) | (z3 << 4) | z4;
        
        p = z1 * 100 + z2 * 10 + z3;
        
	// output comentado para se efectuar uma comparacao leal dos tempos com os tempos da implementacao em Python
        //printf("k:%d | p:%d | prn:%d\n", j+1, p, n);
        
	if(p == 999)
	{
	    p = rand()%1000;
	}
    }
    end = clock();
    
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("total time: %f\n", elapsed);
}

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        prng(atoi(argv[1]));
    }
    else if(argc <= 1)
    {
        printf("Tem de indicar a quantidade de elementos a ser gerada!\n");
	printf("Utilizacao: ./prng <quantidade>\n");
    }
    
    return 0;
}

