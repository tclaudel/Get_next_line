/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 17:52:44 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 14:13:34 by tclaudel    ###    #+. /#+    ###.fr     */
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
    int     ret;
	char	*line;
    int     count = 0;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		dprintf(1, "%d line :\t\t%s\n", ret, line);
        free(line);
        count++;
	}
	dprintf(1, "%d line :\t\t%s\n", ret, line);
	free(line);
    printf("\nline readed : %d\n\n", count);
	close(fd);
}