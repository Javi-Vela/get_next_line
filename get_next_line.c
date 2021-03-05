/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:05:24 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/05 12:12:39 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*restos;
	char		buf[BUFFER_SIZE + 1];
	char		*aux;
	int			n_bytes;
	int			comprobador;

	aux = *line;
	n_bytes = 1;
	if (fd == -1)
		return (-1);
	comprobador = 3;
	aux = compro_restos(&restos, &comprobador);
	while (comprobador != 0 && comprobador != 1)
	{
		if ((n_bytes = read(fd, buf, BUFFER_SIZE)) <= 0)
			comprobador = 0;
		buf[n_bytes] = '\0';
		aux = compro_buf(buf, &restos, aux, &comprobador);
		
	}
	*line = ft_substr(aux, 0, ft_strlen(aux));
	free (aux);
	return (comprobador);
}
