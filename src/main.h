#pragma once
#include "utils.h"

int init();

int main(int argc, char* argv[]);

int handle_keygen(int argc, char* argv[]);

int encrypt_file(int argc, char* argv[]);

int decrypt_file(int argc, char* argv[]);

int get_file(char * filepath, char* buffer, int buffer_size);

int get_file_size(char * filepath);