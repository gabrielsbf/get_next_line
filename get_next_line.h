#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1042
#endif
#include <unistd.h>
#include <stdlib.h>
// STDIO - RETIRAR BIBLIOTECA DEPOIS
#include <stdio.h>

char	*read_buffsize(int fd);
char	*check_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
