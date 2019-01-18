#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  if (mkfifo("Luigi",0644) == -1){
    printf("Failure to make pipe. =(");
  }
  
  int wk_pipe = open("Luigi",O_RDONLY);
  printf("The server has opened pipe\n");
  
  char * client_message = calloc(100,1);
  read(wk_pipe,client_message,4);
  printf("Server thinks the client said: %s\n",client_message);
  
  int pipe = open(client_message,O_WRONLY);
  printf("Server opened another pipe for client\n");
  
  write(pipe,ACK,sizeof(ACK));
  
  *to_client = pipe; //*to_client or to_client?  You say *to_client so I'll take your word.
  printf("Server has completed its run");
  return wk_pipe;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  mkfifo("Kiddo",0644);
  
  int wk_pipe = open("Luigi",O_WRONLY);
  printf("The client has accessed the well known pipe.");
  
  write(wk_pipe,"Kiddo",4);
  
  int p_pipe = open("Kiddo",O_RDONLY);
  char * message = calloc(10,1);
  read(p_pipe,message,10);
 
  *to_server = wk_pipe;
  printf("The client has shooketh hands.");
  return p_pipe;
  //while(1){fork()} is what I feel like doing to my computer.
  

}
