#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

struct config{
	char* identificador;
	char* executavel;
	int instancias;
};

typedef struct config* Config;

int main(int argc, char const *argv[]) {
	mkfifo("../tmp/fifo_client_server",0644);
	mkfifo("../tmp/fifo_server_client",0644);
	int op=0;
    
    int bytesRead = 0;
    char buffer[1024];
    while(1) {
  	char* buffer=malloc(sizeof(char)*1024);
     	int cs_fd = open("/tmp/fifo_client_server", O_RDONLY);
	int sc_fd = open("/tmp/fifo_server_client", O_WRONLY);
	read(cs_fd,buffer,1024);
	int arg=strlen(buffer);
	int i=0;
	char *line= buffer;
	strsep(&line," ");
	char** linhas=malloc(sizeof(char*)*30);
	while(line){
		linhas[i]=strdup(strsep(&line," ");
		i++;
	}
	if(i<2){
	char * buf= "./aurras status\n./aurras transform input-filename output-filename filter-id-1 filter-id-2 ...\n";
	write(sc_fd,buf,strlen(buf));
	}
	else{
	//testa se o programa esta 
		switch(linhas[1]){
			case "transform":
				break;
			case "status":
				break;
			deafault:
				//erro?
				break;
		}
	}	
   }
   close(fd);
  //  unlink(cs_fd);//rever
  //  unlink(sc_fd);//rever
    return 0;
}
