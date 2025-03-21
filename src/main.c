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
		printf("[Info] Initializing Keygen\n");
		if (handle_keygen(argc, argv) == 1)
		{
			return 1;
		}
	}

	if (strcmp(argv[1], "enc") == 0)
	{
		if (arc < 3)
		{
			printf("Not enough args\n");
			return 1;
		}

		printf("[Info] Initializing Encrytion\n");
		if (encrypt_file(argc, argv) == 1)
		{
			return 1;
		}
	}


	return 0;
}


int handle_keygen(int argc, char* argv[])
{
	if (argc < 3)
	{
		generate_key((char *)"0.key");
	}
	else
	{
		generate_key(argv[2]);
	}
	

	return 0;
}

int encrypt_file(int arc, char* argv[])
{
	FILE * enc_file_ptr = fopen(argv[2], "r");
	FILE * key_file_ptr = fopen(argv[3], "w");

	if (enc_file_ptr == NULL || key_file_ptr == NULL)
	{
		return -1;
	}

	unsigned char key[KEYLEN] = {0};

	fgets(key, KEYLEN, key_file_ptr);
	fclose(key_file_ptr);


	printf("[INFO] Read Key as: %s", key);

	fseek(enc_file_ptr, 0, SEEK_END);
	int size = ftell(enc_file_ptr);
	fseek(enc_file_ptr, 0, SEEK_SET);

	printf("[INFO] Read Encrytion file length to be: %d", size);

	unsigned char enc_file[size] = {0};

	fgets(key, KEYLEN, key_file_ptr); 


	fclose(enc_file_ptr);
	FILE * enc_file_ptr = fopen(argv[2], "w");

	int result = fputs(enc_file, enc_file_ptr);
}