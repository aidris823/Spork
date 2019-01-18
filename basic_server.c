#include "pipe_networking.h"


static void sighandler(int signo){
  if (signo == SIGINT){
    remove("Luigi");
    exit(1);
  }
}

int main() {

  int to_client;
  int from_client;

  while (1){
    //fork();
    from_client = server_handshake( &to_client );
    char * steve = calloc(100,1);
    while(read(from_client,steve,100)){
	printf("Client says: %s",steve);
	char * appendix = "[This was understood by the server.]";
	strcat(steve,appendix);
	write(to_client,steve,100);
    }
  }
}
   
