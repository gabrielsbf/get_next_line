/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:39:06 by gabrfern          #+#    #+#             */
/*   Updated: 2024/01/18 09:39:11 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
// STDIO - RETIRAR BIBLIOTECA DEPOIS

# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *s, int size_buff);
size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size);
size_t	ft_gnl_strcat(char *dst, char *src);
int		ft_gnl_strlen(char *s);
char	*return_line(char *ent_line);
char	*store_after_lb(char *buffer);
char	*read_process(int fd, int *buff_size, char *ent_line);

#endif
