
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE + 1] = '\0';
	printf("Bytes readed : %ld", bytes_read);
	return (buffer);

}
