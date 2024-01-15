#include "get_next_line.h"

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

int	main()
{
	char *s1 = "i'm making a";
	char *s2 = "test";
	printf("entire text is : %s", ft_gnl_strjoin(s1, s2));
}
