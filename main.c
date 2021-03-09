/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvela-ca <jvela-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:23:41 by jvela-ca          #+#    #+#             */
/*   Updated: 2021/03/08 11:53:46 by jvela-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		main()
{
	//int				fd;
	//int				i;
	//static int		cont;
	//int 			cont2;
	char			*cad = NULL;
	//int				result = 1;

	printf("          -----------------------------------------\n");
	printf("          -------------------BONUS-----------------\n");
	printf("          -----------------VARIOS FD---------------\n");
	printf("          -----------------------------------------\n");
	int salida;
	printf("\n\n");
	printf("\n\n");
	int fd = open("1.txt", O_RDONLY);
	int fd2 = open("2.txt", O_RDONLY);
	int fd3 = open("lotr.txt", O_RDONLY);
	salida = get_next_line(fd,&cad);
	printf("fd-linea1**SALIDA: %d ***LINEA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd2,&cad);
	printf("fd2-linea1**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd,&cad);
	printf("fd-linea2**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd,&cad);
	printf("fd-linea3**SALIDA: %d ***LINEA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd3,&cad);
	printf("fd3-linea1**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd2,&cad);
	printf("fd2-linea2**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd,&cad);
	printf("fd-linea4**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	salida = get_next_line(fd3,&cad);
	printf("fd3-linea2**SALIDA: %d ****ULTIMA --->%s<---\n",salida,  cad);
	free(cad);
	close(fd);
	close(fd2);
	close(fd3);








	/////////////////////////////////////////////test sin bonus////////////////////////////////////////////

	//cont = 0;
	//cont2 = 0;
	/*i = 0;
	fd = open("1.txt", O_RDONLY);
	while (result != 0 && result != -1)
	{
		result = get_next_line(fd, &line);
		printf ("%d---->%s<----\n", i, line);
		free (line);
		i++;
	}
	//system("leaks a.out");
	//printf("resultado final: %d\n", result);
	close(fd);*/
}