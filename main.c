#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int	i;
	char* fileName = "tests/41_no_nl";
	int fd = open(fileName, O_RDWR);
	char *buff;

	i = 0;
	while (i > -1)
	{
		buff = get_next_line(fd);
		// printf("*************RUN %d of function*************\nTEXT: %s********************************************\n\n", i, buff);
		if (!buff)
			break;
		printf("%s",buff);
		free(buff);

		i++;
	}
	free(buff);
	close(fd);
	return (0);
}
