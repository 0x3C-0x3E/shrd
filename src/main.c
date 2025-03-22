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
		if (argc < 4)
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

	if (strcmp(argv[1], "dec") == 0)
	{
		if (argc < 4)
		{
			printf("Not enough args\n");
			return 1;
		}

		printf("[Info] Initializing Decryption\n");
		if (decrypt_file(argc, argv) == 1)
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
	FILE * key_file_ptr = fopen(argv[3], "r");

	if (enc_file_ptr == NULL || key_file_ptr == NULL)
	{
		printf("could not open file\n");
		return -1;
	}


	// get key
	char key[KEYLEN] = {0};

	fgets(key, KEYLEN, key_file_ptr);
	fclose(key_file_ptr);
	printf("[INFO] Read Key as: %s\n", key);


	// get enc file size
	fseek(enc_file_ptr, 0, SEEK_END);
	int size = ftell(enc_file_ptr);
	fseek(enc_file_ptr, 0, SEEK_SET);

	printf("[INFO] Read Encrytion file length to be: %d\n", size);

	char enc_file[size] = {0};

	fgets(enc_file, size, enc_file_ptr);

	printf("[INFO] Read File contents: %s\n", enc_file);

	fclose(enc_file_ptr);

	//write to file
	enc_file_ptr = fopen(argv[2], "w");

	char cipher_text[size] = {0};

	crypto_random_with_seed((unsigned char *) cipher_text, size , (unsigned char *) &key);

	printf("[INFO] generated cipher text as: %s\n", cipher_text);

	for (int i = 0; i < size; i++)
	{
		enc_file[i] = enc_file[i] ^ cipher_text[i];
	}

	printf("[INFO] created new output as %s\n", enc_file);

	fputs(enc_file, enc_file_ptr);

	fclose(enc_file_ptr);


	return 0;
	
}

int decrypt_file(int argc, char* argv[])
{
	return 0;	
}