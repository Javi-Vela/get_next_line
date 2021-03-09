/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:05:24 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/08 11:39:23 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	liberar(char *aux, int comprobador, char **restos)
{
	free(aux);
	aux = 0;
	if (comprobador == 0)
	{
		free(*restos);
		*restos = NULL;
	}
}

char	*compro_restos(char **restos, int *controlador)
{
	int		i;
	char	*aux;
	char	*aux2;

	i = 0;
	aux = NULL;
	if (*restos != NULL)
	{
		i = 0;
		i = look_slash_n(*restos, controlador);
		aux = ft_substr(*restos, 0, i);
		if (*(*restos + i) == '\n')
		{
			aux2 = *restos;
			*restos = ft_substr(*restos, i + 1, BUFFER_SIZE - i - 1);
			free(aux2);
		}
	}
	return (aux);
}

char	*compro_buf(char *buf, char **restos, char *aux, int *comprobador)
{
	int		i;
	char	*temp;
	char	*aux2;
	char	*aux3;

	i = 0;
	aux3 = *restos;
	i = look_slash_n(buf, comprobador);
	if (*(buf + i) == '\n')
	{
		*restos = ft_substr(buf, i + 1, BUFFER_SIZE - i - 1);
		free(aux3);
	}
	if (aux == NULL)
		aux2 = ft_substr(buf, 0, i);
	else
	{
		temp = ft_substr(buf, 0, i);
		aux2 = ft_strjoin(aux, temp);
		free(temp);
		free(aux);
	}
	return (aux2);
}

int		get_next_line(int fd, char **line)
{
	static char	*restos;
	char		buf[BUFFER_SIZE + 1];
	char		*aux;
	int			n_bytes;
	int			comprobador;

	*line = NULL;
	n_bytes = 1;
	if (fd == -1 || fd > FOPEN_MAX)
		return (-1);
	comprobador = 3;
	aux = compro_restos(&restos, &comprobador);
	while (comprobador != 0 && comprobador != 1)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes <= 0)
			comprobador = 0;
		buf[n_bytes] = '\0';
		aux = compro_buf(buf, &restos, aux, &comprobador);
	}
	*line = ft_substr(aux, 0, ft_strlen(aux));
	liberar(aux, comprobador, &restos);
	return (comprobador);
}
