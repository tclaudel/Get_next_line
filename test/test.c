/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fgalaup <fgalaup@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:14:57 by fgalaup      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 12:49:03 by fgalaup     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "get_next_line.h"

void	get_next_line_file(char *filePath)
{
	int			fd = 0;
	char		*line = NULL;
	int			returned_value;
	size_t		line_number = 1;

	fd = open(filePath, O_RDONLY);
	printf("File Descriptor  = %d\n", fd);
	if (fd == -1)
		puts(strerror(errno));
	do
	{
		returned_value = get_next_line(fd, &line);
		printf("[%lu]-(%d):'%s'\n", line_number,  returned_value, line);
		free(line);
		line_number++;
		if (line_number > 1024)
			break ;
	} while (returned_value >= 1);
	close(fd);
}

void	get_next_line_stdin()
{
	int			fd = 0;
	char		*line = NULL;
	int			returned_value;
	size_t		line_number = 1;

	do
	{
		returned_value = get_next_line(1, &line);
		if (line[0] != '\0')
			printf("[%lu]-%d-'%s'\n", line_number,  returned_value, line);
		else
			printf(".");
		free(line);
		line_number++;
	} while (returned_value >= 1);
	close(fd);
}

int		main(int argc, char const *argv[])
{
	if (argc != 1)
	{
		if (strcmp(argv[1], "stdin"))
			get_next_line_stdin();
	}
	else
	{
		puts("/////////////////////Test[1] Reading a fat file/////////////////////");
		get_next_line_file("file/fat.file");
		puts("/////////////////////Test[2] Reading a small file/////////////////////");
		get_next_line_file("file/small.file");
		puts("/////////////////////Test[3] Reading a empty file/////////////////////");
		get_next_line_file("file/empty.file");
		puts("/////////////////////Test[4] Reading a just endl file/////////////////////");
		get_next_line_file("file/endl.file");
		puts("/////////////////////Test[5] Reading a non readable file/////////////////////");
		get_next_line_file("file/notReadable.file");
	}
	return (0);
}
