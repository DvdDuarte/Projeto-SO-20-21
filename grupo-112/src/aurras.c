#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]) {
   
    char buffer[1024];
    buffer[0]='\0';
    int bytesRead = 0;

    int i = 1;
    
    int cs_fd = open("../tmp/fifo_client_server", O_WRONLY);

    if(argc == 1){
        write(1,"./aurras status\n",16);
        write(1,"./aurras transform <ficheiro original> <ficheiro destino> <filtros>\n",68);
    }else{  
        while(i != argc){
            write(cs_fd,argv[i],strlen(argv[i]));
            write(cs_fd," ",1);
            i++;
        }
    }

    
    close(cs_fd);

    /*
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
    */

    

    return 0;
}
