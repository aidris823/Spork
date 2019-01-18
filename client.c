#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  char * read_steve = calloc(100,1);
  char * write_steve = calloc(100,1);

  while(1){
    //fork();
    printf("Welcome to the warp zone! Enter which world: (Or anything really \n");
    fgets(read_steve,100,stdin);
    read_steve[strlen(read_steve)-1] = (char)'/0';//Apparently this is how to make a null charNULL;
    write(to_server,read_steve,100);
    read(from_server,write_steve,100);
    printf("Survey[er] says... %s\n",write_steve);
  }
}
