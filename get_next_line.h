#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif
#include <unistd.h>
#include <stdlib.h>
// STDIO - RETIRAR BIBLIOTECA DEPOIS
#include <stdio.h>

char	*check_line(char *buffer, size_t bytes_read);
char	*buffer_until_line(int fd);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strdup(char *s);
size_t	ft_gnl_strcpy(char *src, char *dst);
size_t	ft_gnl_strcat(char *src, char *dst);

#endif
