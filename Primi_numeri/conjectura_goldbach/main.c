#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BOOL unsigned int
#define TRUE  1
#define FALSE 0

#define A 100
#define B 1000
#define C 10000
#define D 100000


/*     Conjectura Goldbach    
 *
 *
 *
 *
 * 
*/

//
typedef unsigned long long u64;


// prime test algo :
BOOL isprime(u64 n)
{
    //
    for(u64 d = 2; pow(d,2) < (n+1); ++d)
    {
        if (n%d == 0)
            return FALSE;
    }
    return TRUE;
}


//
BOOL Goldbach(u64 n)
{
    //
    for (u64 i = 1; i < n; i++)
    {
        //
        if (isprime(i) && isprime(n - i))
        {
            // printf("%llu = %llu (i) + %llu (j)  , with i and j prime \n", n, i, (n-i));
            return TRUE;
        }   
    }
    return FALSE;
}


// Test
int test_conjecture(u64 N)
{
    //
    u64 cpt = 0;
    //
    for(u64 i = 4; i < N; i+=2)
    {
        //
        if (Goldbach(i))
            cpt++;
        else
        {
            printf("%llu can be written like : q + p, with q and p prime \n", i);
            return 0;
        }
    }

    //
    printf("N : %llu, cpt : %llu \n All even < N and > 3 can be write like : p+q with p and q prime numbers \n", N, cpt);
    return 1;
}

//
int main(int argc, char **argv)
{
    //
    if (argc == 2 && (strlen(argv[1]) == 1))
    {
        //
        char option = argv[1][0];

        // program
        switch (option)
        {
        case 'a':
            test_conjecture(A);
            break;
        case 'b':
            test_conjecture(B);
            break;
        case 'c':
            test_conjecture(C);
            break;
        case 'd':
            test_conjecture(D);
            break;
        default:
            test_conjecture(B);
            break;
        }
        
    }
    else
    {
        //
        printf("Usage : %s [option] \n  (a : 100, b: 1000, etc )\n", argv[0]);
    }

    //
    return 0;
}