#include "wordfreak.h"

int main(int argc, char const *argv[],char *envp[])
{
  int file;
  int err;
  gloss* head = create("-----",0);
  int output;
  if((output = open("output.txt",O_CREAT))==-1){printf("%s\n", strerror(errno));} //create text file to place output data
  if((output = open("output.txt",O_WRONLY))==-1){printf("%s\n", strerror(errno));}  // set to write only
  if(getenv("WORD_FREAK")!=NULL){
    if((file = open(getenv("WORD_FREAK"),O_RDONLY))==-1){printf("%s\n", strerror(errno));}
    parse(head,file);
  }
  else if(argc == 1){ // if only one argument then read from stdin
    file = 0; //stdin
    parse(head,file); //places all words from file into linked list
  }else{ //if more than one argument
    for(int i = 1; i < argc; i++) { //loop for amount of arguments
      if((file = open(argv[i],O_RDONLY))==-1){printf("%s\n", strerror(errno));}  //open arg i  as read only
      parse(head,file);  //places all words from file into linked list
      if(close(file)==-1){printf("%s\n", strerror(errno));} //close file when done
    }
  }
  print(head,1); // print takes data from list and prints it on output.txt
  if(close(output)==-1){printf("%s\n", strerror(errno));} // close output.txt
  gloss* temp;
  clear(head); //freeing up link list
  head = NULL; // avoid error by setting head to null
  return 0;
}
