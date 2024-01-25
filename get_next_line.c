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
	ft_gnl_strcat(ptr, complement) ;
	return (ptr);
}

char	*return_line(char *ent_line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!ent_line)
		return (NULL);
	while (ent_line[i] != '\n' && ent_line[i] != '\0')
		i++;
	if (ent_line[i] == '\n')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if(ent_line[i - 1] == '\n')
		ptr[i - 1] = '\n';
	ptr[i] = '\0';
	i = 0;
	while (ent_line[i] != '\n' && ent_line[i] != '\0')
	{
		ptr[i] = ent_line[i];
		i++;
	}
	free(ent_line);
	return (ptr);
}

char	*store_after_lb(char *buffer)
{
	int		i;
	char	*lb_point;
	char	*ptr;

	lb_point = ft_gnl_strchr(buffer, '\n');
	if (lb_point == 0)
		return (NULL);
	i = 0;
	while (*(lb_point + i) != '\0')
		i++;
	ptr = (char *)malloc(i * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(lb_point + i + 1) != '\0')
	{
		ptr[i] = *(lb_point + i + 1);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*read_process(int fd, int *buff_size, char *ent_line)
{
	char	*tmp;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	*buff_size = read(fd, tmp, BUFFER_SIZE);
	if (*buff_size <= 0)
	{
		free(tmp);
		return (ent_line);
	}
	tmp[*buff_size] = '\0';
	if (!ent_line)
		ent_line = ft_gnl_strdup(tmp, *buff_size);
	else
		ent_line = ft_gnl_strjoin(ent_line, tmp);
	free(tmp);
	return (ent_line);
}

char	*get_next_line(int fd)
{
	int			buff_size;
	static char	*storage;
	char		*ent_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ent_line = NULL;
	buff_size = BUFFER_SIZE;
	if (storage != NULL)
	{
		ent_line = ft_gnl_strdup(storage, ft_gnl_strlen(storage));
		free(storage);
		storage = NULL;
	}
	while (buff_size == BUFFER_SIZE && ft_gnl_strchr(ent_line, '\n') == 0)
			ent_line = read_process(fd, &buff_size, ent_line);
	storage = store_after_lb(ent_line);
	ent_line = return_line(ent_line);
	return (ent_line);
}
