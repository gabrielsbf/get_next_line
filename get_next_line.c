/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:39:15 by gabrfern          #+#    #+#             */
/*   Updated: 2024/01/18 09:39:19 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *main_str, char *complement)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;

	if (main_str == NULL || complement == NULL)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (main_str[s1_len] != '\0')
		s1_len++;
	while (complement[s2_len] != '\0')
		s2_len++;
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	ft_gnl_strlcpy(ptr, main_str, ft_gnl_strlen(main_str) + 1);
	free(main_str);
	ft_gnl_strcat(complement, ptr);
	return (ptr);
}

char	*return_line(char *ent_line)
{
	int		i;
	char	*ptr;

	i = 0;
	while (ent_line[i] != '\n')
		i++;
	//printf("i represents the number %d on the loop\n", i);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (ent_line[i] != '\n')
	{
		ptr[i] = ent_line[i];
		//printf("character is : %c, index is %d\n", ptr[i], i);
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
	//printf("i_iteration is: %d\n", i);
	ptr = (char *)malloc(i * sizeof(char));
	i = 0;
	while (*(lb_point + i + 1) != '\0')
	{
		ptr[i] = *(lb_point + i + 1);
		i++;
	}
	ptr[i] = '\0';
	//printf("ptr value is: %s\n", ptr);
	return (ptr);
}

char	*buff_process(char *buff, char *ent_line, int *buff_sz)
{
	char	*tmp;

	tmp = ft_gnl_strdup(ent_line, *buff_sz);
	free(ent_line);
	ent_line = ft_gnl_strjoin(tmp, buff);
	free(tmp);
	free(buff);

	printf("buff_sz is : %d and buff is: %s\n", *buff_sz, buff);
	free(buff);
	return (ent_line);
}

char	*read_process(int fd, int *buff_size)
{
	char	*buffer;
	char	*tmp;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buff_size = read(fd, tmp, BUFFER_SIZE);
	if (*buff_size <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[BUFFER_SIZE] = '\0';
	if (*buff_size < BUFFER_SIZE && buff_size > 0)
	{
		buffer = (char *)malloc((*buff_size + 1) * sizeof(char));
		ft_gnl_strlcpy(buffer, tmp, *buff_size + 1);
		if (!buffer)
			return (NULL);
		free(tmp);
		return (buffer);
	}
	return (tmp);
}


char	*line_process(int fd)
{
	int			buff_size;
	static char	*storage;
	char		*ent_line;
	char		*buffer;

	ent_line = NULL;
	buff_size = BUFFER_SIZE;
	if (storage != NULL)
	{
		printf("storage is %s\n", storage);
		ent_line = ft_gnl_strdup(storage, ft_gnl_strlen(storage));
		free(storage);
		storage == NULL;
	}
	while (buff_size == BUFFER_SIZE && ft_gnl_strchr(ent_line, '\n') != 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		buff_size = read(fd, buffer, BUFFER_SIZE);
		buffer[buff_size] = '\0';
		if (buff_size <= 0)
		{
			free(buffer);
			return (NULL);
		}
		if (!ent_line)
			ent_line = ft_gnl_strdup(buffer, buff_size);
		else
			ent_line = buff_process(buffer, ent_line, &buff_size);
			//printf("INSIDE WHILE - function strchr catch a line break\n, the buffer in question is: %s\n", ent_line);
	}
	storage = store_after_lb(ent_line);
	ent_line = return_line(ent_line);
	// printf("ent line is : %s\n",ent_lin	}
	printf("storage  at the final of function is: %s\n", storage);
	return (ent_line);
}

