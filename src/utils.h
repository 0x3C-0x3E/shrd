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

void generate_key(char * filename);