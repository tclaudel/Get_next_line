/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_bonus.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fgalaup <fgalaup@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:14:57 by fgalaup      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 13:11:55 by fgalaup     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "get_next_line_bonus.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	get_next_line_file(int fd, size_t number_of_line_to_read)
{
	char		*line = NULL;
	int			returned_value;
	size_t		line_number = 1;

	printf("File Descriptor  = %d\n", fd);
	if (fd == -1)
		puts(strerror(errno));
	do
	{
		returned_value = get_next_line(fd, &line);
		printf("[%lu]-(%d):'%s'\n", line_number,  returned_value, line);
		free(line);
		line_number++;
		if (line_number > number_of_line_to_read)
			break ;
	} while (returned_value >= 1);
}

int		main(void)
{
	int		fd_fat_file = open("file/fat.file", O_RDONLY);
	int		fd_small_file = open("file/small.file", O_RDONLY);
	int		fd_empty_file = open("file/empty.file", O_RDONLY);
	int		fd_endl_file = open("file/endl.file", O_RDONLY);
	int		fd_not_readable_file = open("file/notReadable.file", O_RDONLY);



	printf(GRN"Test[1] Reading a fat file\n" RESET);
	get_next_line_file(fd_fat_file, 5);

	printf(GRN"Test[2] Reading a small file\n" RESET);
	get_next_line_file(fd_small_file, 2);

	printf(GRN"Test[3] Reading a empty file\n" RESET);
	get_next_line_file(fd_empty_file, 1);

	printf(GRN"Test[2] Reading a small file\n" RESET);
	get_next_line_file(fd_small_file, 2);

	printf(GRN"Test[1] Reading a fat file\n" RESET);
	get_next_line_file(fd_fat_file, 5);

	printf(GRN"Test[4] Reading a just endl file\n" RESET);
	get_next_line_file(fd_endl_file, 64);

	printf(GRN"Test[5] Reading a non readable file\n" RESET);
	get_next_line_file(fd_not_readable_file, 10);

	printf(GRN"Test[2] Reading a small file\n" RESET);
	get_next_line_file(fd_small_file, 2);

	printf(GRN"Test[1] Reading a fat file\n" RESET);
	get_next_line_file(fd_fat_file, 5);
	return (0);
}
