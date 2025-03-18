#include "utils.h"

int get_random(int min, int max)
{
	if (min >= max)
	{
		printf("Invalid range\n");
		return -1;
	}
	
	return min + randombytes_uniform(max - min + 1);
}


void generate_key(char * filename)
{
	FILE * fptr = fopen(filename, "w");
	if (fptr == NULL)
	{
		perror("Error opening file");
		return;
	}

	for (int i = 0; i < 32; i++)
	{
		int newchar = get_random(33, 123);

		printf("[DEBUG] newchar: %c, %d\n", (char) newchar, newchar);

		fputc(newchar, fptr);
	}

	fclose(fptr);
}