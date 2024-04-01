#include "factors.h"
void factorize(unsigned int n)
{
	printf("%u=", n);

	if (n < 0)
	{
		printf("%u*%u\n", n, -1);
		return;
	}

	unsigned int p = 2;

	while (p * p <= n && n % p != 0)
		p++;

	if (p * p > n)
		printf("%u\n", n);
	else
		printf("%u*%u\n", p, n / p);
}
