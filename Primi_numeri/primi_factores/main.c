#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL unsigned int
#define TRUE  1
#define FALSE 0

//
typedef unsigned long long u64;


// prime test algorithm
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



// decomposition in prime factors
int prime_factors(u64 n)
{
    //
    printf("Decomposition in prime factors of %llu : \n[ ", n);
    
    // Algorithm
    do
    {
        //
        for(u64 d = 2; pow(d,2) < (n+1); ++d)
        {
            //
            if (n%d == 0)
            {
                //
                n /= d;
                printf("%llu, ", d);
                break;
            }
        }
    } while(!isprime(n));

    //
    printf("%llu ]\n", n);
    return 1;
}


//
int main(int argc, char **argv)
{

    //
    prime_factors(555525);
    return 0;
}
