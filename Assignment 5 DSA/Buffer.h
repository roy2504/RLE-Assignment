#pragma once

//Gitesh - DSA - Assignment 5

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define BUFFER_SIZE 300
#define ESCAPE_CHAR '?'

int rle_encode(const char*, char*, char); 
int rle_decode(const char*, char*,char);
void print_buffer(const char*, int);