/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:10:16 by javi              #+#    #+#             */
/*   Updated: 2021/02/26 19:03:17 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int n_bytes = 1;
	int i;
	static char *restos = NULL;
	char *aux = NULL;

	if (restos != NULL)
	{
		i = 0;
		while (*(restos + i) != '\0')
		{
			if (*(restos + i) == '\n')
			{
				restos = ft_substr(restos, i + 1, BUFFER_SIZE - i - 1);
				aux = ft_substr(restos, 0, i);
				*line = aux;
				return (1);
			}
			i++;
		}
		aux = ft_substr(restos, 0, i);
		*line = aux;
	}

	while ((n_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (*(buf + i) != '\0')
		{
			if (*(buf + i) == '\n')
			{
				//rellenar(buf, line, restos, i, n_bytes);
				if (*(buf + i) == '\n')
					restos = ft_substr(buf, i + 1, BUFFER_SIZE - i - 1);
				if (n_bytes <= 0)
					i = n_bytes;
				if (aux == NULL)
					aux = ft_substr(buf, 0, i);
				else
					aux = ft_strjoin(aux, ft_substr(buf, 0, i));
				*line = aux;
				//printf ("%s\n", *line);
				//printf ("%s", aux);
				printf("la linea es:    %s\n", *line);
				printf("el resto de la cadena es:     %s\n", restos);
				printf("\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}

/*void rellenar(char *buf, char **line, char *restos, int i, int n_bytes)
{
	char *aux = NULL;

	if (*(buf + i) == '\n')
		restos = ft_substr(buf, i + 1, BUFFER_SIZE - i - 1);
	if (n_bytes <= 0)
		i = n_bytes;
	if (aux == NULL)
		aux = ft_substr(buf, 0, i);
	else
		aux = ft_strjoin(aux, ft_substr(buf, 0, i));
	*line = aux;
}*/