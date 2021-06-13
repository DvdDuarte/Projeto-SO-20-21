#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
   
    char buffer[1024];
    int bytesRead = 0;
    
    if(argc>1){
	    switch(argv[1]){
		case "status":
			//executar status
			break;
    		case "transform":
			//executar os filtros
			char * fOrig=strdup(argv[2]);
			char * fFinal=strdup(argv[3]);
			int i=4;int j=0;
			char *filtros[argc-i];
			while(i<=argc){
				filtros[j]=strdup(argv[i]);
				j++;i++;
			}
			//blabla
			break;
		//outros casos
	    }
    } else {
    
    }
    
    return 0;	
   }    

		    
		    
/*	bulhufas daqui para baixo, mas pode ser util
 *
 *	while((bytesRead= read(0,buffer,1024))>0){
	int cs_fd = open("/tmp/fifo_client_server", O_WRONLY);
	int sc_fd = open("/tmp/fifo_server_client", O_RDONLY);
	write(cs_fd,buffer,bytesRead);
	close(cs_fd);
	
	while((bytesRead = read(sc_fd, buffer, 1024)) > 0) 
        	write(1, buffer, bytesRead);
	close(sc_fd);
    	}}}
    //}
*/
/*else{
	opcoes de coisas a serem feitas
	int cs_fd=open("/tmp/fifo_client_server", O_WRONLY);
	write(cs_fd,buffer,strlen(buffer));
	close(cs_fd);
	
	int bytesRead=0;
	int sc_fd=open("/tmp/fifo_server_client",O_RDONLY);
	while((bytesRead=read(sc_fd,buffer,1024))>0)
		write(0,buffer,bytesRead);
	close(sc_fd);
*/	
    //close(fd);
