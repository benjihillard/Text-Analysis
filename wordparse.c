#include "wordparse.h"
 #include <errno.h>
void parse(gloss* head,int file)
{
  size_t s = 1;
  char buf[s]; // buffer reads 1 char at a time
  char word[84]; //hold each word (fun fact the longest english word is 84 char)
  int cnt; // holds number of chars read
  while((cnt = read(file,buf,s))>0){ //while there are char left to read
    if(alphabet(buf[0])==1){ //if current char is in the alphabet
      if(word[0]=='\0'){ //if word is empty
        strcpy(word,buf); //copy char in
      }else{
        strcat(word,buf);//concat char to word
      }
    }else{ // else add word to data structure
      if(single(word)==1){ //filters out single letter except a and I
        if(word!=NULL){ // filters out NULL words
          //printf("%s\n",word );
          add(head,word); //add to data structure
          word[0]='\0'; // reset word
        }
      }
    }
  }

}

int alphabet(char letter)
{
  int yes = 0;
  char alph[62] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; // the alphabet
  for (int i = 0; i < 62; i++) { //for 2*26 letters
    if(letter == alph[i]){ //check if letter is is on of 62 letters in alphabet
      yes = 1; // set yes to true
    }
  }
  return yes;
}

int single(char* word)
{
  if(word[1]=='\0' && word[0]!='A' && word[0]!='a' && word[0]!='I'){ // make sure single char words are either a,A or I
    return 0;
  }
  if(word[0]=='\0'){ //check for null word
    return 0;
  }
  return 1;
}
