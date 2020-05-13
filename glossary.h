#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

struct Glossary
{
  struct Glossary* next;
  char* word;
  int count;
};
typedef struct Glossary gloss;

// creates new indexs for Glossary
gloss* create(char* word, int count);
// adds new word to glossary, or incriments its count if already in the glossary
void add(gloss* add, char* word);
// prints contents of glossary
void print(gloss* array, int file);
// clears out glossary and free memory
void clear(gloss* head);
// returns the number of placeholders in a number
int place(int number);

int hash(char* word);
