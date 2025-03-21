#pragma once
#include <sodium.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define KEYLEN 32


typedef struct
{
    int len;
    char * chars;

} String;

int get_random(int min, int max);

void crypto_random_with_seed(unsigned char *buffer, size_t length, const unsigned char *seed);

void generate_key(char * filename);