#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
   
    char buffer[1024];
    int bytesRead = 0;
    
    int cs_fd = open("/tmp/fifo_client_server", O_WRONLY);
    
    buffer[0]='\0';
    char * fOrig=strdup(argv[2]);
    strcat(buffer,fOrig);
    strcat(buffer," ");
    char * fFinal=strdup(argv[3]);
    strcat(buffer,fFinal);
    strcat(buffer," ");
    int i=4;int j=0;
    char *filtros[argc-i];
    while(i<=argc){
	filtros[j]=strdup(argv[i]);
        strcat(buffer,filtros[j]);
        strcat(buffer," ");

	j++;i++;
    }
    write(cs_fd,buffer,strlen(buffer));
    close(cs_fd);

    return 0;
}
