#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct config{
	char* identificador;
	char* executavel;
	int instancias;
};

typedef struct config* Config;

int executeTransform(char* args){
	//execvp("ffmpeg",);

	return 0;
}
int executeStatus(){
	
	return 0;
}
int execute(char* op,char* args){
        int ret = -1;

       if(strcmp(op, "status")==0) {executeStatus();ret=0;}
       else if(strcmp(op,"transform")==0){ executeTransform(args);ret=1;}
       else perror("opcao invalida");

        return ret;
}




int main(int argc, char const *argv[]) {

	mkfifo("../tmp/fifo_client_server",0644);
	//mkfifo("../tmp/fifo_server_client",0644);
	int op=0;
    
    int bytesRead = 0;
    //argv[1]= ficheiro de config, argv[2]= pasta dos filtros executaveis
    Config c= malloc(sizeof(struct config));
    c->identificador=strdup(argv[1]);
    c->executavel=strdup(argv[2]);
    c->instancias=0;


    //while(1) {
	  	char* buffer=malloc(sizeof(char)*1024);
	    int cs_fd = open("../tmp/fifo_client_server", O_RDONLY);
		int sc_fd = open("../tmp/fifo_client_server", O_WRONLY);

	    while((bytesRead = read(cs_fd,buffer,1024)) > 0){
	    	write(1,buffer,bytesRead);
	    	execute(strsep(&buffer," "),buffer);
	    }
	
/*
		int arg=strlen(buffer);
		int i=0;
		char *line= buffer;
		strsep(&line," ");
		char** linhas=malloc(sizeof(char*)*30);
		while(line){
			linhas[i]=strdup(strsep(&line," "));
			i++;
		}
		if(i<2){
			char * buf= "./aurras status\n./aurras transform input-filename output-filename filter-id-1 filter-id-2 ...\n";
			write(sc_fd,buf,strlen(buf));
		}
		else{
		//testa se o programa esta 
		/*	switch(linhas[1]){
				case "transform":
					break;
				case "status":
					break;
				deafault:
					//erro?
					break;
			}
		}*/
		close(cs_fd);
		//close(sc_fd);	
  // }
   //close(cs_fd);

  //  unlink(cs_fd);//rever
  //  unlink(sc_fd);//rever
   
   return 0;
}


