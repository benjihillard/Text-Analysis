#include "glossary.h"


gloss* create(char* word, int count)
{
  gloss* ptr = NULL;
  ptr = (gloss*)malloc(sizeof(gloss)); //alocate room for new glossary index
  if (ptr == NULL){return NULL;}
  ptr->next = NULL;
  ptr->word = (char*)malloc(85*sizeof(char)); //allocate room for 85 char word
  strcpy(ptr->word,word);
  ptr->count = count;
  return ptr;
}

int hash(char* word)
{
  char alp[26] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    if(word[0] == alp[i]){return i;}
  }
}

void add(gloss* head, char* word)
{
  gloss* temp = head; //set temp to not change location of head
  while(temp->next != NULL){ //while not at bottom of list
    if(strcasecmp(word,temp->next->word)==0){ // if word (not case sensitive) is eqaul to word at index in the list
      temp->next->count++; // incriment counter
      return;
    }
    temp = temp->next; //else check next in list
  }
  temp->next = create(word,1); // if word doesnt exist in list, create new index with count 1 of current word at bottom of list
}

void print(gloss* head, int file)
{
  gloss* temp;
  temp = head;
  while(temp->next != NULL){ //while not at bottom of list
    char str[10]; // 10 digit largest int
    write(file,temp->next->word,84); // write word with space for largest word
    sprintf(str,"%d",temp->next->count); //turn int to string
    write(file,str,place(temp->next->count)); //write count with space for amount of digits
    write(file,"\n",1); // goto next line
    temp = temp->next; //goto next on the list
  }
}

int place(int number)
{
  int i = 0;
  while(number != 0){
    number = number/10; //divide by 10 until number = 0
    i++; // incriment i for every power of 10
  }
  return i; //return amount of digits
}

void clear(gloss* head)
{
  while (head != NULL){
    gloss* temp = head;
    head = head->next; //move one down the list
    free(temp);  //free previous location
  }
}
