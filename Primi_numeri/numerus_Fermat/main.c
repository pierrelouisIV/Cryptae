#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define BOOL unsigned int
#define TRUE  1
#define FALSE 0


// long integer
typedef unsigned long long u64;


// Fermat's number :
u64 Fer(u64 n)
{
    return pow(2, pow(2, n)) + 1;
}


//
BOOL isprime(u64 n)
{
    for (u64 d = 2; pow(d, 2) < (n + 1); d++)
    {
        if (n%d == 0)
            return FALSE;
    }
    return TRUE;
}


//
BOOL test(u64 n)
{
    for(u64 i = 0; i < n; ++i)
    {
        if ( !isprime(Fer(i)) )
        {
            printf(" (2^2^%llu) + 1 = %llu, it's not a prime number \n", i, Fer(i));
            return FALSE;
        }
    }
    return TRUE;
}


//
int main(int argc, char  **argv)
{
    //
    // test of Fermat's number 
    if (argc == 2)
    {
        //
        u64 integer = atoll(argv[1]);
        test(integer);
    }
    else
    {
        printf("Usage: %s [integer] \n", argv[0]);
    }
    return 0;
}