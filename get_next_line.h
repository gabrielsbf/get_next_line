#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 820
#endif
#include <unistd.h>
#include <stdlib.h>
// STDIO - RETIRAR BIBLIOTECA DEPOIS
#include <stdio.h>

char	*buffer_until_line(int fd);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strdup(char *s, int size_buff);
size_t	ft_gnl_strcpy(char *src, char *dst);
size_t	ft_gnl_strcat(char *src, char *dst);
int		ft_gnl_strlen(char *s);
char	*return_line(char *ent_line);
char	*store_after_lb(char *buffer);
void	buffering_process (int buff_size, char *storage, char *buffer, char *ent_line);

#endif
