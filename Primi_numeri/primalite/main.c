#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BOOL  unsigned int
#define TRUE  1
#define FALSE 0

/*  compilation :  gcc -o prog main.c -lm          */

//
clock_t start, end;

//
typedef unsigned long long u64;


// Exhaustive algorithm :
BOOL classical_isprime(u64 n)
{
    //
    for(u64 i = 2; i < n; ++i)
    {
        if (n%i == 0)
            return FALSE;
    }

    //
    return TRUE;
}

// much faster than the first algo
BOOL second_isprime(u64 n)
{
    //
    for(u64 d = 2; pow(d,2) < (n+1); ++d)
    {
        //
        if (n%d == 0)
            return FALSE;
    }

    //
    return TRUE;
}


// Create a prime number list
u64 *crible_eratosthene(u64 n)
{
    // var
    u64 index = 0;
    // allocate mem
    u64 * L = malloc(sizeof(u64) * n);

    // the first prime number
    L[0] = 2;

    // fill the list
    for(u64 i = 3; i < n; i+=2)
    {
        if (second_isprime(i))
        {
            L[index] = i;
            index++;
        }
    }
    //
    return L;
}




//
int main(int argc, char **argv)
{

    // test if a number is prime
    if (argc == 2)
    {
        //
        u64 integer = atoll(argv[1]);
        if (second_isprime(integer))
            printf("%llu is prime \n", integer);
        else
            printf("%llu is not prime \n", integer);
    }
    else
    {
        printf("Usage: %s [integer] \n", argv[0]);
    }

    //
    return 0;
}
