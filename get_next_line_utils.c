/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:56:14 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/04 14:04:52 by jvela-ca         ###   ########.fr       */
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
		if (!(aux = (char *)malloc(sizeof(char) + 1)))
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

char	*compro_restos(char **restos, int *controlador)
{
	int		i;
	char	*aux;

	i = 0;
	aux = NULL;
	if (*restos != NULL)
	{
		i = 0;
		while (*(*restos + i) != '\0')
		{
			if (*(*restos + i) == '\n')
			{
				*controlador = 1;
				break ;
			}
			i++;
		}
		aux = ft_substr(*restos, 0, i);
		if (*(*restos + i) == '\n')
			*restos = ft_substr(*restos, i + 1, BUFFER_SIZE - i - 1);
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
	aux3 = NULL;
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			*comprobador = 1;
			break ;
		}
		i++;
	}
	if (*(buf + i) == '\n')
		aux3 = ft_substr(buf, i + 1, BUFFER_SIZE - i - 1);
	if (aux == NULL)
		aux2 = ft_substr(buf, 0, i);
	else
	{
		temp = ft_substr(buf, 0, i);
		aux2 = ft_strjoin(aux, temp);
		free (aux);
		free (temp);
	}
	*restos = aux3;
	free (aux3);
	return (aux2);
}
