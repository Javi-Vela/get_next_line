#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*compro_restos(char *restos, int *comprobador);

#endif
