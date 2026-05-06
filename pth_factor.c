#include <stdio.h>
#include <math.h>

/**
 * pthFactor - finds the p-th smallest factor of a number
 * @n: the number whose factors are being determined
 * @p: the position of the desired factor 
 *
 * Description:
 * A factor is any number that divides n without a remainder
 * Factors occur in pairs
 * Iterate up to the square root of n to avoid the need to  store all factors
 *
 * Return:
 *p-th smallest factor of n, or 0 if n has fewer than p factors
 */
long long pthFactor( long long n, long long p)
{
    long long i;
    long long count = 0;

   /* find small factors */
    for (i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            count++;
            if (count == p)
                return (i);
        }
    }

    /* Count of total factors */
    long long total = count;


    /* Perfect square case adjustment */
    long long sqrt_n = (long long)sqrt(n);

    if (sqrt_n * sqrt_n == n)
        total = count * 2 - 1;
    else
        total = count * 2;


    /*if p exceeds the total factors */
    if (p > total)
        return (0);

    /* find the large factors in reverse */
    for (i = sqrt_n; i >= 1; i--)
    {
        if (n % i == 0)
        {
            long long paired = n / i;
            if (paired == i)
                continue;
            count ++;
            if (count == p)
                return (paired);
        }
    }
    return (0);
}
