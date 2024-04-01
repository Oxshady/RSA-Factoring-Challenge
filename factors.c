#include <stdio.h>
#include <stdlib.h>

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
	{
		p++;
	}

	if (p * p > n)
	{
		printf("%u*%u\n", n, 1);
	}
	else
	{
		printf("%u*%u\n", p, n / p);
	}
}

int main(int argc, char *argv[])
{

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *filename;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return 1;
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return 1;
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		unsigned int n = atoi(line);
		factorize(n);
	}

	free(line);
	fclose(file);

	return 0;
}
