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

    int fd = open("/tmp/fifo", O_RDONLY);
    int bytesRead = 0;
    char buffer[1024];
    /*while(1) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    */


    close(fd);
    return 0;
}
