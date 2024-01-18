#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int	i;
	char* fileName = "text.txt";
	int fd = open(fileName, O_RDWR);
	char *buff;

	i = 0;
	while (i < 5)
	{
		buff = buffer_until_line(fd);
		printf("*************RUN %d of function*************\n TEXT: %s********************************************\n\n", i, buff);
		free(buff);
		i++;
	}
	return (0);
}

