/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:23:41 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/04 13:47:45 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int				fd;
	int				i;
	//static int		cont;
	//int 			cont2;
	char			*line = NULL;
	int				result = 1;

	//cont = 0;
	//cont2 = 0;
	i = 0;
	fd = open("1.txt", O_RDONLY);
	while (result != 0 && result != -1)
	{
		result = get_next_line(fd, &line);
		printf ("%d---->%s<----\n", result, line);
		i++;
	}
	
	system("leaks a.out");
	printf("resultado final: %d\n", result);
	close(fd);
}