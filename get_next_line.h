#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1042
#endif
#include <unistd.h>
#include <stdlib.h>
// STDIO - RETIRAR BIBLIOTECA DEPOIS
#include <stdio.h>

char	*get_next_line(int fd);


#endif
