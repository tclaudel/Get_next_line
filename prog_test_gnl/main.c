/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 13:02:56 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 13:37:34 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *dest;
	int ret[3];
	int fd[3];
	char *dst[3];
	int i;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nBUFF SIZE = %d\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n", BUFFER_SIZE);
	printf("(0) stdin\n(1) single fd\n(2) multi fd\n(3) all\n\n");
	printf("select option : ");
	char c = getchar();
	printf("\n\n");
	if (c == '0' || c == '3')
	{
		while ((ret[0] = get_next_line(0, &dest)))
		{
			printf("retour gnl: %d~\n", ret[0]);
			printf("LINE: ~%s~\n", dest);
			printf("_________________________________\n");
			free(dest);
		}
		printf("retour gnl: %d\n", ret[0]);
		printf("LINE: ~%s~\n", dest);
		free(dest);
	}
	if (c == '1' || c == '3')
	{
		i = 1;
		while (i < ac)
		{
			printf("~ File name : %s ~\n\n", av[i]);
			fd[0] = open(av[i], O_RDONLY);
			while ((ret[0] = get_next_line(fd[0], &dest)))
			{
				printf("retour gnl: %d~\n", ret[0]);
				printf("LINE: ~%s~\n", dest);
				printf("_________________________________\n");
				free(dest);
			}
			printf("retour gnl: %d~\n", ret[0]);
			printf("LINE: ~%s~\n", dest);
			printf("_________________________________\n");
			free(dest);
			close(fd[0]);
			i++;
			printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
		}
	}
	if (c == '2' || c == '3')
	{
		char gnl[12];
		int k = 0;
		i = 0;
		fd[0] = open(av[1], O_RDONLY);	
		fd[1] = open(av[2], O_RDONLY);	
		fd[2] = open(av[3], O_RDONLY);
		ret[0] = 1;
		ret[1] = 1;
		ret[2] = 1;
		int comp[3] = {1, 1, 1};
		int exit = 3;
		while (exit)
		{
			if ((comp[i] = ret[i]) && (ret[i] = get_next_line(fd[i], &dst[i])))
			{
				printf("ret %d : ", ret[i]);
				printf("~%s~\n", dst[i]);
				gnl[k] = dst[i][0];
				k++;
				free(dst[i]);
			}
			if (comp[i] && !ret[i])
			{
				printf("~ File %d reached EOF ~\n", i);
				exit--;
			}
			i++;
			i = (i == 3) ? 0 : i;
		}
		i = 0;
		int count = 3;
		while (count--)
		{
			printf("ret %d : ", ret[i]);
			printf("~%s~\n", dst[i]);
			gnl[k] = dst[i][0];
			k++;
			free(dst[i]);
			i++;
		}
		gnl[k] = '\0';
		printf("\nInitiales de chaque ligne concatenees : \n%s", gnl);
		if (!strcmp(gnl, "GETNEXTLINE"))
			printf("->>>>>>>>>>>> SUCCESS !!\n");
		else
			printf("->>>>>>>>>>>> FAIL\n");
	}
}
