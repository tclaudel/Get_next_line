/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:16:41 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 16:52:56 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdlib.h"
#include "unistd.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "get_next_line.h"

int			main(int ac, char **av)
{
	int		fd;
	int		fd2;
    int     ret;
	char	*line;
    int     count = 0;

	line = NULL;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ret = get_next_line(fd, &line);
	puts(line);
    free(line);
	ret = get_next_line(fd2, &line);
	puts(line);
    free(line);
	ret = get_next_line(fd2, &line);
	puts(line);
    free(line);
	ret = get_next_line(fd, &line);
	puts(line);
    free(line);
	count++;
	// while ((ret = get_next_line(fd, NULL)) > 0)
	// {
	// 	puts(line);
    //     free(line);
    //     count++;
	// 	// printf("VALEUR DE RETOUR : %d\n", ret);
	// }
	// puts(line);
	// free(line);
    // printf("VALEUR DE RETOUR : %d\n", ret);
    // printf("LIGNE LUE(S) : %d\n", count);
	// // fd2 = open(av[2], O_RDONLY);
	// // while ((ret = get_next_line(fd2, &line)) > 0)
	// // {
	// // 	puts(line);
    // //     free(line);
    // //     count++;
	// // 	//printf("VALEUR DE RETOUR : %d\n", ret);
	// // }
	// // puts(line);
	// // free(line);
    // // printf("VALEUR DE RETOUR : %d\n", ret);
    // // printf("LIGNE LUE(S) : %d\n", count);
	close(fd);
	close(fd2);
	fclose(stdout);
}