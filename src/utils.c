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