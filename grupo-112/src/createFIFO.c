#include <sys/types.h>
#include <sys/stat.h>

//redundante??
int main (int argc, char const* argv[]){
	mkfifo("../tmp/fifo",0644);
	return 0;
}
