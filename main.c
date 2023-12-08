#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>



int main(){

	char* fileName = "text.txt";
	int fd = open(fileName, O_RDWR);
	char *buff;
	buff = get_next_line(fd);
	printf("File Contents: %s\n", buff);

	return 0;
}
