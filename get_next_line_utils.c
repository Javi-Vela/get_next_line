/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:56:14 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/02/27 12:17:19 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	cont;
	size_t	i;

	cont = 0;
	i = 0;
	if (start >= ft_strlen(s) && (len + start) >= ft_strlen(s))
	{
		if (!(aux = (char *)malloc(sizeof(char)+ 1)))
			return (NULL);
		aux[cont] = '\0';
		return (aux);
	}
	if (!(aux = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	aux[len] = '\0';
	while (cont < len)
	{
		aux[i] = s[cont + start];
		cont++;
		i++;
	}
	return (aux);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	tam;
	size_t	cont;
	size_t	i;

	tam = ft_strlen(s1) + ft_strlen(s2);
	cont = 0;
	i = 0;
	if (!(aux = (char *)malloc(sizeof(char) * (tam + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		aux[cont] = s1[i];
		cont++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		aux[cont] = s2[i];
		cont++;
		i++;
	}
	aux[cont] = '\0';
	return (aux);
}

int	compro_restos(char *restos, char **line)
{
	int		i;
	char	*aux;
	int		controlador;

	aux = NULL;
	i = 0;
	controlador = 3;
	if (restos != NULL)
	{
		puts("bbb");
		i = 0;
		while (*(restos + i) != '\0')
		{
			if (*(restos + i) == '\n')
			{
				controlador = 1;
				break;
			}
			i++;
		}
		aux = ft_substr(restos, 0, i);
		if (*(restos + i) == '\n')
			restos = ft_substr(restos, i + 1, BUFFER_SIZE - i - 1);
		*line = aux;
	//	printf ("%s", line);
	}
	return (controlador);
}