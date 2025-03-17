#include "main.h"

int init()
{
	if (sodium_init() < 0)
	{
		printf("Failed to initialize libsodium\n");
		return 1;
	}

	return 0;
}


int main(int argc, char* argv[])
{
	if (init() == 1)
	{
		return 1;
	}
	if (argc < 2)
	{
		printf("Not enough args\n");
		return 1;
	}

	if (strcmp(argv[1], "genkey") == 0)
	{
		printf("[Info] Initializing Keygen");
		if (handle_keygen(argc, argv) == 1)
		{
			return 1;
		}
	}

	return 0;
}


int handle_keygen(int argc, char* argv[])
{
	FILE * fptr;

	if (argc < 3)
	{
		fptr = fopen(argv[2], "w");	
	}
	else
	{
		fptr = fopen("00000000.key", "w");
	}

	fprintf(fptr, "Some text");
	fclose(fptr);

	return 0;
}