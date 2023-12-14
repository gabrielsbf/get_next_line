
#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			s_size;
	size_t			i_ptr;
	char			*ptr;

	if (!s)
		return (NULL);
	i_ptr = 0;
	s_size = 0;
	while (*(s + s_size) != '\0')
		s_size++;
	if (s_size <= start)
		len = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i_ptr < len && s_size > start)
	{
		ptr[i_ptr] = s[start];
		start++;
		i_ptr++;
	}
	ptr[i_ptr] = '\0';
	return (ptr);
}

char	*read_buffsize(int fd)
{
	char			*buffer;
	static size_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	(void)bytes_read;
	buffer[BUFFER_SIZE] = '\0';

	return buffer;

}
char	*check_line(int fd)
{
	int		i;
	char	*buffer;
	char	*t_line;

	buffer = read_buffsize(fd);
	i = 0;
	while (*buffer != '\0' && *(buffer + i) != '\n')
		i++;
	if(*(buffer + i) == '\n')
		t_line = ft_substr(buffer, 0, i);
	free(buffer);
	return (t_line);
}


