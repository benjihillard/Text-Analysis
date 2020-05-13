#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "glossary.h"


// takes a file as input parses out the words inside, then places into data structure
void parse(gloss* head,int file);
// checks to see if a certain char is in the alphabet
int alphabet(char letter);
//checks to see if word is single character(excluding i,a,A) or if word is N
int single(char* word);
