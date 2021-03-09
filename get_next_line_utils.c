/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:56:14 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/08 11:31:41 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		look_slash_n(char *cad, int *controlador)
{
	int i;

	i = 0;
	while (*(cad + i) != '\0')
	{
		if (*(cad + i) == '\n')
		{
			*controlador = 1;
			break ;
		}
		i++;
	}
	return (i);
}
