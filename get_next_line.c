/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:05:24 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/02/23 13:48:02 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char *restos;
	char buf[BUFFER_SIZE + 1];
	char *aux = NULL;
	int n_bytes = 1;
	int i;
	int comprobador;

	if (fd == -1)
		return (-1);
	comprobador = 1;
	*line = compro_restos(restos, &comprobador);
	//printf ("%s", restos);
	while (comprobador != 0)
	{
		i = 0;
		if ((n_bytes = read(fd, buf, BUFFER_SIZE)) <= 0)
			comprobador = 0;
		buf[n_bytes] = '\0';
		while (*(buf + i) != '\0')
		{
			if (*(buf + i) == '\n')
			{
				comprobador = 0;
				break;
			}
			i++;
		}
		if (*(buf + i) == '\n')
			restos = ft_substr(buf, i + 1, BUFFER_SIZE - i - 1);
		if (n_bytes <= 0)
			i = n_bytes;
		if (aux == NULL)
			aux = ft_substr(buf, 0, i);
		else
			aux = ft_strjoin(aux, ft_substr(buf, 0, i));
		//restos = &buf[i + 1];
		//printf ("bytes           %d             ", n_bytes);
		*line = aux;
	}
	
	//printf ("%s\n", *line);
	//printf ("%s", aux);
	//printf("la linea es:    %s\n", *line);
	//printf("el resto de la cadena es:     %s\n", restos);
	//printf("\n");
	return(n_bytes);
}






	/*if (restos != NULL)
	{
		i = 0;
		while (*(restos + i) != '\0')
		{
			if (*(restos + i) == '\n')
			{
				comprobador = 0;
				break;
			}
			i++;
		}
		aux = ft_substr(restos, 0, i);
		if (*(restos + i) == '\n')
			restos = ft_substr(restos, i + 1, BUFFER_SIZE - i - 1);
		*line = aux;
	}*/