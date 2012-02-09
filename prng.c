#include <stdio.h>
#include <time.h>
#include <math.h>

void swap(int *valor1, int *valor2)
{
    int tmp = *valor1;
    *valor1 = *valor2;
    *valor2 = tmp;
}


int main()
{
    int x = 0;
    clock_t start, end;
    double elapsed;
    
    start = clock();
    
    int T[1000];
    int digits[] = {0,1,2,3,4,5,6,7,8,9};
    
    while(x < 1000)
    {
        int r = rand()%10;
        if(digits[r] < 100)
        {
            T[x]=r;
            x++;
        }
    }
    
    int p = rand()%1000;
    int j;
    int z1 = 0;
    int z2 = 0;
    int z3 = 0;
    int z4 = 0;
    int n = 0;
    
    for(j = 0; j < 1000; j++ )
    {
        if(p < 1000)
        {
            z1 = T[p];
            swap(&T[p], &T[0]);
        }
        else
        {
            z1 = T[0];
        }
        if(p < 999)
        {
            z2 = T[p+1];
            swap(&T[p+1], &T[0]);
        }
        else
        {
            z2 = T[0];
        }
        if(p < 998)
        {
            z3 = T[p+2];
            swap(&T[p+2], &T[0]);
        }
        else
        {
            z3 = T[0];
        }
        if(p < 997)
        {
            z4 = T[p+3];
            swap(&T[p+3], &T[0]);
        }
        else
        {
            z4 = T[0];
        }
        
        n = (z1 << 12) | (z2 << 8) | (z3 << 4) | z4;
        
        p = z1 * pow(10, 2) + z2 * pow(10, 1) + z3 * 10;
        
        printf("n:%d | p:%d\n", n, p);
    }
    end = clock();
    
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("total time: %f\n", elapsed);
    
    return 0;
}


