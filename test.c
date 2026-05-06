#include <stdio.h>
#include "main.h"


/**
 * main - entry point to test pthFactor function
 *
 * Return: Always 0
 */
int main(void)
{
	long long n = 10;
	long long p = 3;
	long long result;

	result = pthFactor(n, p);

	printf("%lld\n", result);

	return (0);
}
