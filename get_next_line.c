
#include "get_next_line.h"

char	*ft_gnl_strchr(char *s, int c)
{
	char	*strc;
	int		i;

	strc = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&strc[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&strc[i]);
	return (0);
}

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
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

char	*check_line(char *buffer, size_t bytes_read)
{
	size_t	i;
	char	*t_line;

	i = 0;
	while (*(buffer + i) != '\n' && i < bytes_read)
		i++;
	t_line = ft_gnl_substr(buffer, 0, i);
	return (t_line);
}

size_t ft_gnl_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

size_t ft_gnl_strcat(char *src, char *dst)
{
	int	i_dst;
	int	i_src;

	i_src = 0;
	i_dst = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (dst[i_dst] != '\0')
		i_dst++;
	while (src[i_src] != '\0')
		src[i_src++] = dst[i_dst++];
	dst[i_dst] = '\0';
	return (i_dst);
}

char	*ft_gnl_strdup(char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *ft_gnl_strjoin(char *s1, char *s2)
{
	char *ptr;
	int	s1_len;
	int	s2_len;

	if(s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	ft_gnl_strcpy(s1, ptr);
	ft_gnl_strcat(s2, ptr);
	return (ptr);
}
char	*buffer_until_line(int fd)
{
	int		buff_size;
	char	*storage;
	char	*buffer;
	char	*complete;

	buff_size = BUFFER_SIZE;
	while (buff_size == BUFFER_SIZE)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		buff_size = read(fd, buffer, BUFFER_SIZE);
		if (!complete)
		{
			complete = ft_gnl_strdup(buffer);
		}
		else
		{
			storage = ft_gnl_strdup(complete);
			free(complete);
			complete = ft_gnl_strjoin(storage, buffer);
			free(storage);
		}
		if(ft_gnl_strchr(complete, '\n')!= 0)
			break ;
		free(buffer);
	}
	storage = ft_gnl_strdup(complete);
	free(complete);
	complete = ft_gnl_strjoin(storage, buffer);
	return (complete);
}

#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int	i;
	char* fileName = "text.txt";
	int fd = open(fileName, O_RDWR);
	char *buff;
	i = 0;
	while (i < 3)
	{
		buff = buffer_until_line(fd);
		printf("RUN %d of function\n TEXT: %s\n", i, buff);
		free(buff);
		i++;
	}
	return (0);
}
