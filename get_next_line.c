
#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
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

char	*return_line(char *ent_line)
{
	int i;
	char *ptr;

	i = 0;
	while (ent_line[i] != '\n')
		i++;
	// printf("i represents the number %d on the loop\n", i);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (ent_line[i] != '\n')
	{
		ptr[i] = ent_line[i];
		// printf("character is : %c, index is %d\n", ptr[i], i);
		i++;

	}
	free(ent_line);
	ptr[i] = '\n';
	ptr[i + 1] = '\0';
	return (ptr);
}

char	*store_after_lb(char *buffer)
{
	int		i;
	char	*lb_point;
	char	*ptr;

	lb_point = ft_gnl_strchr(buffer, '\n');
	i = 0;
	while (*(lb_point + i) != '\0')
		i++;
	printf("i_iteration is: %d\n", i);
	ptr = (char *)malloc(i * sizeof(char));
	i = 0;
	while (*(lb_point + i + 1) != '\0')
	{
		ptr[i] = *(lb_point + i + 1);
		i++;
	}
	ptr[i] = '\0';
	printf("ptr value is: %s\n", ptr);
	return (ptr);
}

char	*buffering_process (char *buffer, char *storage, char *ent_line, int buff_size)
{
	if (!ent_line)
		ent_line = ft_gnl_strdup(buffer, buff_size);
	else
	{
		storage = ft_gnl_strdup(ent_line, ft_gnl_strlen(ent_line));
		free(ent_line);
		ent_line = ft_gnl_strjoin(storage, buffer);
		free(storage);
		storage = NULL;
	}
	printf("Buffer_size is : %d and buffer is: %s\n",buff_size, buffer);
	free(buffer);
	return (ent_line);
}

char	*buffer_until_line(int fd)
{
	int			buff_size;
	static char	*storage;
	char		*ent_line;
	char		*buffer;

	ent_line = NULL;
	buff_size = BUFFER_SIZE;
	if(storage != NULL)
	{
		printf("storage is %s\n", storage);
		ent_line = ft_gnl_strdup(storage, ft_gnl_strlen(storage));
		free(storage);
	}
	while (buff_size == BUFFER_SIZE)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (0);
		buff_size = read(fd, buffer, BUFFER_SIZE);
		buffer[buff_size] = '\0';
		ent_line = buffering_process(buffer, storage, ent_line, buff_size);
		printf("ent line is : %s\n",ent_line);
		if(ent_line != NULL && ft_gnl_strchr(ent_line, '\n') != 0)
		{
			printf("INSIDE WHILE - function strchr catch a line break\n, the buffer in question is: %s\n", ent_line);
			storage = store_after_lb(ent_line);
			ent_line = return_line(ent_line);
			break ;
		}
	}
	printf("storage  at the final of function is: %s\n", storage);
	return (ent_line);
}
